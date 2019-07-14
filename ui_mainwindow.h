/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QSplitter *splitter;
    QScrollArea *subinfo;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *suburlinput;
    QPushButton *subbutton;
    QLabel *label;
    QListView *subinglist;
    QScrollArea *subarticle;
    QWidget *scrollAreaWidgetContents_5;
    QVBoxLayout *verticalLayout_2;
    QListView *listView;
    QMenuBar *menuBar;
    QMenu *menuRSSReader;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(657, 477);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        subinfo = new QScrollArea(splitter);
        subinfo->setObjectName(QString::fromUtf8("subinfo"));
        subinfo->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 270, 424));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(scrollAreaWidgetContents_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        suburlinput = new QLineEdit(scrollAreaWidgetContents_3);
        suburlinput->setObjectName(QString::fromUtf8("suburlinput"));

        verticalLayout->addWidget(suburlinput);

        subbutton = new QPushButton(scrollAreaWidgetContents_3);
        subbutton->setObjectName(QString::fromUtf8("subbutton"));

        verticalLayout->addWidget(subbutton);

        label = new QLabel(scrollAreaWidgetContents_3);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        subinglist = new QListView(scrollAreaWidgetContents_3);
        subinglist->setObjectName(QString::fromUtf8("subinglist"));

        verticalLayout->addWidget(subinglist);

        subinfo->setWidget(scrollAreaWidgetContents_3);
        splitter->addWidget(subinfo);
        subarticle = new QScrollArea(splitter);
        subarticle->setObjectName(QString::fromUtf8("subarticle"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(subarticle->sizePolicy().hasHeightForWidth());
        subarticle->setSizePolicy(sizePolicy);
        subarticle->setWidgetResizable(true);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_5"));
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 366, 424));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_5);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        listView = new QListView(scrollAreaWidgetContents_5);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout_2->addWidget(listView);

        subarticle->setWidget(scrollAreaWidgetContents_5);
        splitter->addWidget(subarticle);

        horizontalLayout->addWidget(splitter);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 657, 15));
        menuRSSReader = new QMenu(menuBar);
        menuRSSReader->setObjectName(QString::fromUtf8("menuRSSReader"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuRSSReader->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\242\236\350\256\242\351\230\205", nullptr));
        subbutton->setText(QCoreApplication::translate("MainWindow", "\350\256\242\351\230\205\350\277\231\344\270\252\346\272\220", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\256\242\351\230\205\345\210\227\350\241\250", nullptr));
        menuRSSReader->setTitle(QCoreApplication::translate("MainWindow", "RSSReader", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
