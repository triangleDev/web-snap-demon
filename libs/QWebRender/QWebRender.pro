#-------------------------------------------------
#
# Project created by QtCreator 2012-04-12T21:54:51
#
#-------------------------------------------------

QT       += network webkit gui


unix{
  OBJECTS_DIR = ./obj/
  MOC_DIR = ./obj/
  DESTDIR = ../../bin/
  UI_DIR = ./obj/
}
INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

TARGET = QWebRender
TEMPLATE = lib

DEFINES += QWEBRENDER_LIBRARY

SOURCES += qwebrender.cpp \
    webpage.cpp \
    webcapture.cpp

HEADERS += qwebrender.h\
        QWebRender_global.h \
    webpage.h \
    webcapture.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEED7E8E5
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = QWebRender.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
