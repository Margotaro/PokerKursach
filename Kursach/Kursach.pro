QT += core
QT -= gui

CONFIG += c++11

TARGET = Kursach
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    card.cpp \
    carddesk.cpp \
    player.cpp \
    game.cpp \
    flashroyale.cpp \
    detectcombination.cpp \
    combination.cpp \
    straightflush.cpp \
    fourofakind.cpp \
    fullhouse.cpp \
    flush.cpp \
    straight.cpp \
    set.cpp \
    twopair.cpp \
    onepair.cpp \
    highcard.cpp \
    ai.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    card.h \
    carddesk.h \
    player.h \
    game.h \
    flashroyale.h \
    detectcombination.h \
    combination.h \
    straightflush.h \
    fourofakind.h \
    fullhouse.h \
    flush.h \
    straight.h \
    set.h \
    twopair.h \
    onepair.h \
    highcard.h \
    ai.h
