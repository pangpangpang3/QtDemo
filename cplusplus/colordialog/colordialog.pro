#-------------------------------------------------
#
# Project created by QtCreator 2017-07-21T10:32:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = colordialog
TEMPLATE = app

CONFIG += c++11 link_pkgconfig

SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

RESOURCES += \
    res.qrc
