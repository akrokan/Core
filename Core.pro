TEMPLATE = app

CONFIG += console
CONFIG += c++14
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -L"/user/lib/x86_64-linux-gnu/"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system

INCLUDEPATH += "/home/hugues/SAFML/include"
DEPENDPATH += "/home/hugues/SAFML/include"

SOURCES += main.cpp \
    src/appengine.cpp \
    src/entity.cpp \
    src/menustate.cpp \
    src/playstate.cpp \
    src/sprite.cpp \
    src/csprite.cpp \
    src/position.cpp

HEADERS += \
    include/appengine.h \
    include/component.h \
    include/entity.h \
    include/menustate.h \
    include/playstate.h \
    include/sprite.h \
    include/statesystem.h \
    include/Components/position.h \
    include/Components/sprite.h
