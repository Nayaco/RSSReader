#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "common/common.h"
#include "common/middleware.h"
#include "model/model.h"
#include "model/sink/modelsink.h"
#include "common/property.h"

class ViewModel : public Middleware {
    Q_OBJECT
public:
    ViewModel() = default;
    ~ViewModel() = default;
    void BindModel(shared_ptr<Middleware>);
    // void BindView(shared_ptr<View>, shared_ptr<ViewSink>);
    // shared_ptr<> Get();
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
    QMap<QString, bool> unsync;
};

#endif