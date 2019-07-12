#include "model.h"

Model::Model() {
    chans.clear();
    crequest = std::make_shared<CRequest>();
    parser = std::make_shared<RSSParser>();
}
Model::~Model() { 
}


void Model::UpdateChannel(const QString& title) {
    if(chans.find(title) == chans.end()) {
        emit SIG_CHANNEL_FAILED("miss");
        return;
    }
    QString url = chans[title]->GetSource();
    crequest->GetChannel(url, [=](bool success, QString xml, QString _url) {
        if(success) {
            parser->SetDoc(xml);
            newChan = parser->Parse();
            chans[title]->DeepCopy(*newChan);

            emit SIG_CHANNEL_CHANGE("cupdate");
        } else {
            emit SIG_CHANNEL_FAILED("cupdate");
        }
    });
}
void Model::AddChannel(const QString& url) {
    crequest->GetChannel(url, [=](bool success, QString xml, QString _url) {
        if(success) {
            parser->SetDoc(xml);
            newChan = parser->Parse();
            if(chans.find(newChan->GetTitle()) != chans.end()) 
                emit SIG_CHANNEL_FAILED("exist");
            newChan->SetSource(url);
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
    for(auto iter = chans.keyBegin(); iter != chans.keyEnd(); ++iter) {
        res->push_back(*iter);
    }
    return res;
}

void Model::SetImg(const QString& title) {
    
    QRegExp regexp("<img(.+)>");
    

    // irequest->GetImg(url, [=](bool success, QString xml, QString _url) {
    //     if(success) {
    //         parser->SetDoc(xml);
    //         newChan = parser->Parse();
    //         if(chans.find(newChan->GetTitle()) != chans.end()) 
    //             emit SIG_CHANNEL_FAILED("exist");
    //         newChan->SetSource(url);
    //         chans[newChan->GetTitle()] = newChan;
    //         emit SIG_CHANNEL_CHANGE("cadd");
    //     } else {
    //         emit SIG_CHANNEL_FAILED("cadd");
    //     }
    // });
}

static QString RSSCACHE = "../.rsscache/channels.cache";
static QString RSSDIR = "..";


void Model::Init() {    
    QString cachePath = QCoreApplication::applicationDirPath() + "/" + RSSCACHE;
    QDir dir(QCoreApplication::applicationDirPath() + "/" + RSSDIR);
    if(!dir.exists(".rsscache")) {
        dir.mkdir(".rsscache");
    }
    if(!QFile::exists(cachePath)) {
        QFile cache(cachePath);
        cache.open(QIODevice::WriteOnly | QIODevice::Text);
        cache.close();
    } else {
        QFile cache(cachePath);
        cache.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream input(&cache);
        while(!input.atEnd()) {
            QString line = input.readLine();
            QRegExp regexp("<(.+)>");
            regexp.setMinimal(true);
            int pos = 0;
            pos = regexp.indexIn(line, pos);
            if(pos == -1) break;
            pos += regexp.matchedLength();
            
            QString title = regexp.cap(1);
            chans[title] = std::make_shared<Channel>();
            pos = regexp.indexIn(line, pos);
            chans[title]->SetSource(regexp.cap(1));
        }
        cache.close();
    }
    emit SIG_CHANNEL_CHANGE("cinit");
}
void Model::Exit() {
    QString cachePath = QCoreApplication::applicationDirPath() + "/" + RSSCACHE;
    QFile cache(cachePath);
    cache.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream output(&cache);
    for(auto iter: chans) {
        output<<"<"<<iter->GetTitle()<<"><"<<iter->GetSource()<<">\n";
    }
    cache.close();
    emit SIG_CHANNEL_CHANGE("cexit");
}