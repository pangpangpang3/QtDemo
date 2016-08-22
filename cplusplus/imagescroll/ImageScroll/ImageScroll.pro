#-------------------------------------------------
#
# Project created by QtCreator 2016-08-01T16:44:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ImageScroll
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    scrollarea.cpp \
    imagewidget.cpp

HEADERS  += widget.h \
    scrollarea.h \
    imagewidget.h

RESOURCES += \
    resource.qrc

DISTFILES += \
    ImageScroll.pro.user
