#include "model.h"

Model::Model() {
    chans.clear();
    crequest = std::make_shared<CRequest>();
    parser = std::make_shared<RSSParser>();
}
Model::~Model() { }

// shared_ptr<Channels> Model::GetChannels() { return chans; }

void Model::UpdateChannel(const QString& title) {
    if(chans.find(title) == chans.end()) emit(SIG_CHANNEL_FAILED("miss"));
    auto url = chans[title]->GetLink();
    crequest->GetChannel(url, [&](bool success, QString xml) {
        if(success) {
            parser->SetDoc(xml);
            auto newChan = parser->Parse();
            chans[title]->DeepCopy(*newChan);
            emit SIG_CHANNEL_CHANGE("cupdate");
        } else {
            emit SIG_CHANNEL_FAILED("cupdate");
        }
    });
}
void Model::AddChannel(const QString& url) {
    crequest->GetChannel(url, [&](bool success, QString xml) {
        if(success) {
            parser->SetDoc(xml);
            auto newChan = parser->Parse();
            chans[newChan->GetTitle()] = newChan;
            emit SIG_CHANNEL_CHANGE("cadd");
        } else {
            emit SIG_CHANNEL_FAILED("cadd");
        }
    });
}
void Model::DeleteChannel(const QString& title) {
    auto iter = chans.find(title);
    if(iter == chans.end()) emit(SIG_CHANNEL_FAILED("miss"));
    chans.erase(iter);
    emit SIG_CHANNEL_CHANGE("cdelete");
}

void Model::UpStreamReciever(const QString& msg) {
    emit SIG_OMIT(msg);
}
void Model::DownStreamReciever(const QString& msg) {
    emit SIG_OMIT(msg);
}

shared_ptr<QVector<Property>> Get(const QString&) {
    
}