#ifndef RSSReaderDetail
#define RSSReaderDetail
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>
#include <QFile>
#include "detail_dialog.h"
#include "ui_detail_dialog.h"

Detail_Dialog::Detail_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Detail_Dialog) {
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

    connect(ui->broswer, SIGNAL(clicked()), this, SLOT(slotOpeninBrowser()));
    connect(ui->closedetail, SIGNAL(clicked()), this, SLOT(slotClose()));
}

Detail_Dialog::~Detail_Dialog() {
    delete ui;
}

void Detail_Dialog::setContent(const ArticleData& content) {
    ui->detail_title->setText(content.title);
    ui->content->setText(content.description);
}

void Detail_Dialog::slotOpeninBrowser() {
    QDesktopServices::openUrl(QUrl("http://www.baidu.com"));

    qDebug() << "[Open in Browser] ...";
}

void Detail_Dialog::slotClose() {
    this->close();
}
#endif
