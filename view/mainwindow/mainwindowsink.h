#ifndef MAINWINDOWSINK_H
#define MAINWINDOWSINK_H

#include "../../app/mainwindow.h"
#include "../sink/viewsink.h"
class MainWindowSink : public ViewSink {
Q_OBJECT
public:
    MainWindowSink() {
        mainwindow = std::make_shared<MainWindow>();
        connect(
            mainwindow.get(),
            SIGNAL(SIG_CLOSE()),
            this,
            SLOT(OnMainWindowClose())
        );
        mainwindow->show();
    }
    ~MainWindowSink() = default;
public
slots:
    void OnMainWindowClose();
    virtual void UpStreamReciever(
        const QString&, const QString&, const QString&) override;
signals:
private:
    shared_ptr<MainWindow> mainwindow;
};

#endif