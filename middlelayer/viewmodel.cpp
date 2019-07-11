#include "viewmodel.h"

ViewModel::ViewModel() { }

ViewModel::~ViewModel() { }

void ViewModel::BindModel(shared_ptr<Model> _modelInstance) {
    
}
void ViewModel::UpStreamReciever(const QString& msg) {
    if(msg == "cupdate" || msg == "cadd" || msg == "cdelete")
        emit SIG_PROPS_CHANGED("channel");
}
void ViewModel::DownStreamReciever(const QString& msg) {
}

void ViewModel::ChannelUpStreamFailureHandler(const QString& msg) {
    if(msg == "cadd" || msg == "cupdate") 
        emit SIG_CMD_FAIL("channel");
} 

void ViewModel::ChannelDownStreamReciever(const QString& msg, const QString& _data) {
    if(msg == "cadd") {
        emit SIG_CMD_CADD("cadd");
    }
    else if(msg == "cupdate") {
        emit SIG_CMD_CUPDATE("cupdate");
    }
    else if(msg == "cdelete") {
        emit SIG_CMD_CDELETE("cdelete");
    }
}
