#include "viewmodel.h"


void ViewModel::BindModel(shared_ptr<Middleware> modelsink) {
    QString name = modelsink->Name();
    models[name] = modelsink->GetChild();
    connect(
        modelsink.get(), 
        SIGNAL(SIG_PROPS_CHANGED(const QString&, const QString&, const QString&)),
        this, 
        SLOT(UpStreamReiever(const QString&, const QString&, const QString&)));
    
    connect(this, 
        SIGNAL(SIG_CMD(const QString&, const QString&, const QString&)),
        modelsink.get(),
        SLOT(DownStreamReciever(const QString&, const QString&, const QString&)));
}

void ViewModel::UpStreamReciever(
    const QString& _data, const QString& msg, const QString& target) {
    if(target == "ok") {
        unsync[_data] = true;
        emit SIG_PROPS_CHANGED(_data, msg, target);
    }
    else if(target == "failed") {
        unsync[_data] = false;
        emit SIG_CMD_FAIL(_data, msg, target);
    }
}
void ViewModel::DownStreamReciever(
    const QString& _data, const QString& msg, const QString& target) {
    emit SIG_CMD(_data, msg, target);
}
