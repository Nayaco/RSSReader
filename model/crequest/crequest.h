#ifndef CREQUEST_H
#define CREQUEST_H
#include "common/common.h"
#include "request/request.h"
#include "parser/channel.h"
#include "parser/item.h"
class CRequest : public Request {
public:
    CRequest();
    ~CRequest();
    void GetChannel(QString url, function<void(bool, QString)> cb);
protected:
    virtual void OnFinished(QNetworkReply *reply, const QByteArray data, const int statusCode) override;
private:
    function<void(bool, QString)> fcb;
};


#endif