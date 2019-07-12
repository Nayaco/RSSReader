#include "ctimer.h"

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
    emit SIG_TRI("channel", "update", "all");
}

void CTimer::UpStreamReciever(
    const QString& _data, const QString& msg, const QString& target) {
}