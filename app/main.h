#pragma once

#include "common/common.h"
#include "common/middleware.h"
#include "common/property.h"

#include "view/sink/viewsink.h"
#include "view/ctimer/ctimer.h"
#include "view/mainwindow/mainwindowsink.h"

#include "middlelayer/viewmodel.h"

#include "model/model.h"
#include "model/sink/modelsink.h"

class RssReaderCore : public Middleware {
Q_OBJECT
public: 
    int zero = 0;
    RssReaderCore() {
        model = std::make_shared<ModelSink>();
        vm = std::make_shared<ViewModel>();
        ctimer = std::make_shared<CTimer>(1800);
        mainwindow = std::make_shared<MainWindowSink>();

        model->BindModel();
        vm->BindModel(std::static_pointer_cast<Middleware>(model));
        ctimer->BindViewModel(std::static_pointer_cast<Middleware>(vm));
        mainwindow->BindViewModel(std::static_pointer_cast<Middleware>(vm));
        
        connect(
            vm.get(), 
            SIGNAL(SIG_TRI(const QString&, const QString&, const QString&)), 
            this, 
            SLOT(UpStreamReciever(const QString&, const QString&, const QString&)));
        connect(
            this,
            SIGNAL(SIG_TRI(const QString&, const QString&, const QString&)), 
            vm.get(),
            SLOT(DownStreamReciever(const QString&, const QString&, const QString&))
        );
    }
    void init() {
        // emit SIG_TEST("channel", "add", "https://rsshub.app/bilibili/ranking/0/3?limit=5");
        // model->AddChannel("https://rsshub.app/bilibili/ranking/0/3?limit=5");
        // model->AddChannel("https://rsshub.app/kirara/news");
        emit SIG_TRI("channel", "init", "");
    }
    shared_ptr<ModelSink> model;
    shared_ptr<ViewModel> vm;
    shared_ptr<CTimer> ctimer;
    shared_ptr<MainWindowSink> mainwindow;
    public
    slots:
    virtual void UpStreamReciever(
        const QString&, const QString&, const QString&) override;
};
