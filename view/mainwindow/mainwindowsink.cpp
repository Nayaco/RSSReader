#include "mainwindowsink.h"
#include <QDebug>
#include <cassert>

void MainWindowSink::OnMainWindowClose() {
    qDebug() << "[MainWindow close]";
    emit SIG_TRI("channel", "exit", "");
}

void MainWindowSink::UpStreamReciever(const QString& _data, const QString& msg, const QString& target) {
    if(_data == "channel" && msg == "update") {

    }
    else if(_data == "channel" && msg == "init") {
        if(target == "ok") {
            qDebug() << "[Initial ok]";

        }
        else {
            qDebug() << "[initial failed]";
            exit(1);
        }
    }
    else {
        assert(false);
    }
}
