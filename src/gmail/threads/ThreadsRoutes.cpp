/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "threads"
 www.prokarpaty.net
***********************************************************/

#include "gmail/threads/ThreadsRoutes.h"
#include "Endpoint.h"
#include "gmail/GmailRoutes.h"
using namespace googleQt;
using namespace threads;

std::unique_ptr<ThreadResource> ThreadsRoutes::get(const gmail::IdArg& arg){
    GOOGLE_BLOCKING_CALL(get_Async, ThreadResource, arg);
}

void ThreadsRoutes::get_Async(
    const gmail::IdArg& arg,
    std::function<void(std::unique_ptr<ThreadResource>)> completed_callback ,
    std::function<void(std::unique_ptr<GoogleException>)> failed_callback)
{
    m_end_point->getStyle
        <
        std::unique_ptr<ThreadResource>,
        ThreadResource::factory
        >
        (m_end_point->buildGmailUrl("threads", arg),
        completed_callback,
        failed_callback);
}

std::unique_ptr<ThreadListRes> ThreadsRoutes::list(const gmail::ListArg& arg){
    GOOGLE_BLOCKING_CALL(list_Async, ThreadListRes, arg);
}

void ThreadsRoutes::list_Async(
    const gmail::ListArg& arg,
    std::function<void(std::unique_ptr<ThreadListRes>)> completed_callback ,
    std::function<void(std::unique_ptr<GoogleException>)> failed_callback)
{
    m_end_point->getStyle
        <
        std::unique_ptr<ThreadListRes>,
        ThreadListRes::factory
        >
        (m_end_point->buildGmailUrl("threads", arg),
        completed_callback,
        failed_callback);
}

