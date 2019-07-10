#ifndef MODEL_H
#define MODEL_H

#include "common/common.h"
#include "common/middleware.h"
#include "parser/channel.h"
#include "parser/item.h"
#include "parser/iobject.h"
#include "parser/RSSparser.h"

#include "crequest/crequest.h"

using Channels = shared_ptr<QVector<shared_ptr<Channel>>>;

class Model: public Middleware<Model>{
public:
    Model();
    ~Model();
    Channels GetChannels();
    void UpdateChannel(QString title);
    void AddChannel(QString url);
    void DeleteChannel(QString title);
public 
slots:
    virtual void UpStreamReciever(const QString&) override;
    virtual void DownStreamReciever(const QString&) override;
signals:
    void SIG_CHANNEL_CHANGE(const QString&);
private:
    Channels chans;
    QMap<QString, int>           chanTable;
    shared_ptr<CRequest>         crequest;
    shared_ptr<RSSParser>        parser;
};
#endif