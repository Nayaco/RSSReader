#include <QApplication>
#include "testMiddleware.h"
#include <QObject>
#include <QDebug>

void Counter::setValue(int value)
{
    if (value != m_value) {
        m_value = value;
        emit valueChanged(value);
    }
}

int main(int argc, char *argv[])
{
    QApplication ax(argc, argv);
    Counter a, b;
    QObject::connect(&a, SIGNAL(valueChanged(int)),&b, SLOT(setValue(int)));
 
    a.setValue(12);     //  a.value() == 12, b.value() == 12
    b.setValue(48);        //   a.value() == 12, b.value() == 48
    qDebug()<<a.value();
    qDebug()<<b.value();
    // Middleware a, b;
    // QObject::connect(&a, SIGNAL());
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
    return ax.exec();
}
