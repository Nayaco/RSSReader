#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "articles/articles.h"
#include "articles/articletype.h"
#include <QtDebug>
#include <QFile>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    qDebug() << QDir::currentPath();
    QFile f(":qdarkstyle/style.qss");
    if (!f.exists()) {
        printf("Unable to set stylesheet, file not found\n");
    }
    else {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        this->setStyleSheet(ts.readAll());
    }

    ui->setupUi(this);

    detail_window = new Detail_Dialog();


    subingurls = new QStandardItemModel(this);
    QStringList strList;
    for(int i = 0; i < 30; i++) {
        strList << ("string" + QString::number(i));
    }
    int nCount = strList.size();
    for(int i = 0; i < nCount; i++) {
        QString string = static_cast<QString>(strList.at(i));
        QStandardItem *item = new QStandardItem(string);
        subingurls->appendRow(item);
    }
    ui->subinglist->setModel(subingurls);

    articles = new QStandardItemModel(this);
    for(int i = 0; i < 20; i++) {
        QStandardItem* item = new QStandardItem;
        ArticleData curData;
        curData.from = "string0";
        curData.title = "This is a title";
        curData.description = "This is a looooooooong description.";
        item->setData(QVariant::fromValue(curData), Qt::UserRole + 1);
        articles->appendRow(item);
    }

    Articles* pArticles = new Articles(this);
    ui->listView->setItemDelegate(pArticles);
    ui->listView->setModel(articles);

    connect(ui->subbutton, SIGNAL(clicked()), this, SLOT(slotSubscription()));
    connect(ui->subinglist, SIGNAL(clicked(QModelIndex)), this, SLOT(slotItemClicked(QModelIndex)));
    connect(ui->listView, SIGNAL(clicked(QModelIndex)), this, SLOT(slotArticleClicked(QModelIndex)));
}

MainWindow::~MainWindow() {
    delete ui;
    delete subingurls;
}

void MainWindow::slotSubscription() {
    QString msg = ui->suburlinput->text();
    qDebug() << "[debug info] " << msg;
}

void MainWindow::slotItemClicked(QModelIndex idx) {
    qDebug() << "[click item] " << idx.data().toString();
}

void MainWindow::slotArticleClicked(QModelIndex idx) {
    QVariant var = idx.data(Qt::UserRole + 1);
    ArticleData curData = var.value<ArticleData>();

    detail_window->setContent(curData);
    detail_window->show();

    qDebug() << "[click article] " << curData.title;
}
