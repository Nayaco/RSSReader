#include <QApplication>
#include "model/model.h"
#include "testModel.h"
void QTT::finished(const QString& _ans) {
    auto meta = model->GetMeta();
    for(auto i: *meta) {
        qDebug()<<i;
    }
    auto data = model->Get(*meta);
    for(auto i: *data) {
        auto q = std::dynamic_pointer_cast<Channel>(i);
        qDebug()<<q->GetTitle();
        qDebug()<<q->GetLink();
        qDebug()<<q->GetDesc();
        qDebug()<<q->GetTTL();
        auto items = q->GetItems();
        for(auto j: *items) {
            qDebug()<<"--item--";
            qDebug()<<j->GetTitle();
            qDebug()<<j->GetLink();
            qDebug()<<j->GetDesc();
            qDebug()<<"--------";
        }
    }
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto qtt = std::make_shared<QTT>();
    qtt->start();
    
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
