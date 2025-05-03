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
    equipe.cpp \
    gs_billet.cpp \
    gs_equipe.cpp \
    gs_match.cpp \
    match.cpp \
    simulation.cpp \
    sponsor.cpp \
    stadiumwidget.cpp

HEADERS += arduino.h \
    billet.h \
    calendar.h \
    connection.h \
    equipe.h \
    gs_billet.h \
    gs_equipe.h \
    gs_match.h \
    match.h \
    simulation.h \
    sponsor.h \
    stadiumwidget.h

FORMS += calendar.ui \
    billet.ui \
    dialog.ui \  # Removed the comment to avoid parsing errors
    gs_billet.ui \
    gs_equipe.ui \
    gs_match.ui \
    sponsor.ui

# Add the Qt resource file
RESOURCES += resources.qrc
