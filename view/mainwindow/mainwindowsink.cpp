#include "mainwindowsink.h"
#include <QDebug>
#include <cassert>

MainWindowSink::MainWindowSink()  {
    loadpage = std::make_shared<loading_page>();
    mainwindow = std::make_shared<MainWindow>();

    connect(mainwindow.get(), SIGNAL(SIG_CLOSE()), this, SLOT(OnMainWindowClose()));
//        connect(mainwindow.get(), SIGNAL(SIG_ADDSUB(const QString&)), this, SLOT(AddSubcription(const QString&)));

    loadpage->show();
}

void MainWindowSink::OnMainWindowClose() {
    qDebug() << "[MainWindow close]";
    emit SIG_TRI("channel", "exit", "");
}

void MainWindowSink::UpStreamReciever(const QString& _data, const QString& msg, const QString& target) {
    qDebug() << "[=== QAQ ===]";
    if(_data == "channel" && msg == "update") {

    }
    else if(_data == "channel" && msg == "init") {
        if(target == "ok") {
            qDebug() << "[Initial ok]";
            loadpage->close();
            mainwindow->show();
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
