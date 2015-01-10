#-------------------------------------------------
#
# Project created by QtCreator 2015-01-07T06:54:25
#
#-------------------------------------------------

QT       += core gui network multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FestService
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

include(QZXing/QZXing.pri)

RESOURCES += \
    img/qrsamp.qrc

DISTFILES += \
    img/qr-code.jpg
