#ifndef DETAIL_DIALOG_H
#define DETAIL_DIALOG_H

#include <QDialog>
#include "../articles/articletype.h"

namespace Ui {
class Detail_Dialog;
}

class Detail_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Detail_Dialog(QWidget *parent = nullptr);
    ~Detail_Dialog();
    void setContent(const ArticleData& content);

public slots:
    void slotOpeninBrowser();
    void slotClose();

private:
    Ui::Detail_Dialog *ui;
};

#endif // DETAIL_DIALOG_H
