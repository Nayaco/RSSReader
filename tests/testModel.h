#pragma once

#include "common/common.h"
#include "view/sink/viewsink.h"
#include "view/ctimer/ctimer.h"
#include "model/model.h"
#include "model/sink/modelsink.h"
#include "middlelayer/viewmodel.h"
class QTT: public QObject {
Q_OBJECT
public:
    int zero = 0;
    QTT() {
        model = std::make_shared<ModelSink>();
        vm = std::make_shared<ViewModel>();
        ctimer = std::make_shared<CTimer>(5);
        model->BindModel();
        vm->BindModel(std::static_pointer_cast<Middleware>(model));
        ctimer->BindViewModel(vm);
        connect(
            vm.get(), 
            SIGNAL(SIG_PROPS_CHANGED(const QString&, const QString&, const QString&)), 
            this, 
            SLOT(finished(const QString&, const QString&, const QString&)));
        connect(
            this,
            SIGNAL(SIG_TEST(const QString&, const QString&, const QString&)), 
            vm.get(),
            SLOT(DownStreamReciever(const QString&, const QString&, const QString&))
        );
    }
    shared_ptr<ModelSink> model;
    shared_ptr<ViewModel> vm;
    shared_ptr<CTimer> ctimer;
    void start() {
        // emit SIG_TEST("channel", "add", "https://rsshub.app/bilibili/ranking/0/3?limit=5");
        // model->AddChannel("https://rsshub.app/bilibili/ranking/0/3?limit=5");
        // model->AddChannel("https://rsshub.app/kirara/news");
        emit SIG_TEST("channel", "init", "");
    }
public 
slots:
void finished(const QString&, const QString&, const QString&);
signals:
void SIG_TEST(const QString&, const QString&, const QString&);
void SIG_QUIT();
};