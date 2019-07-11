#include "viewmodel.h"


void ViewModel::BindModel(shared_ptr<ModelSink> modelsink) {
    model = modelsink->GetModel();
    connect(modelsink.get(), SIGNAL(SIG_PROPS_CHANGED(const QString&, const QString&, const QString&)),
        this, SLOT(ModelUpStreamReiever(const QString&, const QString&, const QString&)));
    connect(this, SIGNAL(SIG_CMD(const QString&, const QString&, const QString&)),
        modelsink.get(), SLOT(ModelDownStreamReciever(const QString&, const QString&, const QString&)));
}

void ViewModel::ModelUpStreamReiever(
    const QString& _data, const QString& msg, const QString& target) {
    if(target == "ok") {
        emit SIG_PROPS_CHANGED(_data, msg, target);
    } 
    else if(target == "failed") {
        emit SIG_CMD_FAIL(_data, msg, target);
    }
}
void ViewModel::ModelDownStreamReciever(
    const QString& _data, const QString& msg, const QString& target) {
    emit SIG_CMD(_data, msg, target);
}

shared_ptr<Channels> ViewModel::GetChannel() {
    return model->GetChannels();
}