#pragma once

#include <QObject>

template<class T>
class Middleware : public QObject {
    Q_OBJECT
public 
slots:
    virtual void UpStreamReciever(const QString&) = 0;
    virtual void DownStreamReciever(const QString&) = 0;
signals:
    void SIG_OMIT(const QString&);
};