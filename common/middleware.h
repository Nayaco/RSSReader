#pragma once

#include "common.h"
#include "property.h"

class Middleware : public QObject {
    Q_OBJECT
public:
    virtual QString Name() { return "NULL"; }
    
    virtual shared_ptr<Middleware> GetChild() { return nullptr; }

    virtual shared_ptr<QVector<PropertyInstance>> Get(const QVector<QString>&) { return nullptr; }
    virtual shared_ptr<QVector<QString>>  GetMeta() { return nullptr; }

    virtual shared_ptr<QVector<PropertyInstance>> Get(const QString&, const QVector<QString>&) { return nullptr; }
    virtual shared_ptr<QVector<QString>>  GetMeta(const QString&) { return nullptr; }
public 
slots:
// from lower layer to higher layer
    virtual void UpStreamReciever(
        const QString&) { } 
    virtual void UpStreamReciever(
        const QString&, const QString&) { } 
    virtual void UpStreamReciever(
        const QString&, const QString&, const QString&) { }
// from higher layer to lower layer
    virtual void DownStreamReciever(
        const QString&) { }
    virtual void DownStreamReciever(
        const QString&, const QString&) { }
    virtual void DownStreamReciever(
        const QString&, const QString&, const QString&) { }
signals:
    void SIG_OMIT(const QString&);
    void SIG_UNI(const QString&);
    void SIG_BI (const QString&, const QString&);
    void SIG_TRI(const QString&, const QString&, const QString&);
};