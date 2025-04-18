#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "arduino.h"  // Include the Arduino header

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;
    bool dbTest = c.createconnect();  // Test database connection

    // Create an instance of the Arduino class
    Arduino arduino;

    // Test Arduino connection
    int arduinoTest = arduino.connect_arduino();
    if (arduinoTest == 0) {
        qDebug() << "Arduino connected successfully.";
    } else {
        qDebug() << "Failed to connect to Arduino.";
    }

    if (dbTest && arduinoTest == 0) {
        // If both the database and Arduino connection are successful
        w.show();
        QMessageBox::information(nullptr, QObject::tr("Database and Arduino are open"),
                                 QObject::tr("Connection successful to both database and Arduino.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    } else {
        // Handle failure case for either database or Arduino connection
        QString errorMsg = "Connection failed.";
        if (!dbTest) {
            errorMsg += "\nDatabase connection failed.";
        }
        if (arduinoTest != 0) {
            errorMsg += "\nArduino connection failed.";
        }

        QMessageBox::critical(nullptr, QObject::tr("Connection Error"),
                              QObject::tr(qPrintable(errorMsg)),
                              QMessageBox::Cancel);
    }

    return a.exec();
}
