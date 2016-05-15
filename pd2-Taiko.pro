#-------------------------------------------------
#
# Project created by QtCreator 2016-05-04T11:42:55
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pd2-Taiko
TEMPLATE = app


SOURCES += main.cpp \
    Note.cpp \
    Taiko.cpp \
    Score.cpp \
    TimeBar.cpp \
    HighNote.cpp \
    LowNote.cpp \
    TaikoGame.cpp

HEADERS  += \
    Note.h \
    Taiko.h \
    Score.h \
    TimeBar.h \
    HighNote.h \
    LowNote.h \
    TaikoGame.h

FORMS    +=

DISTFILES +=

RESOURCES += \
    res.qrc
