#-------------------------------------------------
#
# Project created by QtCreator 2016-12-19T18:47:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageButton_demo
TEMPLATE = app

CONFIG += c++11 link_pkgconfig
PKGCONFIG += x11 xext libexif dtkwidget dtkutil dtkbase

SOURCES += main.cpp\
        widget.cpp \
    imagebutton.cpp

HEADERS  += widget.h \
    imagebutton.h

RESOURCES += \
    resources.qrc
