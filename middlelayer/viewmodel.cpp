#include "viewmodel.h"

void ViewModel::BindModel(shared_ptr<Middleware> modelsink) {
    QString name = modelsink->Name();
    models[name] = modelsink->GetChild();
    unsync[name] = true;
    connect(
        modelsink.get(), 
        SIGNAL(SIG_TRI(const QString&, const QString&, const QString&)),
        this, 
        SLOT(UpStreamReciever(const QString&, const QString&, const QString&)));
    
    connect(this, 
        SIGNAL(SIG_CMD(const QString&, const QString&, const QString&)),
        modelsink.get(),
        SLOT(DownStreamReciever(const QString&, const QString&, const QString&)));
}

void ViewModel::UpStreamReciever(
    const QString& _data, const QString& msg, const QString& target) {
    if(_data == "channel" && msg == "update") {
        counter++;
        global_counter++;
        if(counter < meta->size())
            emit SIG_CMD("channel", "update", meta->value(counter));
        else
            emit SIG_PROPS_CHANGED("channel", "update", "ok"); 
        return;
    }
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
    if(_data == "channel" && msg == "update") {
        meta = models["channel"]->GetMeta();
        counter = 0;
        if(meta->size() > 0)
            emit SIG_CMD("channel", "update", meta->value(counter));
        return; 
    }
    emit SIG_CMD(_data, msg, target);
}

shared_ptr<QVector<PropertyInstance>> ViewModel::Get(
    const QString& _data, const QVector<QString>& targets) {
    unsync[_data] = false;
    if(models.find(_data) != models.end())
        return models[_data]->Get(targets);
    return nullptr;
}
shared_ptr<QVector<QString>>  ViewModel::GetMeta(const QString& _data) {
    if(models.find(_data) != models.end())
        return models[_data]->GetMeta();
    return nullptr;
}
