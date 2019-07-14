#include "model.h"

Model::Model() {
    busy = 0;
    chans.clear();
    crequest = std::make_shared<CRequest>();
    irequest = std::make_shared<IRequest>();
    parser = std::make_shared<RSSParser>();
    connect(
        this,
        SIGNAL(SIG_IMG(const QString&)),
        this,
        SLOT(SetImg(const QString&)));
}
Model::~Model() { 
}

void Model::UpdateChannel(const QString& title) {
    if(chans.find(title) == chans.end()) {
        emit SIG_CHANNEL_FAILED("miss");
        return;
    }
    if(!busy) 
        busy = 1;
    else 
        emit SIG_CHANNEL_FAILED("busy");
    QString url = chans[title]->GetSource();
    crequest->GetChannel(url, [&](bool success, QString xml, QString _url) {
        if(success) {
            parser->SetDoc(xml);
            newChan = parser->Parse();
            newItems = newChan->GetItems();
            icounter = 0;
            emit SIG_IMG("cupdate");
        } else {
            busy = 0;
            emit SIG_CHANNEL_FAILED("cupdate");
        }
    });
}
void Model::AddChannel(const QString& url) {
    qDebug()<<"add"<<url<<busy;
    if(!busy) {
        busy = 1;
        iurl = url;
        iurl.replace("\n", "");
    }
    else {
        emit SIG_CHANNEL_FAILED("busy");
        return;
    }
    crequest->GetChannel(url, [&](bool success, QString xml, QString _url) {
        if(success) {
            parser->SetDoc(xml);
            newChan = parser->Parse();
            newChan->SetSource(iurl);
            newItems = newChan->GetItems();
            icounter = 0;
            emit SIG_IMG("cadd");
        } else {
            busy = 0;
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

void Model::SetImg(const QString& act) {
    if(icounter == newItems->size()) {
        busy = 0;
        if(act == "cadd")
            chans[newChan->GetTitle()] = newChan;
        else if(act == "cupdate")
            chans[newChan->GetTitle()]->DeepCopy(*newChan);
        emit SIG_CHANNEL_CHANGE(act);
        return;
    }
    QRegExp regexp("<img(.+)>");
    QRegExp regexp2("src=\"(.+)\"");
    QRegExp regexp3("<(.+)>");
    QRegExp regexp4("\\s{2,}");
    regexp.setMinimal(true);
    regexp2.setMinimal(true);
    regexp3.setMinimal(true);
    int finded = regexp.indexIn(newItems->value(icounter)->GetDesc());
    if(finded == -1) {
        Q_INIT_RESOURCE(images);
        QPixmap imgdefault(":/default_img.jpeg");
        newItems->value(icounter)->SetImg(imgdefault);
        icounter++;
        emit SIG_IMG(act);
        return;
    }
    regexp2.indexIn(regexp.cap(1));
    QString url = regexp2.cap(1);
    QString newDesc = newItems->value(icounter)->GetDesc().replace(regexp3, "  ");
    newDesc.replace(regexp4, " ");
    newDesc.replace("\n", ",");
    newItems->value(icounter)->SetDesc(newDesc);
    int count = icounter;
    irequest->GetImg(url, [=](bool success, QPixmap img, QString _url) {
        if(success) {
            newItems->value(count)->SetImg(img);
            emit SIG_IMG(act);
        } else {
            busy = 0;
            emit SIG_CHANNEL_FAILED(act);
        }
    });
    icounter++;
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
    qDebug()<<"Exiting";
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