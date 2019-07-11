#pragma once

#include "common/common.h"
#include "model/model.h"
class QTT: public QObject {
Q_OBJECT
public:
    QTT() {
        model = std::make_shared<Model>();
        connect(model.get(), SIGNAL(SIG_CHANNEL_CHANGE(const QString&)),this, SLOT(finished(const QString&)));
    }
    shared_ptr<Model> model;
    void start() {
        model->AddChannel("https://rsshub.app/bilibili/ranking/0/3?limit=10");
    }
public 
slots:
void finished(const QString&);
};