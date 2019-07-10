#include "request.h"

Request::Request() {
    qDebug() << "BaseAPI";
    QObject::connect(&networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(serviceRequestFinished(QNetworkReply*)));
}

Request::~Request() {
    networkAccessManager.disconnect();
}

void Request::get(const QString url)
{
    httpRequest.setUrl(QUrl(url));
    networkAccessManager.get(httpRequest);
}

void Request::post(const QString url, const QByteArray &data)
{
    httpRequest.setUrl(QUrl(url));
    networkAccessManager.post(httpRequest, data);
}

void Request::RequestFinished(QNetworkReply *reply)
{
    int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    qDebug() << "Request...Finished...StatusCode:" << statusCode;

    if(reply->error() == QNetworkReply::NoError) {
        OnFinished(reply, reply->readAll(), statusCode);
    } else {
        OnFinished(reply, "", statusCode);
    }
    reply->deleteLater();
}