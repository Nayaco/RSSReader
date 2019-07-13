#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QCloseEvent>
namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    virtual void closeEvent(QCloseEvent *event) override;  
private:
    Ui::MainWindow *ui;
public
slots:
signals:
    void SIG_CLOSE();
};

#endif // MAINWINDOW_H
