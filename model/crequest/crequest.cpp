#include "crequest.h"

CRequest::CRequest() { }
CRequest::~CRequest() { }

void CRequest::GetChannel(QString url,function<void(bool, QString)> cb) {
    fcb = cb;
    get(url);
}
void CRequest::OnFinished(QNetworkReply *reply, const QByteArray data, const int statusCode) {
    if(statusCode == 200) {
        QString xmlData(data);
        fcb(true, xmlData);
        return;
    }
    QString xmlData("");
    fcb(false, xmlData);
    return;
}