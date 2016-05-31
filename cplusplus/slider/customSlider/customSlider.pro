#-------------------------------------------------
#
# Project created by QtCreator 2016-05-30T16:26:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = customSlider
TEMPLATE = app

CONFIG += c++11 link_pkgconfig
PKGCONFIG +=  dtkwidget dtkutil dtkbase

SOURCES += main.cpp\
        mainwindow.cpp \
    sliderwidget.cpp

HEADERS  += mainwindow.h \
    sliderwidget.h

RESOURCES += \
    resource.qrc
