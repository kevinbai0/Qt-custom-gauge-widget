#-------------------------------------------------
#
# Project created by QtCreator 2014-11-08T02:11:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SpeedGauge
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../../source/qcgaugewidget.cpp \
    speedgauge.cpp

HEADERS  += mainwindow.h \
    ../../source/qcgaugewidget.h \
    speedgauge.h

FORMS    += mainwindow.ui

