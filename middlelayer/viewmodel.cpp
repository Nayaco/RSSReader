#include "viewmodel.h"


void ViewModel::BindModel(shared_ptr<ModelSink> modelsink) {
    model = modelsink->GetModel();
    connect(modelsink, SIGNAL(SIG_PROPS_CHANGED), this, );
}

// void ViewModel::UpStreamReciever(const QString& msg) {
//     if(msg == "cupdate" || msg == "cadd" || msg == "cdelete") {
//         PropsUnsync["channel"] = false;
//         emit SIG_PROPS_CHANGED("channel");
//     }
// }
// void ViewModel::DownStreamReciever(const QString& msg) {
// }

// void ViewModel::ChannelUpStreamFailureHandler(const QString& msg) {
//     if(msg == "cadd" || msg == "cupdate") {
//         PropsUnsync["channel"] = false;
//         emit SIG_CMD_FAIL("channel");
//     }
// } 

// void ViewModel::ChannelDownStreamReciever(const QString& msg, const QString& _data) {
//     if(msg == "cadd") {
//         PropsUnsync["channel"] = true;
//         emit SIG_CMD_CADD("cadd");
//     }
//     else if(msg == "cupdate") {
//         PropsUnsync["channel"] = true;
//         emit SIG_CMD_CUPDATE("cupdate");
//     }
//     else if(msg == "cdelete") {
//         PropsUnsync["channel"] = true;
//         emit SIG_CMD_CDELETE("cdelete");
//     }
// }
