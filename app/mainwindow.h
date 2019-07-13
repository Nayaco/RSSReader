#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>

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

private:
    Ui::MainWindow *ui;
    QStandardItemModel* subingurls;
    QStandardItemModel* articles;
};

#endif // MAINWINDOW_H
