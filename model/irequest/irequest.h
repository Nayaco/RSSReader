#ifndef IREQUEST_H
#define IREQUEST_H
#include "common/common.h"
#include "request/request.h"
#include "parser/channel.h"
#include "parser/item.h"
class IRequest : public Request {
public:
    IRequest();
    ~IRequest();

    void GetImg(QString url, function<void(bool, QPixmap, QString)> cb);
    
protected:
    virtual void OnFinished(QNetworkReply *reply, const QByteArray data, const int statusCode) override;
    
private:
    function<void(bool, QPixmap, QString)> fcb;
    QString _url;
};


#endif