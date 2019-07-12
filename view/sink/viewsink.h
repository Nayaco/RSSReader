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
public
slots:
virtual void UpStreamReciever(
    const QString& _data, const QString& msg, const QString& target)override { };
virtual void DownStreamReciever(
    const QString& _data, const QString& msg, const QString& target)override { };
};

#endif