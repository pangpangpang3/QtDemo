#-------------------------------------------------
#
# Project created by QtCreator 2017-01-22T17:23:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dwindow
TEMPLATE = app

CONFIG += c++11 link_pkgconfig
PKGCONFIG += x11 xext libexif dtkwidget dtkutil dtkbase

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

RESOURCES += \
    image.qrc
