#include "irequest.h"

IRequest::IRequest() { }
IRequest::~IRequest() { }

void IRequest::GetImg(QString url,function<void(bool, QPixmap, QString)> cb) {
    fcb = cb;
    _url = url;
    get(url);
}
void IRequest::OnFinished(QNetworkReply *reply, const QByteArray data, const int statusCode) {
    if(statusCode == 200) {
        QPixmap img;
        img.loadFromData(data);
        fcb(true, img, _url);
        return;
    }
    QPixmap img;
    fcb(false, img, _url);
    return;
}