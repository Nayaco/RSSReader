#ifndef LOADING_PAGE_H
#define LOADING_PAGE_H

#include <QWidget>
#include "loading.h"

namespace Ui {
class loading_page;
}

class loading_page : public QWidget
{
    Q_OBJECT

public:
    explicit loading_page(QWidget *parent = nullptr);
    ~loading_page();

private:
    Ui::loading_page *ui;
    Loading* loading;
};

#endif // LOADING_PAGE_H
