TEMPLATE = app

CONFIG += console
CONFIG += c++14
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L"/user/lib/x86_64-linux-gnu/"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

INCLUDEPATH += "/home/hugues/SFML/include"
DEPENDPATH += "/home/hugues/SFML/include"

SOURCES += main.cpp \
    appengine.cpp \
    entity.cpp \
    component.cpp \
    menustate.cpp \
    setupstate.cpp \
    statesystem.cpp \
    positioncomponent.cpp \
    spritecomponent.cpp \
    sprite.cpp \
    playstate.cpp

HEADERS += \
    appengine.h \
    entity.h \
    component.h \
    menustate.h \
    setupstate.h \
    statesystem.h \
    positioncomponent.h \
    spritecomponent.h \
    sprite.h \
    playstate.h
