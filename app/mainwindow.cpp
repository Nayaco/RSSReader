#include "mainwindow.h"
#include <QPushButton>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
    setFixedSize(500, 250);

    m_button = new QPushButton("Hello!", this);
    m_button->setGeometry(100, 100, 160, 60);

    m_button->setCheckable(true);
    this->m_counter = 0;

    connect(m_button, SIGNAL(clicked(bool)), this, SLOT(slotButtonClicked(bool)));
    connect(this, SIGNAL(counterReached()), QApplication::instance(), SLOT(quit()));
}

void MainWindow::slotButtonClicked(bool checked) {
    if(checked) {
        m_button->setText("Checked");
    }
    else {
        m_button->setText("Hello World");
    }
    this->m_counter++;
    if(this->m_counter >= 10) {
        emit counterReached();
    }
}
