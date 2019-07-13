#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include "details/detail_dialog.h"

enum State {
    loading,
    running
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void slotSubscription();
    void slotItemClicked(QModelIndex idx);
    void slotArticleClicked(QModelIndex idx);

private:
    Ui::MainWindow *ui;
    QStandardItemModel* subingurls;
    QStandardItemModel* articles;
    Detail_Dialog* detail_window;
    State curState;
};

#endif // MAINWINDOW_H
