#-------------------------------------------------
#
# Project created by QtCreator 2015-12-01T13:13:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = frameArrow
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

PKGCONFIG +=dui
CONFIG += c++11 link_pkgconfig
