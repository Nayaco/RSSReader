#-------------------------------------------------
#
# Project created by QtCreator 2019-07-06T16:45:20
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bin/testModel
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
        tests/testModel.cpp\
        parser/channel.cpp\
        parser/item.cpp\
        parser/RSSparser.cpp\
        request/request.cpp\
        model/model.cpp\
        model/sink/modelsink.cpp\
        model/crequest/crequest.cpp\
        externalLib/tinyxml2.cpp\
        middlelayer/viewmodel.cpp\
        view/ctimer/ctimer.cpp

HEADERS += \
        tests/testModel.h\
        parser/channel.h\
        parser/item.h\
        parser/RSSparser.h\
        request/request.h\
        model/model.h\
        model/sink/modelsink.h\
        model/crequest/crequest.h\
        externalLib/tinyxml2.h\
        common/common.h\
        common/middleware.h\
        common/property.h\
        middlelayer/viewmodel.h\
        view/ctimer/ctimer.h\
        view/sink/viewsink.h

FORMS += \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
