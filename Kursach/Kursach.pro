QT += core gui widgets printsupport

CONFIG += c++11

TARGET = Kursach
CONFIG += console

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
    ai.cpp \
    mainwindow.cpp \
    you.cpp \
    table.cpp

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
    ai.h \
    mainwindow.h \
    you.h \
    table.h

RESOURCES += \
    cardimages.qrc

DISTFILES += \
    ../PekorCards/C2.png \
    ../PekorCards/C3.png \
    ../PekorCards/C4.png \
    ../PekorCards/C5.png \
    ../PekorCards/C6.png \
    ../PekorCards/C7.png \
    ../PekorCards/C8.png \
    ../PekorCards/C9.png \
    ../PekorCards/C10.png \
    ../PekorCards/C11.png \
    ../PekorCards/C12.png \
    ../PekorCards/C13.png \
    ../PekorCards/C14.png \
    ../PekorCards/D2.png \
    ../PekorCards/D3.png \
    ../PekorCards/D4.png \
    ../PekorCards/D5.png \
    ../PekorCards/D6.png \
    ../PekorCards/D7.png \
    ../PekorCards/D8.png \
    ../PekorCards/D9.png \
    ../PekorCards/D10.png \
    ../PekorCards/D11.png \
    ../PekorCards/D12.png \
    ../PekorCards/D13.png \
    ../PekorCards/D14.png \
    ../PekorCards/H2.png \
    ../PekorCards/H3.png \
    ../PekorCards/H4.png \
    ../PekorCards/H5.png \
    ../PekorCards/H6.png \
    ../PekorCards/H7.png \
    ../PekorCards/H8.png \
    ../PekorCards/H9.png \
    ../PekorCards/H10.png \
    ../PekorCards/H11.png \
    ../PekorCards/H12.png \
    ../PekorCards/H13.png \
    ../PekorCards/H14.png \
    ../PekorCards/S2.png \
    ../PekorCards/S3.png \
    ../PekorCards/S4.png \
    ../PekorCards/S5.png \
    ../PekorCards/S6.png \
    ../PekorCards/S7.png \
    ../PekorCards/S8.png \
    ../PekorCards/S9.png \
    ../PekorCards/S10.png \
    ../PekorCards/S11.png \
    ../PekorCards/S12.png \
    ../PekorCards/S13.png \
    ../PekorCards/S14.png

FORMS += \
    mainwindow.ui
