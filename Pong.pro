#-------------------------------------------------
#
# Project created by QtCreator 2016-05-18T16:59:40
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pong
TEMPLATE = app


SOURCES += main.cpp \
    ball.cpp \
    ai.cpp \
    player.cpp \
    game.cpp \
    score.cpp \
    countdown.cpp

HEADERS  += \
    ball.h \
    ai.h \
    player.h \
    game.h \
    score.h \
    countdown.h

RESOURCES += \
    resource.qrc
