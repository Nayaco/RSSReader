#ifndef DETAILS_H
#define DETAILS_H

#include <QDockWidget>

namespace Ui {
class Details;
}

class Details : public QDockWidget
{
    Q_OBJECT

public:
    explicit Details(QWidget *parent = nullptr);
    ~Details();

private:
    Ui::Details *ui;
};

#endif // DETAILS_H
