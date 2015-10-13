#-------------------------------------------------
#
# Project created by QtCreator 2015-10-11T17:26:29
#
#-------------------------------------------------

QT       += core gui

QMAKE_CXXFLAGS += -std=c++0x

INCLUDEPATH += /usr/include/libusb-1.0/
LIBS += -lusb-1.0

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = k40
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
