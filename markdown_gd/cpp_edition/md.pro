#-------------------------------------------------
#
# Project created by QtCreator 2014-12-07T00:17:52
#
#-------------------------------------------------

QT       += core gui
QT      +=  webkitwidgets network widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = md
TEMPLATE = app



SOURCES += parse.cpp\
    md.cpp \
    main.cpp

HEADERS  +=  parse.h \
    md.h \
    common.h



FORMS    += md.ui

RESOURCES += \
    file.qrc
