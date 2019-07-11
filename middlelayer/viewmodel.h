#ifndef VIEWMODEL_H
#define VIEWMODEL_H

#include "common/common.h"
#include "common/middleware.h"
#include "model/model.h"
#include "model/sink/modelsink.h"

class ViewModel : public Middleware<ViewModel> {
public:
    ViewModel() = default;
    ~ViewModel() = default;
    void BindModel(shared_ptr<ModelSink>);
    // void BindView(shared_ptr<View>, shared_ptr<ViewSink>);
public
slots:
virtual void ModelUpStreamFailureHandler(
    const QString& _data, const QString& msg, const QString& target);
virtual void ModelUpStreamReiever(
    const QString& _data, const QString& msg, const QString& target);

virtual void ModelDownStreamReciever(
    const QString& _data, const QString& msg, const QString& target);
signals:

void SIG_PROPS_CHANGED(
    const QString& _data, const QString& msg, const QString& target);

void SIG_CMD_FAIL(
    const QString& _data, const QString& msg, const QString& target);

void SIG_CMD(
    const QString& _data, const QString& msg, const QString& target);

private:
    shared_ptr<Model> model;
};

#endif