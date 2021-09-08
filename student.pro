#-------------------------------------------------
#
# Project created by QtCreator 2021-08-31T15:43:20
#
#-------------------------------------------------

QT       += core gui
QT       += core gui multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = student
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    addstu.cpp \
    quersystu.cpp \
    about.cpp

HEADERS  += mainwindow.h \
    addstu.h \
    quersystu.h \
    about.h

FORMS    += mainwindow.ui \
    addstu.ui \
    quersystu.ui \
    about.ui

RESOURCES += \
    res.qrc
