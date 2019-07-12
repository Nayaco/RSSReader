#include "crequest.h"

CRequest::CRequest() { }
CRequest::~CRequest() { }

void CRequest::GetChannel(QString url,function<void(bool, QString, QString)> cb) {
    fcb = cb;
    _url = url;
    get(url);
}
void CRequest::OnFinished(QNetworkReply *reply, const QByteArray data, const int statusCode) {
    if(statusCode == 200) {
        QString xmlData(data);
        fcb(true, xmlData, _url);
        return;
    }
    QString xmlData("");
    fcb(false, xmlData, _url);
    return;
}