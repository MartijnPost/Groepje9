#-------------------------------------------------
#
# Project created by QtCreator 2014-11-10T17:25:07
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
win32:RC_ICONS += Logo.ico

TARGET = Begin
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    invoegscherm.cpp \
    resultatenscherm.cpp \
    tekenveld.cpp \
    knoop.cpp \
    graaf.cpp \
    tak.cpp

HEADERS  += mainwindow.h \
    invoegscherm.h \
    resultatenscherm.h \
    tekenveld.h \
    knoop.h \
    graaf.h \
    tak.h

FORMS    += mainwindow.ui \
    invoegscherm.ui \
    resultatenscherm.ui

