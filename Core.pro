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
    CORE/Components/position.cpp \
    CORE/Components/sprite.cpp \
    CORE/Components/state.cpp \
    CORE/Components/velocity.cpp \
    CORE/Systems/movement.cpp \
    CORE/appengine.cpp \
    CORE/block.cpp \
    CORE/entity.cpp \
    CORE/States/play.cpp \
    CORE/States/pause.cpp

HEADERS += \
    CORE/component.h \
    CORE/Components/position.h \
    CORE/Components/sprite.h \
    CORE/Components/state.h \
    CORE/Components/velocity.h \
    CORE/appengine.h \
    CORE/block.h \
    CORE/entity.h \
    CORE/States/play.h \
    CORE/States/pause.h \
    CORE/Systems/movement.h
