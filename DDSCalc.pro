#-------------------------------------------------
#
# Project created by QtCreator 2016-01-30T23:52:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DDSCalc
TEMPLATE = app

LIBS+=-L/usr/local/lib


SOURCES += main.cpp\
        ddscalc.cpp\
        dds.cpp

HEADERS += ddscalc.h\
        dds.h

FORMS    += ddscalc.ui
