#ifndef CTIMER_H
#define CTIMER_H
#include "common/common.h"
#include "common/middleware.h"
#include "common/property.h"
#include "../sink/viewsink.h"
#include "middlelayer/viewmodel.h"
#include <QTimer>
class CTimer : public ViewSink {
    Q_OBJECT
public:
    CTimer(int _interval) : ontiking(false), interval(_interval) {};
    ~CTimer() = default;
    virtual void BindViewModel(const shared_ptr<ViewModel> _viewmodel);
    virtual void StartTik();
    virtual void StopTik();
public slots:

virtual void TimeOutReciever();
virtual void UpStreamReciever(
    const QString& _data, const QString& msg, const QString& target)override;

private:
    shared_ptr<ViewModel> viewmodel;
    shared_ptr<QTimer> timer;
    bool ontiking; 
    int interval;
    shared_ptr<QVector<QString>> meta;
    int counter;
};

#endif