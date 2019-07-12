#pragma once

#include "common/common.h"
#include "model/model.h"
#include "model/sink/modelsink.h"
class QTT: public QObject {
Q_OBJECT
public:
    int zero = 0;
    QTT() {
        model = std::make_shared<ModelSink>();
        model->BindModel();
        connect(
            model.get(), 
            SIGNAL(SIG_TRI(const QString&, const QString&, const QString&)), 
            this, 
            SLOT(finished(const QString&, const QString&, const QString&)));
        connect(
            this,
            SIGNAL(SIG_TEST(const QString&, const QString&, const QString&)), 
            model.get(),
            SLOT(DownStreamReciever(const QString&, const QString&, const QString&))
        );
    }
    shared_ptr<ModelSink> model;
    void start() {
        emit SIG_TEST("channel", "add", "https://rsshub.app/bilibili/ranking/0/3?limit=5");
        // model->AddChannel("https://rsshub.app/bilibili/ranking/0/3?limit=5");
        // model->AddChannel("https://rsshub.app/kirara/news");
    }
public 
slots:
void finished(const QString&, const QString&, const QString&);
signals:
void SIG_TEST(const QString&, const QString&, const QString&);
};