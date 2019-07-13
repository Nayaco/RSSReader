#include "modelsink.h"

void ModelSink::BindModel() {
    model = std::make_shared<Model>();
    Model* ptr_model = model.get();
    connect(ptr_model, SIGNAL(SIG_CHANNEL_CHANGE(const QString&)), 
        this, SLOT(ModelUpStreamReciever(const QString&)));
    connect(ptr_model, SIGNAL(SIG_CHANNEL_FAILED(const QString&)),
        this, SLOT(ModelUpStreamErrorReciever(const QString&)));

    connect(this, SIGNAL(SIG_CHANNEL_ADD(const QString&)), 
        ptr_model, SLOT(AddChannel(const QString&)));
    connect(this, SIGNAL(SIG_CHANNEL_UPDATE(const QString&)), 
        ptr_model, SLOT(UpdateChannel(const QString&)));
    connect(this, SIGNAL(SIG_CHANNEL_DELETE(const QString&)), 
        ptr_model, SLOT(DeleteChannel(const QString&)));
    
    connect(this, SIGNAL(SIG_CHANNEL_INIT()), 
        ptr_model, SLOT(Init()));
    connect(this, SIGNAL(SIG_CHANNEL_EXIT()), 
        ptr_model, SLOT(Exit()));
}

void ModelSink::ModelUpStreamErrorReciever(const QString& msg) {
    emit SIG_BI("error", msg);
}

void ModelSink::ModelUpStreamReciever(const QString& msg) {
    if(msg == "cadd") {
        emit SIG_TRI("channel" , "add", "ok");
    }
    else if(msg == "cupdate") {
        emit SIG_TRI("channel" , "update", "ok");
    }
    else if(msg == "cdelete") {
        emit SIG_TRI("channel" , "delete", "ok");
    }
    else if(msg == "cinit") {
        emit SIG_TRI("channel" , "init", "ok");
    } 
    else if(msg == "cexit") {
        emit SIG_TRI("channel", "exit", "ok");
    }
}

void ModelSink::DownStreamReciever(
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
        else if(msg == "init") {
            emit SIG_CHANNEL_INIT();
        }
        else if(msg == "exit") {
            emit SIG_CHANNEL_EXIT();
        }
    }
}