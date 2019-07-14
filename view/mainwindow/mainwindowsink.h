#ifndef MAINWINDOWSINK_H
#define MAINWINDOWSINK_H

#include "../../app/mainwindow.h"
#include "../../app/loading/loading_page.h"
#include "../sink/viewsink.h"

class MainWindowSink : public ViewSink {
Q_OBJECT
public:
    MainWindowSink() {
        loadpage = std::make_shared<loading_page>();
        mainwindow = std::make_shared<MainWindow>();

        connect(mainwindow.get(), SIGNAL(SIG_CLOSE()), this, SLOT(OnMainWindowClose()));
//        connect(mainwindow.get(), SIGNAL(SIG_ADDSUB(const QString&)), this, SLOT(AddSubcription(const QString&)));

        loadpage->show();
    }
    ~MainWindowSink() = default;
public
slots:
    void OnMainWindowClose();
//    void AddSubcription(const QString&);
    virtual void UpStreamReciever(
        const QString&, const QString&, const QString&) override;
signals:
private:
    shared_ptr<MainWindow> mainwindow;
    shared_ptr<loading_page> loadpage;
};

#endif
