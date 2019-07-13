#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD:app/mainwindow.h
#include <QStandardItemModel>
#include "details/detail_dialog.h"

enum State {
    loading,
    running
};

=======
#include <QWidget>
#include <QCloseEvent>
>>>>>>> Backend:view/mainwindow/mainwindow.h
namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
<<<<<<< HEAD:app/mainwindow.h

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
=======
protected:
    virtual void closeEvent(QCloseEvent *event) override;  
private:
    Ui::MainWindow *ui;
public
slots:
signals:
    void SIG_CLOSE();
>>>>>>> Backend:view/mainwindow/mainwindow.h
};

#endif // MAINWINDOW_H
