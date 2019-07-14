#ifndef MAINWINDOWSINK_H
#define MAINWINDOWSINK_H

#include "../../app/mainwindow.h"
#include "../../app/loading/loading_page.h"
#include "../sink/viewsink.h"

class MainWindowSink : public ViewSink {
Q_OBJECT
public:
    MainWindowSink();
    ~MainWindowSink() = default;
    void UpdateSub();
public
slots:
    void OnMainWindowClose();
    void AddSubcription(const QString&);
    virtual void UpStreamReciever(const QString&, const QString&, const QString&) override;
signals:
private:
    shared_ptr<MainWindow> mainwindow;
    shared_ptr<loading_page> loadpage;
};

#endif
