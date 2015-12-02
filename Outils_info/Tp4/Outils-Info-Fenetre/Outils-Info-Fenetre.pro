#-------------------------------------------------
#
# Project created by QtCreator 2015-11-30T12:04:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=gnu++11\

TARGET = Outils-Info-Fenetre
TEMPLATE = app

LIBS+= -lpython2.7\


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
