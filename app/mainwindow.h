#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <QMainWindow>
#include <QStandardItemModel>
#include "../view/sink/viewsink.h"
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
    void UpdateLeft(std::shared_ptr<QVector<QString>> allsubtitle);
    void UpdateRight(std::shared_ptr<QVector<PropertyInstance>> allarticles);

signals:
    void SIG_CLOSE();
    void SIG_ADDSUB(const QString&);

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
