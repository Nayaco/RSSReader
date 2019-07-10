#ifndef MODEL_H
#define MODEL_H

#include <QVector>
#include "common/common.h"
#include "common/etl.h"
#include "parser/channel.h"
#include "parser/item.h"
#include "parser/iobject.h"

#include "crequest/crequest.h"

class Model: public ProxyPropertyNotification<Model> {
public:
    Model();
    ~Model();
    shared_ptr<QVector<Channel>> GetChannels();
    void UpdateChannel();
    void AddChannel(QString url);
    void DeleteChannel(string name);
private:
    shared_ptr<QVector<Channel>> chan;
    map<string, int>             chanTable;
    shared_ptr<CRequest>         request;
};
#endif