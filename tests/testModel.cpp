#include <QApplication>
#include "model/model.h"
#include "testModel.h"
void QTT::finished(const QString& _ans1, const QString& _ans2, const QString& _ans3) {
    qDebug()<<"--ttttttt--";
    auto _model = std::dynamic_pointer_cast<Model>(model->GetChild());
    auto meta = _model->GetMeta();
    for(auto i: *meta) {
        qDebug()<<i;
    }
    qDebug()<<"--ttttttt--";
    auto data = _model->Get(*meta);
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
    if(zero==0) {
        zero = 1;
        emit SIG_TEST("channel", "update", "bilibili 3日排行榜-动画-近期投稿");
    } else if(zero == 1) {
        zero = 2;
        emit SIG_TEST("channel", "delete", "bilibili 3日排行榜-动画-近期投稿");
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
