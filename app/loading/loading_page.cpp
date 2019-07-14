#ifndef RSSReader_loadpage
#define RSSReader_loadpage
#include "loading_page.h"
#include "ui_loading_page.h"
#include <Qt>
#include <QFile>
#include <QTextStream>

loading_page::loading_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loading_page) {
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

    loading = new Loading(this);
    loading->start();

    ui->gridLayout_2->addWidget(loading, 1, 1);
}

loading_page::~loading_page()
{
    delete ui;
}
#endif
