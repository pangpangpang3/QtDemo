#-------------------------------------------------
#
# Project created by QtCreator 2015-07-14T15:10:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Group
TEMPLATE = app


SOURCES += main.cpp \
    item.cpp \
    elidedlabel.cpp \
    desktopframe.cpp \
    arrowrectangle.cpp

HEADERS  += \
    item.h \
    elidedlabel.h \
    desktopframe.h \
    arrowrectangle.h

RESOURCES += \
    skin.qrc

DISTFILES +=

CONFIG+=c++11
