#ifndef MODEL_H
#define MODEL_H

#include "common/common.h"
#include "common/middleware.h"
#include "parser/channel.h"
#include "parser/item.h"
#include "parser/iobject.h"
#include "parser/RSSparser.h"

#include "crequest/crequest.h"

using Channels = QVector<shared_ptr<Channel>>;

class Model: public Middleware<Model>{
public:
    Model();
    ~Model();
    shared_ptr<Channels> GetChannels();

public 
slots:
    void UpdateChannel(const QString& title);
    void AddChannel(const QString& url);
    void DeleteChannel(const QString& title);
    virtual void UpStreamReciever(const QString&) override;
    virtual void DownStreamReciever(const QString&) override;
signals:
    void SIG_CHANNEL_CHANGE(const QString&);
    void SIG_CHANNEL_FAILED(const QString&);
private:
    shared_ptr<Channels>         chans;
    QMap<QString, int>           chanTable;
    shared_ptr<CRequest>         crequest;
    shared_ptr<RSSParser>        parser;
};
#endif