#include "model.h"

Model::Model() {
    chans = std::make_shared<Channels>();
    crequest = std::make_shared<CRequest>();
    parser = std::make_shared<RSSParser>();
}
Model::~Model() { }

shared_ptr<Channels> Model::GetChannels() { return chans; }

void Model::UpdateChannel(QString title) {
    auto id = chanTable[title];
    auto url = chans->value(id)->GetLink();
    crequest->GetChannel(url, [&](bool success, QString xml) {
        if(success) {
            parser->SetDoc(xml);
            auto newChan = parser->Parse();
            chans->value(id)->DeepCopy(*newChan);
            emit SIG_CHANNEL_CHANGE("cupdate");
        } else {
            emit SIG_CHANNEL_FAILED("cupdate");
        }
    });
}
void Model::AddChannel(QString url) {
    crequest->GetChannel(url, [&](bool success, QString xml) {
        if(success) {
            parser->SetDoc(xml);
            auto newChan = parser->Parse();
            chans->push_back(newChan);
            chanTable[newChan->GetTitle()] = chans->size() - 1;
            emit SIG_CHANNEL_CHANGE("cadd");
        } else {
            emit SIG_CHANNEL_FAILED("cadd");
        }
    });
}
void Model::DeleteChannel(QString title) {
    auto id = chanTable[title];
    auto lid = chans->size() - 1;
    auto ltitle = chans->value(lid)->GetTitle();
    chanTable[title] = -1;
    chanTable[ltitle] = id;
    chans->value(id)->DeepCopy(*(chans->value(lid)));
    chans->pop_back();
    emit SIG_CHANNEL_CHANGE("cdelete");
}
void Model::UpStreamReciever(const QString& msg) {
    emit SIG_OMIT(msg);
}
void Model::DownStreamReciever(const QString& msg) {
    emit SIG_OMIT(msg);
}