#-------------------------------------------------
#
# Project created by QtCreator 2017-06-18T19:56:57
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SiO4
TEMPLATE = app

SOURCES += \
    main.cpp \
    sio4.cpp \
    includes.cpp \
    socket.cpp

HEADERS += \
    includes.h \
    sio4.h \
    socket.h

RESOURCES += \
    resources.qrc
