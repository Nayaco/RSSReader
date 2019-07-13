#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

    connect(ui->subbutton, SIGNAL(clicked()), this, SLOT(subscription()));
    connect(ui->subinglist, SIGNAL(clicked(QModelIndex)), this, SLOT(itemClicked(QModelIndex)));
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
