#-------------------------------------------------
#
# Project created by QtCreator 2015-12-03T11:37:58
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += -std=gnu++11 \

TARGET = Jeux-echec
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ia_alphabeta.cpp \
    pieces.cpp \
    plateau.cpp \
    roi.cpp \
    reine.cpp \
    fou.cpp \
    cavalier.cpp \
    tour.cpp \
    pion.cpp \
    coup.cpp \
    casePlateau.cpp

HEADERS  += mainwindow.h \
    ia_alphabeta.h \
    pieces.h \
    plateau.h \
    roi.h \
    reine.h \
    fou.h \
    cavalier.h \
    tour.h \
    pion.h \
    coup.h \
    casePlateau.h

FORMS    += mainwindow.ui

RESOURCES += \
    ressources.qrc
