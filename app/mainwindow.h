#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

class QPushButton;
class MainWindow : public QWidget {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:
    void counterReached();
public slots:
    void slotButtonClicked(bool checked);
private:
    int m_counter;
    QPushButton* m_button;
};

#endif // WINDOW_H
