#include <QApplication>
#include "model/model.h"
#include "model/sink/modelsink.h"

class QTT: public QObject {
Q_OBJECT
public:
    QTT() = default;
    ~QTT() = default;
public 
slots:
void finished();
};
void QTT::finished() {
    
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto model = std::make_shared<Model>();
    model->AddChannel("https://rsshub.app/bilibili/ranking/0/3?limit=10");
    // model->AddPropertyNotification();
    
    // auto chans = model->GetChannels();
    // for(auto i : *chans) {
    //     qDebug()<<QString::fromStdString(i->GetTitle());
    //     qDebug()<<QString::fromStdString(i->GetLink());
    //     qDebug()<<QString::fromStdString(i->GetDesc());
    //     qDebug()<<i->GetTTL();
    //     auto &items = i->GetItems();
    //     for(auto j: items) {
    //         qDebug()<<"--item--";
    //         qDebug()<<QString::fromStdString(i->GetTitle());
    //         qDebug()<<QString::fromStdString(i->GetLink());
    //         qDebug()<<QString::fromStdString(i->GetDesc());
    //         qDebug()<<"--------";
    //     }
    // }
    return a.exec();
}
