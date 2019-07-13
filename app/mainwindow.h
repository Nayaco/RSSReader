#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "details/detail_dialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void SIG_CLOSE();

public slots:
    void slotSubscription();
    void slotItemClicked(QModelIndex idx);
    void slotArticleClicked(QModelIndex idx);

private:
    Ui::MainWindow *ui;
    QStandardItemModel* subingurls;
    QStandardItemModel* articles;
    Detail_Dialog* detail_window;
};

#endif // MAINWINDOW_H
