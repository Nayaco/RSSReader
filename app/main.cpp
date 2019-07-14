#include "main.h"
#include <QApplication>
void RssReaderCore::UpStreamReciever(
        const QString& data, const QString& msg, const QString& stat) {
    zero ++;
    qDebug()<<data<<msg<<stat;
    if(data == "channel" && msg == "update" && stat == "ok" && zero == 1) {    
        ctimer->StartTik();
    }
    
    qDebug()<<"--ttttttt-- "<<zero;
    auto _model = std::dynamic_pointer_cast<Model>(model->GetChild());

    auto meta = vm->GetMeta("channel");
    for(auto i: *meta) {
        qDebug()<<i;
    }
    qDebug()<<"--ttttttt-- "<<zero<<"\n";
    
}
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    RssReaderCore core;
    core.init();

    return a.exec();
}
