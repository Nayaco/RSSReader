#ifndef VIEWSINK_H
#define VIEWSINK_H

#include "common/common.h"
#include "common/middleware.h"
#include "common/property.h"
#include <QWidget>

class ViewSink : public Middleware {
    Q_OBJECT
public:
    ViewSink() = default;
    ~ViewSink() = default;

    virtual QString Name() { return "view"; }

    virtual void BindWidget(const QWidget& ) {}

    virtual void BindViewModel (const shared_ptr<Middleware> _viewmodel) {
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
public
slots:
virtual void UpStreamReciever(
    const QString& _data, const QString& msg, const QString& target)override { };
    
virtual void DownStreamReciever(
    const QString& _data, const QString& msg, const QString& target)override { };
protected:
    shared_ptr<Middleware> viewmodel;
};

#endif