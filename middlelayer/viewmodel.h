#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "common/common.h"
#include "common/middleware.h"
#include "common/property.h"

class ViewModel : public Middleware {
    Q_OBJECT
public:
    ViewModel() = default;
    ~ViewModel() = default;
    virtual QString Name() { return "viewmodel"; }
    void BindModel(shared_ptr<Middleware>);
    virtual shared_ptr<QVector<PropertyInstance>> Get(const QString&, const QVector<QString>&) override;
    virtual shared_ptr<QVector<QString>>  GetMeta(const QString&) override;
public
slots:
virtual void UpStreamReciever(
    const QString& _data, const QString& msg, const QString& target) override;
virtual void DownStreamReciever(
    const QString& _data, const QString& msg, const QString& target) override;

signals:
void SIG_PROPS_CHANGED(
    const QString& _data, const QString& msg, const QString& target);
void SIG_CMD_FAIL(
    const QString& _data, const QString& msg, const QString& target);

void SIG_CMD(
    const QString& _data, const QString& msg, const QString& target);

private:
    QMap<QString, shared_ptr<Middleware>> models;
    // dirty table (For Virtual DOM)
    QMap<QString, bool> unsync;

    // for update bussiness logical
    shared_ptr<QVector<QString>> meta;
    int counter;
    int global_counter;
};

#endif