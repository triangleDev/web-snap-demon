

QT +=webkit network

TEMPLATE = app

TARGET = webcapture

SOURCES = main.cpp \
    webcapture.cpp \
    webpage.cpp

HEADERS += \
    webcapture.h \
    webpage.h

unix {
    OBJECTS_DIR = ./obj/
    MOC_DIR = ./obj/
    DESTDIR = ./bin/
    UI_DIR = ./obj/
}

