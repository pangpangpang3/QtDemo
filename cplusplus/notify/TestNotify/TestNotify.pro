#-------------------------------------------------
#
# Project created by QtCreator 2017-06-01T14:54:15
#
#-------------------------------------------------

QT       += core gui dbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestNotify
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dbusnotify.cpp

HEADERS  += mainwindow.h \
    dbusnotify.h
