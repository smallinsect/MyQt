#-------------------------------------------------
#
# Project created by QtCreator 2019-07-01T13:43:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = XEditor
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

INCLUDEPATH += F:/small-insect/Elements \
    C:/software/boost_1_49_0 \
    F:/small-insect/icee/IceE/cppe/include

SOURCES += main.cpp\
        MainWindow.cpp \
    SubText.cpp \
    DialogConnect.cpp \
    ContentForm.cpp \
    ClassView.cpp \
    ViewTree.cpp \
    NetArgConfig.cpp \
    PropertiesWnd.cpp

HEADERS  += MainWindow.h \
    SubText.h \
    DialogConnect.h \
    PrefixInclude.h \
    ContentForm.h \
    ClassView.h \
    ViewTree.h \
    NetArgConfig.h

FORMS    += MainWindow.ui \
    DialogConnect.ui \
    ContentForm.ui

RESOURCES += \
    res.qrc
