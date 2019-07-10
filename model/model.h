#ifndef MODEL_H
#define MODEL_H

#include <QVector>
#include "common/common.h"
#include "common/etl.h"
#include "parser/channel.h"
#include "parser/item.h"
#include "parser/iobject.h"
#include "parser/RSSparser.h"

#include "crequest/crequest.h"

using Channels = shared_ptr<QVector<shared_ptr<Channel>>>;

class Model: public ProxyPropertyNotification<Model> {
public:
    Model();
    ~Model();
    Channels GetChannels();
    void UpdateChannel(QString title);
    void AddChannel(QString url);
    void DeleteChannel(QString title);
private:
    Channels chans;
    QMap<QString, int>           chanTable;
    shared_ptr<CRequest>         crequest;
    shared_ptr<RSSParser>        parser;
};
#endif