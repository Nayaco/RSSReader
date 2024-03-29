#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "articles/articles.h"
#include "articles/articletype.h"
#include "../model/model.h"
#include <QtDebug>
#include <QFile>
#include <QDir>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent = nullptr), ui(new Ui::MainWindow) {
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

    this->resize(QSize(1600, 800));

    detail_window = new Detail_Dialog();
    detail_window->resize(QSize(800, 600));

    connect(ui->subbutton, SIGNAL(clicked()), this, SLOT(slotSubscription()));
    connect(ui->listView, SIGNAL(clicked(QModelIndex)), this, SLOT(slotArticleClicked(QModelIndex)));
}

MainWindow::~MainWindow() {
    delete ui;
    delete subingurls;
    emit SIG_CLOSE();
}

void MainWindow::UpdateLeft(std::shared_ptr<QVector<QString>> allsubtitle) {
    subingurls = new QStandardItemModel(this);
    QStringList strList;

    for (QVector<QString>::iterator iter = allsubtitle->begin();iter != allsubtitle->end(); iter++) {
        qDebug() << *iter << "\n";
        strList << *iter;
    }
//    for(int i = 0; i < 5; i++) {
//        strList << ("string" + QString::number(i));
//    }
    int nCount = strList.size();
    for(int i = 0; i < nCount; i++) {
        QString string = static_cast<QString>(strList.at(i));
        QStandardItem *item = new QStandardItem(string);
        subingurls->appendRow(item);
    }
    ui->subinglist->setModel(subingurls);
}

void MainWindow::UpdateRight(std::shared_ptr<QVector<PropertyInstance>> allarticles) {
    articles = new QStandardItemModel(this);
    for(QVector<PropertyInstance>::iterator iter = allarticles->begin(); iter != allarticles->end(); iter++) {
        ChannelInstance tmpval = std::dynamic_pointer_cast<Channel>(*iter);
        std::shared_ptr<Items> items = tmpval->GetItems();
        for(QVector<shared_ptr<Item>>::iterator jter = items->begin(); jter != items->end(); jter++) {
            ArticleData curData;
            curData = (*jter)->GetArticle();
            QStandardItem* item = new QStandardItem;
            item->setData(QVariant::fromValue(curData), Qt::UserRole + 1);
            articles->appendRow(item);
        }
    }

    Articles* pArticles = new Articles(this);
    ui->listView->setItemDelegate(pArticles);
    ui->listView->setModel(articles);
}

void MainWindow::slotSubscription() {
    QString msg = ui->suburlinput->text();
    emit SIG_ADDSUB(msg);
}

void MainWindow::slotArticleClicked(QModelIndex idx) {
    QVariant var = idx.data(Qt::UserRole + 1);
    ArticleData curData = var.value<ArticleData>();

    detail_window->setContent(curData);
    detail_window->show();

    qDebug() << "[click article] " << curData.title;
}
