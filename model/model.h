#ifndef MODEL_H
#define MODEL_H

#include "common/common.h"
#include "common/middleware.h"
#include "common/property.h"

#include "parser/channel.h"
#include "parser/item.h"
#include "parser/RSSparser.h"
#include "crequest/crequest.h"
#include "irequest/irequest.h"

#include <QFile> 
#include <QTextStream>
#include <QStringList>
#include <QRegExp>
#include <QCoreApplication>
#include <QDir>
using ChannelInstance = shared_ptr<Channel>;

class Model: public Middleware{
    Q_OBJECT
public:
    Model();
    ~Model();
    virtual QString Name() override { return "CHANNEL"; }
    virtual shared_ptr<QVector<PropertyInstance>> Get(const QVector<QString>&) override;
    virtual shared_ptr<QVector<QString>>  GetMeta() override;
public
slots:
    virtual void Init() ;
    virtual void Exit() ;

    void AddChannel(const QString& url);
    void UpdateChannel(const QString& title);
    void DeleteChannel(const QString& title);
    virtual void UpStreamReciever(const QString&) override;
    virtual void DownStreamReciever(const QString&) override;
    
    void SetImg(const QString& title);
signals:
    void SIG_CHANNEL_CHANGE(const QString&);
    void SIG_CHANNEL_FAILED(const QString&);

    void SIG_IMG(const QString&);
private:
    ChannelInstance                     newChan;
    QMap<QString, ChannelInstance>      chans;
    shared_ptr<CRequest>                crequest;
    shared_ptr<IRequest>                irequest;
    shared_ptr<RSSParser>               parser;
};
#endif