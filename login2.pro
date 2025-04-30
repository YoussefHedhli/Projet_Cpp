QT       += core gui

QT += core gui pdf

QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT       +=  sql

CONFIG += c++17

QT += network


QT += serialport

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connection.cpp \
    employe.cpp \
    fennetre1.cpp \
    fennetre2.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    arduino.h \
    connection.h \
    employe.h \
    fennetre1.h \
    fennetre2.h \
    mainwindow.h

FORMS += \
    fennetre1.ui \
    fennetre2.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
