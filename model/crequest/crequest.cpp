#include "crequest.h"

CRequest::CRequest() { }
CRequest::~CRequest() { }

void CRequest::GetChannel(QString url,function<void(bool, QString, Channel*)> cb, Channel* _chan) {
    fcb = cb;
    chan = _chan;
    get(url);
}
void CRequest::OnFinished(QNetworkReply *reply, const QByteArray data, const int statusCode) {
    if(statusCode == 200) {
        QString xmlData(data);
        fcb(true, xmlData, chan);
        return;
    }
    QString xmlData("");
    fcb(false, xmlData, chan);
    return;
}