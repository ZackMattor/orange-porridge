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
    INCLUDEPATH += /home/zmattor/Projects/libs/SFML-2.1-build/include
    LIBS += -L/home/zmattor/Projects/libs/SFML-2.1-build/lib -lallegro -lallegro_ttf -lallegro_font -lallegro_primitives -lsfml-graphics -lsfml-window -lsfml-system
}

SOURCES += main.cpp \
    engine.cpp \
    gameManager.cpp \
    menu.cpp \
#    elements/allegrotextbox.cpp \
    elements/allegrobutton.cpp \
#    helpers/starfield.h \
#    helpers/starfield.cpp

HEADERS += \
    globals.h \
    engine.h \
    gameManager.h \
    menu.h \
#    elements/allegrotextbox.h \
    elements/allegrobutton.h
