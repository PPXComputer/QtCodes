# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = tomato
DESTDIR = ../x64/Debug
QT += core gui multimedia uitools widgets multimediawidgets charts
CONFIG += debug
DEFINES += _UNICODE WIN64 QT_DLL QT_CHARTS_LIB QT_MULTIMEDIA_LIB QT_MULTIMEDIAWIDGETS_LIB QT_UITOOLS_LIB QT_WIDGETS_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/$(ConfigurationName)
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/$(ConfigurationName)
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
UI_DIR=./UI
include(tomato.pri)
win32:RC_FILE = tomato.rc
