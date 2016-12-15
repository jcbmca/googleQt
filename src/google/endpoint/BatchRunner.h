#pragma once

#include <list>
#include <memory>
#include <QObject>
#include "GoogleTask.h"

namespace googleQt{

    template <class ARG_PARAM, class RESULT>
    using TASK_MAP = std::map<ARG_PARAM, std::unique_ptr<GoogleTask<RESULT>>>;
    template <class RESULT>
    using RESULT_LIST = std::list<RESULT>;

    template <class ARG_PARAM>
    using REQUEST_LIST = std::list<ARG_PARAM>;

    template <class ARG_PARAM, class RESULT>
    class BatchResult
    {
    public:
        void registerRequest(const ARG_PARAM& ap)
        {
            m_requests.push_back(ap);
        };
        void registerResult(const ARG_PARAM& ap, GoogleTask<RESULT>* t) 
        {
            m_results[ap] = std::unique_ptr<GoogleTask<RESULT>>(t);
        };

        RESULT_LIST<RESULT*> results()
        {
            RESULT_LIST<RESULT*> rv;
            for (auto& i : m_results) 
            {
                GoogleTask<RESULT>* t = i.second.get();
                if (t->isCompleted()) 
                {
                    rv.push_back(t->get());
                }
            }
            return rv;
        }

    protected:
        TASK_MAP<ARG_PARAM, RESULT> m_results;
        REQUEST_LIST<ARG_PARAM> m_requests;
    };

    class BatchBaseRunner : public QObject
    {
        Q_OBJECT;
    public:
        BatchBaseRunner(ApiEndpoint& ept):m_endpoint(ept)
        {
            m_available_concurrent_routes_count = m_max_concurrent_routes_count;
        }

        bool isFinished()const { return m_finished; }

    signals:
        void finished();

    protected:
        void notifyOnFinished();
        void waitUntillFinishedOrCancelled();

    protected:
        int  m_max_concurrent_routes_count          {2};
        int  m_available_concurrent_routes_count    {0};
        bool m_finished                             { false };
        bool m_in_wait_loop                         { false };
        ApiEndpoint& m_endpoint;
    };


    template <class ARG_PARAM, class ROUTER, class RESULT>
    class BatchRunner: public BatchBaseRunner
    {
    public:
        BatchRunner(const std::list<ARG_PARAM>& arg_params, ROUTER* r, ApiEndpoint& ept)
            :BatchBaseRunner(ept)
        {
            m_arg_parameters = arg_params;
            m_router = r;
        }

        void run()
        {
            if (!m_result)
            {
                m_result.reset(new BatchResult<ARG_PARAM, RESULT>);
            }

            while(m_arg_parameters.size() > 0 && 
                m_available_concurrent_routes_count > 0)
                {
                runSingleRequest();
                }
        }

        BatchResult<ARG_PARAM, RESULT>* get() { return m_result.get(); }
        std::unique_ptr<BatchResult<ARG_PARAM, RESULT> > waitForResultAndRelease()
        {
            std::unique_ptr<BatchResult<ARG_PARAM, RESULT> > res;

            if (!isFinished()) 
            {
                m_in_wait_loop = true;
                waitUntillFinishedOrCancelled();
            }

            res = std::move(m_result);

            deleteLater();
            return res;
        }

    protected:
        void runSingleRequest() 
        {
            if (m_arg_parameters.empty())
            {
                m_finished = true;
                notifyOnFinished();
                return;
            }
            ARG_PARAM ap = m_arg_parameters.front();
            m_arg_parameters.pop_front();
            m_result->registerRequest(ap);
            GoogleTask<RESULT>* t = m_router->route(ap);
            m_available_concurrent_routes_count--;
            connect(t, &GoogleTask<RESULT>::finished, this, [=]()
            {
                m_result->registerResult(ap, t);
                m_available_concurrent_routes_count++;
                runSingleRequest();
            });
        }

    protected:
        std::list<ARG_PARAM>            m_arg_parameters;
        ROUTER*                         m_router        {nullptr};
        std::unique_ptr<BatchResult<ARG_PARAM,RESULT> > m_result;
    };

};