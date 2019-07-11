#include "model.h"

Model::Model() {
    chans.clear();
    crequest = std::make_shared<CRequest>();
    parser = std::make_shared<RSSParser>();
}
Model::~Model() { }

// shared_ptr<Channels> Model::GetChannels() { return chans; }

void Model::UpdateChannel(const QString& title) {
    if(chans.find(title) == chans.end()) 
        emit SIG_CHANNEL_FAILED("miss");
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
            if(chans.find(newChan->GetTitle()) != chans.end()) 
                emit SIG_CHANNEL_FAILED("exist");
            chans[newChan->GetTitle()] = newChan;
            emit SIG_CHANNEL_CHANGE("cadd");
        } else {
            emit SIG_CHANNEL_FAILED("cadd");
        }
    });
}
void Model::DeleteChannel(const QString& title) {
    auto iter = chans.find(title);
    if(iter == chans.end()) 
        emit SIG_CHANNEL_FAILED("miss");
    chans.erase(iter);
    emit SIG_CHANNEL_CHANGE("cdelete");
}

void Model::UpStreamReciever(const QString& msg) {
    emit SIG_OMIT(msg);
}
void Model::DownStreamReciever(const QString& msg) {
    emit SIG_OMIT(msg);
}

shared_ptr<QVector<PropertyInstance>> Model::Get(const QVector<QString>& _target) {
    auto res = std::make_shared<QVector<PropertyInstance>>();
    for(auto iter : _target) {
        res->push_back(std::static_pointer_cast<Property>(chans[iter]));
    }
    return res;
}

shared_ptr<QVector<QString>>  Model::GetMeta() {
    auto res = std::make_shared<QVector<QString>>();
    for(auto iter =  chans.keyBegin(); iter != chans.keyEnd(); ++iter) {
        res->push_back(*iter);
    }
    return res;
}