#-------------------------------------------------
#
# Project created by QtCreator 2015-09-16T14:52:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ColorTransplant
TEMPLATE = app
CONFIG +=c++11

SOURCES += main.cpp\
        widget.cpp \
    dbreathinglabel.cpp

HEADERS  += widget.h \
    dbreathinglabel.h

RESOURCES += \
    image.qrc
