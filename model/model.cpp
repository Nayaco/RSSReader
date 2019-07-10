#include "model.h"

Model::Model() {
    chans = std::make_shared<QVector<shared_ptr<Channel>>>();
    crequest = std::make_shared<CRequest>();
    parser = std::make_shared<RSSParser>();
}
Model::~Model() {
}

Channels Model::GetChannels() {
    return chans;
}
void Model::UpdateChannel(QString title) {
    auto id = chanTable[title];
    auto url = chans->value(id)->GetLink();
    crequest->GetChannel(QString::fromStdString(url), [&](bool success, QString xml) {
        if(success) {
            parser->SetDoc(xml.toStdString());
            auto newChan = parser->Parse();
            chans->value(id)->DeepCopy(*newChan);
            TriggerNotification("Channel");
        }
    });
}
void Model::AddChannel(QString url) {
    crequest->GetChannel(url, [&](bool success, QString xml) {
        if(success) {
            parser->SetDoc(xml.toStdString());
            auto newChan = parser->Parse();
            chans->push_back(newChan);
            chanTable[QString::fromStdString(newChan->GetTitle())] = chans->size() - 1;
            // auto chansr = newChan;
            for(auto i : *chans) {
                qDebug()<<QString::fromStdString(i->GetTitle());
                qDebug()<<QString::fromStdString(i->GetLink());
                qDebug()<<QString::fromStdString(i->GetDesc());
                qDebug()<<i->GetTTL();
                auto &items = i->GetItems();
                for(auto j: items) {
                    qDebug()<<"--item--";
                    qDebug()<<QString::fromStdString(j->GetTitle());
                    qDebug()<<QString::fromStdString(j->GetLink());
                    qDebug()<<QString::fromStdString(j->GetDesc());
                    qDebug()<<"--------";
                }
            }
            TriggerNotification("Channel");
        }
    });
}
void Model::DeleteChannel(QString title) {
    auto id = chanTable[title];
    auto lid = chans->size() - 1;
    auto ltitle = QString::fromStdString(chans->value(lid)->GetTitle());
    chanTable[title] = -1;
    chanTable[ltitle] = id;
    chans->value(id)->DeepCopy(*(chans->value(lid)));
    chans->pop_back();
    TriggerNotification("Channel");
}