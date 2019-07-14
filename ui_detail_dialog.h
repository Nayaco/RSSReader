/********************************************************************************
** Form generated from reading UI file 'detail_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAIL_DIALOG_H
#define UI_DETAIL_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Detail_Dialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *detail_title;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QLabel *content;
    QHBoxLayout *horizontalLayout;
    QPushButton *broswer;
    QPushButton *closedetail;

    void setupUi(QDialog *Detail_Dialog)
    {
        if (Detail_Dialog->objectName().isEmpty())
            Detail_Dialog->setObjectName(QString::fromUtf8("Detail_Dialog"));
        Detail_Dialog->resize(538, 422);
        verticalLayout_2 = new QVBoxLayout(Detail_Dialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        detail_title = new QLabel(Detail_Dialog);
        detail_title->setObjectName(QString::fromUtf8("detail_title"));

        verticalLayout->addWidget(detail_title);

        scrollArea = new QScrollArea(Detail_Dialog);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 520, 368));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        content = new QLabel(scrollAreaWidgetContents);
        content->setObjectName(QString::fromUtf8("content"));

        verticalLayout_3->addWidget(content);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        broswer = new QPushButton(Detail_Dialog);
        broswer->setObjectName(QString::fromUtf8("broswer"));

        horizontalLayout->addWidget(broswer);

        closedetail = new QPushButton(Detail_Dialog);
        closedetail->setObjectName(QString::fromUtf8("closedetail"));

        horizontalLayout->addWidget(closedetail);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Detail_Dialog);

        QMetaObject::connectSlotsByName(Detail_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Detail_Dialog)
    {
        Detail_Dialog->setWindowTitle(QCoreApplication::translate("Detail_Dialog", "Dialog", nullptr));
        detail_title->setText(QCoreApplication::translate("Detail_Dialog", "Titleeeee", nullptr));
        content->setText(QCoreApplication::translate("Detail_Dialog", "TextLabel", nullptr));
        broswer->setText(QCoreApplication::translate("Detail_Dialog", "Open in Browser", nullptr));
        closedetail->setText(QCoreApplication::translate("Detail_Dialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Detail_Dialog: public Ui_Detail_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAIL_DIALOG_H
