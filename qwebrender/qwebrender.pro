#-------------------------------------------------
#
# Project created by QtCreator 2012-04-12T21:50:01
#
#-------------------------------------------------

QT       += core gui network webkit xml

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

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libs/qxmlrpc_lib/ -lqxmlrpc
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libs/qxmlrpc_lib/ -lqxmlrpc
else:symbian: LIBS += -lqxmlrpc
else:unix: LIBS += -L$$PWD/../libs/qxmlrpc_lib/ -lqxmlrpc

INCLUDEPATH += $$PWD/../libs/qxmlrpc_lib
DEPENDPATH += $$PWD/../libs/qxmlrpc_lib

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libs/qxmlrpc_lib/qxmlrpc.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libs/qxmlrpc_lib/qxmlrpc.lib
else:unix:!symbian: PRE_TARGETDEPS += $$PWD/../libs/qxmlrpc_lib/libqxmlrpc.a
