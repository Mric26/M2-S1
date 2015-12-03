#-------------------------------------------------
#
# Project created by QtCreator 2015-12-03T11:37:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Jeux-echec
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ia_alphabeta.cpp \
    pieces.cpp \
    plateau.cpp \
    caseplateau.cpp \
    roi.cpp \
    reine.cpp \
    fou.cpp \
    cavalier.cpp \
    tour.cpp \
    pion.cpp

HEADERS  += mainwindow.h \
    ia_alphabeta.h \
    pieces.h \
    plateau.h \
    caseplateau.h \
    roi.h \
    reine.h \
    fou.h \
    cavalier.h \
    tour.h \
    pion.h

FORMS    += mainwindow.ui
