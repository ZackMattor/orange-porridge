#-------------------------------------------------
#
# Project created by QtCreator 2013-10-27T00:04:24
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = orange-porridge
CONFIG   -= app_bundle

TEMPLATE = app

unix {
    CONFIG += console
    LIBS += -L/usr/local/lib -lallegro
}

SOURCES += main.cpp \
    engine.cpp \
    gameManager.cpp

HEADERS += \
    globals.h \
    engine.h \
    gameManager.h
