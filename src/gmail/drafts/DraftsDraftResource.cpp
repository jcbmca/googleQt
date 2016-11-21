/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "drafts"
 www.prokarpaty.net
***********************************************************/

#include "gmail/drafts/DraftsDraftResource.h"
using namespace googleQt;

namespace googleQt{

namespace drafts{
///DraftResource

DraftResource::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void DraftResource::toJson(QJsonObject& js)const{

    if(!m_id.isEmpty())
        js["id"] = QString(m_id);
    js["message"] = (QJsonObject)m_message;
}

void DraftResource::fromJson(const QJsonObject& js){

    m_id = js["id"].toString();
    m_message.fromJson(js["message"].toObject());
}

QString DraftResource::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<DraftResource>  DraftResource::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<DraftResource>  DraftResource::factory::create(const QJsonObject& js)
{
    std::unique_ptr<DraftResource> rv;
    rv = std::unique_ptr<DraftResource>(new DraftResource);
    rv->fromJson(js);
    return rv;
}

#ifdef API_QT_AUTOTEST
std::unique_ptr<DraftResource> DraftResource::EXAMPLE(){
    std::unique_ptr<DraftResource> rv(new DraftResource);
    rv->m_id = "test1value";
    rv->m_message = *(messages::MessageResource::EXAMPLE().get());
    return rv;
}
#endif //API_QT_AUTOTEST

}//drafts
}//googleQt
