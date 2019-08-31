#-------------------------------------------------
#
# Project created by QtCreator 2019-04-19T11:37:50
#
#-------------------------------------------------

QT       += core gui
QT += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_painter
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mydraw.cpp

HEADERS  += mainwindow.h \
    mydraw.h

FORMS    += mainwindow.ui

RESOURCES += \
    image.qrc

DISTFILES +=
