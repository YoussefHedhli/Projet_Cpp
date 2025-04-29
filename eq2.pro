QT       += core gui
QT       += core gui sql
QT += core gui charts
QT += core gui sql charts widgets

QT += network

QT += serialport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connetion.cpp \
    equipe.cpp \
    gs_equipe.cpp \
    main.cpp

HEADERS += \
    arduino.h \
    connetion.h \
    equipe.h \
    gs_equipe.h


FORMS += \
    gs_equipe.ui
    TEMPLATE = app
    TARGET = berasmiwoh

    greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
