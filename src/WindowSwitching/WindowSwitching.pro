#-------------------------------------------------
#
# Project created by QtCreator 2019-07-01T09:24:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WindowSwitching
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        Widget.cpp \
    Form01.cpp \
    Form02.cpp \
    Form03.cpp

HEADERS  += Widget.h \
    Form01.h \
    Form02.h \
    Form03.h

FORMS    += Widget.ui \
    Form01.ui \
    Form02.ui \
    Form03.ui
