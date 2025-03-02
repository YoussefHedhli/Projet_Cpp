# Define the Qt modules needed
QT += core gui widgets sql  # Added "sql" to enable database support

# Set the target name (output executable)
TARGET = my_project

# Define the project type
TEMPLATE = app

# Add source and header files
SOURCES += main.cpp mainwindow.cpp \
    calendar.cpp \
    connection.cpp \
    match.cpp

HEADERS += mainwindow.h \
    calendar.h \
    connection.h \
    match.h

FORMS += mainwindow.ui \
    calendar.ui \
    dialog.ui  # Removed the comment to avoid parsing errors

# Add the Qt resource file
RESOURCES += resources.qrc
