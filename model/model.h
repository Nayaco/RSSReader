#ifndef MODEL_H
#define MODEL_H

#include "common/common.h"
#include "common/etl.h"
#include <QVector>
#include "parser/channel.h"
#include "parser/item.h"
#include "parser/iobject.h"

class Model: public ProxyPropertyNotification<Model> {
public:
    Model();
    ~Model();
    shared_ptr<QVector<Channel>> GetChannels();
    void update();
private:
    shared_ptr<QVector<Channel>> chan;
};
#endif