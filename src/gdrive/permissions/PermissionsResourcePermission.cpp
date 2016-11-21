/**********************************************************
 DO NOT EDIT
 This file was generated from stone specification "permissions"
 www.prokarpaty.net
***********************************************************/

#include "gdrive/permissions/PermissionsResourcePermission.h"
using namespace googleQt;

namespace googleQt{

namespace permissions{
///ResourcePermission

ResourcePermission::operator QJsonObject()const{
    QJsonObject js;
    this->toJson(js);
    return js;
}


void ResourcePermission::toJson(QJsonObject& js)const{

    if(!m_id.isEmpty())
        js["id"] = QString(m_id);
    if(!m_kind.isEmpty())
        js["kind"] = QString(m_kind);
    if(!m_type.isEmpty())
        js["type"] = QString(m_type);
    if(!m_emailAddress.isEmpty())
        js["emailAddress"] = QString(m_emailAddress);
    if(!m_domain.isEmpty())
        js["domain"] = QString(m_domain);
    if(!m_role.isEmpty())
        js["role"] = QString(m_role);
    js["allowFileDiscovery"] = m_allowFileDiscovery;
    if(!m_displayName.isEmpty())
        js["displayName"] = QString(m_displayName);
    if(!m_photoLink.isEmpty())
        js["photoLink"] = QString(m_photoLink);
    if(m_expirationTime.isValid())
        js["expirationTime"] = m_expirationTime.toString(Qt::ISODate);
}

void ResourcePermission::fromJson(const QJsonObject& js){

    m_id = js["id"].toString();
    m_kind = js["kind"].toString();
    m_type = js["type"].toString();
    m_emailAddress = js["emailAddress"].toString();
    m_domain = js["domain"].toString();
    m_role = js["role"].toString();
    m_allowFileDiscovery = js["allowFileDiscovery"].toVariant().toBool();
    m_displayName = js["displayName"].toString();
    m_photoLink = js["photoLink"].toString();
    m_expirationTime = QDateTime::fromString(js["expirationTime"].toString(), Qt::ISODate);
}

QString ResourcePermission::toString(bool multiline)const
{
    QJsonObject js;
    toJson(js);
    QJsonDocument doc(js);
    QString s(doc.toJson(multiline ? QJsonDocument::Indented : QJsonDocument::Compact));
    return s;
}


std::unique_ptr<ResourcePermission>  ResourcePermission::factory::create(const QByteArray& data)
{
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject js = doc.object();
    return create(js);
}


std::unique_ptr<ResourcePermission>  ResourcePermission::factory::create(const QJsonObject& js)
{
    std::unique_ptr<ResourcePermission> rv;
    rv = std::unique_ptr<ResourcePermission>(new ResourcePermission);
    rv->fromJson(js);
    return rv;
}

#ifdef API_QT_AUTOTEST
std::unique_ptr<ResourcePermission> ResourcePermission::EXAMPLE(){
    std::unique_ptr<ResourcePermission> rv(new ResourcePermission);
    rv->m_id = "test1value";
    rv->m_kind = "test2value";
    rv->m_type = "test3value";
    rv->m_emailAddress = "test4value";
    rv->m_domain = "test5value";
    rv->m_role = "test6value";
    rv->m_displayName = "test8value";
    rv->m_photoLink = "test9value";
    rv->m_expirationTime = QDateTime::currentDateTime();
    return rv;
}
#endif //API_QT_AUTOTEST

}//permissions
}//googleQt
