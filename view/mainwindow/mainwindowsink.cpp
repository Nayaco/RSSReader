#include "mainwindowsink.h"
#include <QDebug>
void MainWindowSink::OnMainWindowClose() {
    qDebug()<<"mainwindow close";
    emit SIG_TRI("channel", "exit", "");
}

void MainWindowSink::UpStreamReciever(
        const QString&, const QString&, const QString&) {
}