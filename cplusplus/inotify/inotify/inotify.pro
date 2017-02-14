#-------------------------------------------------
#
# Project created by QtCreator 2017-01-16T10:54:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = inotify
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    inotifyengine.cpp

HEADERS  += widget.h \
    inotifyengine.h
