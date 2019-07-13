#ifndef RSSReaderDetail
#define RSSReaderDetail
#include <QDebug>
#include "detail_dialog.h"
#include "ui_detail_dialog.h"

Detail_Dialog::Detail_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Detail_Dialog)
{
    ui->setupUi(this);

    connect(ui->broswer, SIGNAL(clicked()), this, SLOT(slotOpeninBrowser()));
    connect(ui->closedetail, SIGNAL(clicked()), this, SLOT(slotClose()));
}

Detail_Dialog::~Detail_Dialog()
{
    delete ui;
}

void Detail_Dialog::setContent(const ArticleData& content) {
    ui->detail_title->setText(content.title);
    ui->content->setText(content.description);
}

void Detail_Dialog::slotOpeninBrowser() {
    qDebug() << "[Open in Browser] ...";
}

void Detail_Dialog::slotClose() {
    this->close();
}
#endif
