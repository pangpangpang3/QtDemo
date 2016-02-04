QT       += core gui widgets x11extras

TARGET = lightdm-deepin-greeter-rootimage
TEMPLATE = app


CONFIG += c++11 link_pkgconfig dbus
PKGCONFIG += gsettings-qt
LIBS +=-lX11

SOURCES += main.cpp \
            rootimageapp.cpp
HEADERS  += \
            rootimageapp.h
