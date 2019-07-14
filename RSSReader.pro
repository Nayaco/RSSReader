#-------------------------------------------------
#
# Project created by QtCreator 2019-07-06T16:45:20
#
#-------------------------------------------------

QT += core gui designer uitools network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bin/RSSReader
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17

SOURCES += \
        app/articles/articles.cpp \
        app/details/detail_dialog.cpp \
        app/loading/loading.cpp \
        app/loading/loading_page.cpp \
        app/mainwindow.cpp \
        app/main.cpp \
        view/mainwindow/mainwindowsink.cpp\
        view/ctimer/ctimer.cpp\
        parser/channel.cpp\
        parser/item.cpp\
        parser/RSSparser.cpp\
        request/request.cpp\
        model/model.cpp\
        model/sink/modelsink.cpp\
        model/crequest/crequest.cpp\
        model/irequest/irequest.cpp\
        externalLib/tinyxml2.cpp\
        middlelayer/viewmodel.cpp

HEADERS += \
        app/articles/articles.h \
        app/articles/articletype.h \
        app/details/detail_dialog.h \
        app/loading/loading.h \
        app/loading/loading_page.h \
        app/mainwindow.h \
        app/main.h \
        common/common.h \
        common/middleware.h \
        common/property.h \
        view/mainwindow/mainwindowsink.h \
        view/sink/viewsink.h \
        view/ctimer/ctimer.h \
        parser/channel.h \
        parser/item.h \
        parser/RSSparser.h \
        request/request.h \
        model/model.h \
        model/sink/modelsink.h \
        model/crequest/crequest.h \
        model/irequest/irequest.h \
        externalLib/tinyxml2.h \
        middlelayer/viewmodel.h

FORMS += \
        app/details/detail_dialog.ui \
        app/loading/loading_page.ui \
        app/mainwindow.ui

RESOURCES += \
        app/qdarkstyle/style.qrc\
        images/images.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
