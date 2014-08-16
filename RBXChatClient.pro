#-------------------------------------------------
#
# Project created by QtCreator 2014-07-13T11:29:12
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
#QMAKESPEC=linux-g++-32 # Comment when on Windows


SOURCES += main.cpp\
        mainwindow.cpp \
    unpwdialog.cpp \
    registerdialog.cpp \
    activationcode.cpp

HEADERS  += mainwindow.h \
    unpwdialog.h \
    ui_mainwindow.h \
    registerdialog.h \
    activationcode.h \
    ui_activationcode.h

FORMS    += mainwindow.ui \
    unpwdialog.ui \
    registerdialog.ui \
    activationcode.ui
