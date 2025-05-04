# Define the Qt modules needed
QT += core gui widgets sql  # Added "sql" to enable database support
QT += charts
QT += multimedia
QT += serialport
QT += printsupport


# Set the target name (output executable)
TARGET = my_project

# Define the project type
TEMPLATE = app

# Add source and header files
SOURCES += main.cpp \
    arduino.cpp \
    billet.cpp \
    calendar.cpp \
    connection.cpp \
    employe.cpp \
    equipe.cpp \
    fennetre1.cpp \
    fennetre2.cpp \
    global.cpp \
    gs_billet.cpp \
    gs_equipe.cpp \
    gs_match.cpp \
    mainwindow.cpp \
    match.cpp \
    simulation.cpp \
    sponsor.cpp \
    stadiumwidget.cpp

HEADERS += arduino.h \
    billet.h \
    calendar.h \
    connection.h \
    employe.h \
    equipe.h \
    fennetre1.h \
    fennetre2.h \
    global.h \
    gs_billet.h \
    gs_equipe.h \
    gs_match.h \
    mainwindow.h \
    match.h \
    simulation.h \
    sponsor.h \
    stadiumwidget.h

FORMS += calendar.ui \
    billet.ui \
    dialog.ui \  # Removed the comment to avoid parsing errors
    fennetre1.ui \
    fennetre2.ui \
    gs_billet.ui \
    gs_equipe.ui \
    gs_match.ui \
    mainwindow.ui \
    sponsor.ui

# Add the Qt resource file
RESOURCES += resources.qrc
