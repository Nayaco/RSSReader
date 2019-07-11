#include "modelsink.h"

void ModelSink::BindModel(shared_ptr<Model> _model) {
    connect(_model.get(), SIGNAL(SIG_CHANNEL_CHANGE(const QString&)), 
        this, SLOT(void ModelUpStreamReciever(const QString&)));
    connect(_model.get(), SIGNAL(SIG_CHANNEL_FAILED(const QString&)),
        this, SLOT(void ModelUpStreamErrorReciever(const QString&)));

    connect(this, SIGNAL(SIG_CHANNEL_ADD(const QString&)), 
        _model.get(), SIGNAL(AddChannel(const QString&)));
    connect(this, SIGNAL(SIG_CHANNEL_UPDATE(const QString&)), 
        _model.get(), SIGNAL(UpdateChannel(const QString&)));
    connect(this, SIGNAL(SIG_CHANNEL_DELETE(const QString&)), 
        _model.get(), SIGNAL(DeleteChannel(const QString&)));

    model = _model;
}

void ModelSink::ModelUpStreamReciever(const QString& msg) {
    if(msg == "cadd") {
        emit SIG_PROPS_CHANGED("channel" , "add", "ok");
    }
    else if(msg == "cupdate") {
        emit SIG_PROPS_CHANGED("channel" , "update", "ok");
    }
    else if(msg == "cdelete") {
        emit SIG_PROPS_CHANGED("channel" , "delete", "ok");
    }
}

void ModelSink::ModelDownStreamReciever(
    const QString& _data, const QString& msg, const QString& target) {
    if(_data == "channel") {
        if(msg == "add") {
            emit SIG_CHANNEL_ADD(target);
        }
        else if(msg == "update") {
            emit SIG_CHANNEL_UPDATE(target);
        }
        else if(msg == "delete") {
            emit SIG_CHANNEL_DELETE(target);
        }
    }
}