#-------------------------------------------------
#
# Project created by QtCreator 2013-08-05T16:00:25
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = qPi
TEMPLATE = app
SOURCES += \
    ./src/scatter.cpp \
    ./src/plotter.cpp \
    ./src/mcpi.cpp \
    ./src/mainwindow.cpp \
    ./src/main.cpp \
    ./src/gui.cpp
HEADERS  += \
    ./src/scatter.h \
    ./src/plotter.h \
    ./src/mcpi.h \
    ./src/mainwindow.h \
    ./src/gui.h
#LIBS += -lgsl \
#   -lgslcblas \
#    -L/usr/local/lib
#    -static

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += \
    android/AndroidManifest.xml \
    src/fig/circ_quad.png
