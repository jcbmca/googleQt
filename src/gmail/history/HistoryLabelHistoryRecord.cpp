/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "history"
 www.prokarpaty.net
***********************************************************/

#include "gmail/history/HistoryLabelHistoryRecord.h"
using namespace googleQt;

namespace googleQt{

namespace history{
///LabelHistoryRecord

LabelHistoryRecord::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void LabelHistoryRecord::toJson(QJsonObject& js)const{

    js["message"] = (QJsonObject)m_message;
    js["labelIds"] = ingrl_list2jsonarray(m_labelIds);
}

void LabelHistoryRecord::fromJson(const QJsonObject& js){

    m_message.fromJson(js["message"].toObject());
    jsonarray2ingrl_list(js["labelIds"].toArray(), m_labelIds);
}

QString LabelHistoryRecord::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<LabelHistoryRecord>  LabelHistoryRecord::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<LabelHistoryRecord>  LabelHistoryRecord::factory::create(const QJsonObject& js)
{
    std::unique_ptr<LabelHistoryRecord> rv;
    rv = std::unique_ptr<LabelHistoryRecord>(new LabelHistoryRecord);
    rv->fromJson(js);
    return rv;
}

#ifdef API_QT_AUTOTEST
std::unique_ptr<LabelHistoryRecord> LabelHistoryRecord::EXAMPLE(int context_index, int parent_context_index){
    Q_UNUSED(context_index);
    Q_UNUSED(parent_context_index);
    static int example_idx = 0;
    example_idx++;
    std::unique_ptr<LabelHistoryRecord> rv(new LabelHistoryRecord);
    rv->m_message = *(messages::MessageResource::EXAMPLE(0, context_index).get());
    std::list<QString> list_of_labelIds;
    for(int i = 0; i < 3; i++){
        rv->m_labelIds.push_back(QString("_%1_%2").arg(i).arg(example_idx));
    }
    return rv;
}
#endif //API_QT_AUTOTEST

}//history
}//googleQt
