#-------------------------------------------------
#
# Project created by QtCreator 2016-12-01T10:37:15
#
#-------------------------------------------------

QT += core
QT -= gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mountdevice_demo
TEMPLATE = app

CONFIG +=c++11

CONFIG += console
CONFIG -= app_bundle



SOURCES += main.cpp \
    volumemonitor.cpp

HEADERS  += \
    volumemonitor.h
