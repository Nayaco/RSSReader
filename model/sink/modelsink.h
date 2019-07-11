#ifndef MODELSINK_H
#define MODELSINK_H
#include "common/common.h"
#include "common/middleware.h"
#include "../model.h"

class ModelSink : public Middleware<ModelSink>{
public:
    ModelSink() = default;
    ~ModelSink() = default;
    void BindModel(shared_ptr<Model>);
    shared_ptr<Model> GetModel() { return model; }
public
slots:
    virtual void ModelUpStreamReciever(
        const QString& msg);
    virtual void ModelUpStreamErrorReciever(
        const QString& msg);
    // expose to viewmodel
    virtual void ModelDownStreamReciever(
        const QString& _data, const QString& msg, const QString& target);
signals:
    // expose to viewmodel 
    void SIG_PROPS_CHANGED(
        const QString& _data, const QString& msg, const QString& target);
    
    void SIG_CHANNEL_UPDATE(const QString&);
    void SIG_CHANNEL_ADD(const QString&);
    void SIG_CHANNEL_DELETE(const QString&);
private:
    shared_ptr<Model> model;
};

#endif