#include "ctimer.h"

void CTimer::BindViewModel(const shared_ptr<ViewModel> _viewmodel) {
    viewmodel = _viewmodel;
    connect(
        this, 
        SIGNAL(SIG_TRI(const QString&, const QString&, const QString&)),
        viewmodel.get(),
        SLOT(DownStreamReciever(const QString&, const QString&, const QString&)));
    connect(
        viewmodel.get(),
        SIGNAL(SIG_TRI(const QString&, const QString&, const QString&)),
        this,
        SLOT(UpStreamReciever(const QString&, const QString&, const QString&)));
}

void CTimer::StartTik() {
    timer = std::make_shared<QTimer>(this);
    connect(timer.get(), SIGNAL(timeout()), this, SLOT(TimeOutReciever()));
    ontiking = true;
    timer->start(interval * 1000);
}

void CTimer::StopTik() {
    ontiking = false;
    timer->stop();
}

void CTimer::TimeOutReciever() {
    counter = 0;
    qDebug()<<counter;
    meta = viewmodel->GetMeta("channel");
    if(meta == nullptr) {
        qDebug()<<"shit";
        return;
    }
    for(auto i: *meta) {
        qDebug()<<i;
    }
    if(meta->size() > 0) 
        emit SIG_TRI("channel", "update", meta->value(counter));
}

void CTimer::UpStreamReciever(
    const QString& _data, const QString& msg, const QString& target) {
    if(_data == "channel" && msg == "update" && target == "ok" && counter < meta->size()) {
        ++counter;
        emit SIG_TRI("channel", "update", meta->value(counter));
    }
}