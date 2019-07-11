#pragma once

#include <QObject>

template<class T>
class Middleware : public QObject {
    Q_OBJECT
public 
slots:
// from lower layer to higher layer
    virtual void UpStreamReciever(const QString&) { } 
// from higher layer to lower layer
    virtual void DownStreamReciever(const QString&) { }
signals:
    void SIG_OMIT(const QString&);
    void SIG_TEMPLATE(const QString&, const QString&, const QString&);
};