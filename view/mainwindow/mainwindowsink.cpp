#include "mainwindowsink.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <cassert>

MainWindowSink::MainWindowSink()  {
    loadpage = std::make_shared<loading_page>();
    mainwindow = std::make_shared<MainWindow>();

    connect(mainwindow.get(), SIGNAL(SIG_CLOSE()), this, SLOT(OnMainWindowClose()));
    connect(mainwindow.get(), SIGNAL(SIG_ADDSUB(const QString&)), this, SLOT(AddSubcription(const QString&)));

    connect(mainwindow.get()->get_ui()->subinglist, SIGNAL(clicked(QModelIndex)), this, SLOT(slotItemClicked(QModelIndex)));

    loadpage->show();
}

void MainWindowSink::OnMainWindowClose() {
    qDebug() << "[MainWindow close]";
    emit SIG_TRI("channel", "exit", "");
}

void MainWindowSink::AddSubcription(const QString& url) {
    loadpage->show();
    qDebug() << "[Add subscription] " << url;
    emit SIG_TRI("channel", "add", url);
}

void MainWindowSink::slotItemClicked(QModelIndex idx) {
    static QString last_clicked = "";
    QString title = idx.data().toString();
    if(last_clicked == title) {
        last_clicked = "";
        UpdateArticle();
    }
    else {
        last_clicked = title;
        UpdateArticle(title);
    }
}

void MainWindowSink::UpdateSub() {
    qDebug() << "[Updating Subscription]";
    std::shared_ptr<QVector<QString>> allsubtitle = viewmodel->GetMeta("channel");

    for (QVector<QString>::iterator iter = allsubtitle->begin();iter != allsubtitle->end(); iter++) {
        qDebug() << *iter;
    }
    qDebug() << "[End]";
    mainwindow->UpdateLeft(allsubtitle);
}

void MainWindowSink::UpdateArticle(const QString& title) {
    shared_ptr<QVector<PropertyInstance>> articles;
    if(title.isEmpty()) {
        std::shared_ptr<QVector<QString>> allsubtitle = viewmodel->GetMeta("channel");
        articles = viewmodel->Get("channel", *allsubtitle);
    }
    else {
        QVector<QString> args;
        args.push_back(title);
        articles = viewmodel->Get("channel", args);
    }
    mainwindow->UpdateRight(articles);
}

void MainWindowSink::UpStreamReciever(const QString& _data, const QString& msg, const QString& target) {
    qDebug() << "[=== QAQ ===] " << _data << ' ' << msg << ' ' << target;
    if(_data == "channel" && msg == "init") {
        if(target == "ok") {
            qDebug() << "[Initial ok]";
            loadpage->close();
            mainwindow->show();
            UpdateSub();
            UpdateArticle();
        }
        else {
            qDebug() << "[initial failed]";
            exit(1);
        }
    }
    else if(_data == "channel" && msg == "add") {
        if(target == "ok") {
            UpdateSub();
            UpdateArticle();
            loadpage->close();
        }
        else {
            qDebug() << "[Add subscription ok]";
            loadpage->close();
            exit(1);
        }
    }
    else if(_data == "channel" && msg == "update") {
        if(target == "ok") {
            UpdateSub();
            UpdateArticle();
        }
        else {
            qDebug() << "[Update failed]";
            exit(1);
        }
    }
    else if(_data == "channel" && msg == "exit") {
        qDebug()<<"[Exit Success]";
    }
    else {
//        assert(false);
    }
}
