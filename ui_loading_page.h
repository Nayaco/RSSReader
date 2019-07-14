/********************************************************************************
** Form generated from reading UI file 'loading_page.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOADING_PAGE_H
#define UI_LOADING_PAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_loading_page
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;

    void setupUi(QWidget *loading_page)
    {
        if (loading_page->objectName().isEmpty())
            loading_page->setObjectName(QString::fromUtf8("loading_page"));
        loading_page->resize(555, 414);
        verticalLayout = new QVBoxLayout(loading_page);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 1);

        widget = new QWidget(loading_page);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMinimumSize(QSize(300, 300));

        gridLayout_2->addWidget(widget, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 2, 1, 1, 1);

        label = new QLabel(loading_page);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        retranslateUi(loading_page);

        QMetaObject::connectSlotsByName(loading_page);
    } // setupUi

    void retranslateUi(QWidget *loading_page)
    {
        loading_page->setWindowTitle(QCoreApplication::translate("loading_page", "Form", nullptr));
        label->setText(QCoreApplication::translate("loading_page", "RSSReader", nullptr));
    } // retranslateUi

};

namespace Ui {
    class loading_page: public Ui_loading_page {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOADING_PAGE_H
