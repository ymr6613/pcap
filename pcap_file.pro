#-------------------------------------------------
#
# Project created by QtCreator 2017-11-15T22:48:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pcap_file
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    packet.cpp

HEADERS  += mainwindow.h \
    packet.h \
    form.h

FORMS    += mainwindow.ui \
    packet.ui
