#-------------------------------------------------
#
# Project created by QtCreator 2015-11-11T10:35:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ReconocimientoRostros
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h \
    cvimagewidget.h

FORMS    += mainwindow.ui

LIBS += -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_objdetect -lopencv_contrib
