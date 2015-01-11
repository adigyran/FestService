#-------------------------------------------------
#
# Project created by QtCreator 2015-01-07T06:54:25
#
#-------------------------------------------------

QT       += core gui network multimedia multimediawidgets quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FestService
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    network_serv.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    network_serv.h

FORMS    += mainwindow.ui \
    logindialog.ui

include(QZXing/QZXing.pri)

RESOURCES += \
    img/qrsamp.qrc

DISTFILES += \
    img/qr-code.jpg \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/AndroidManifest.xml \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
