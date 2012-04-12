#-------------------------------------------------
#
# Project created by QtCreator 2012-04-12T21:50:01
#
#-------------------------------------------------

QT       += core gui network webkit

TARGET = qwebrender
TEMPLATE = app


unix{
  OBJECTS_DIR = ./obj/
  MOC_DIR = ./obj/
  DESTDIR = ../bin/
  UI_DIR = ./obj/
  QMAKE_LFLAGS += -Wl,--rpath=../bin/
  QMAKE_LFLAGS_RPATH=
}

SOURCES += main.cpp \
    demon.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../bin/release/ -lQWebRender
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../bin/debug/ -lQWebRender
else:symbian: LIBS += -lQWebRender
else:unix: LIBS += -L$$PWD/../bin/ -lQWebRender

INCLUDEPATH += $$PWD/../libs/QWebRender
DEPENDPATH += $$PWD/../libs/QWebRender

HEADERS += \
    demon.h
