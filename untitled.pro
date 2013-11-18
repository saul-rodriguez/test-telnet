#-------------------------------------------------
#
# Project created by QtCreator 2013-11-17T22:47:15
#
#-------------------------------------------------

QT       += core gui network
#QT += network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qttelnet.cpp

HEADERS  += mainwindow.h \
    qttelnet.h

FORMS    += mainwindow.ui
