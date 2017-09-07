#-------------------------------------------------
#
# Project created by QtCreator 2017-08-01T13:08:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = multi-screens
TEMPLATE = app

CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkcore dtkwidget dtkwm

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h
