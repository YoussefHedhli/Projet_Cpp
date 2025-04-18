#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "arduino.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool dbTest = c.createconnect();  // Test database connection

    // Create and connect an instance of the Arduino class
    Arduino* arduino = new Arduino;
    int arduinoTest = arduino->connect_arduino();

    if (arduinoTest == 0) {
        qDebug() << "Arduino connected successfully.";
    } else {
        qDebug() << "Failed to connect to Arduino.";
    }

    // Pass the connected Arduino to MainWindow
    MainWindow w(arduino);

    if (dbTest && arduinoTest == 0) {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("Database and Arduino are open"),
                                 QObject::tr("Connection successful to both database and Arduino.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    } else {
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

    int execResult = a.exec();
    delete arduino; // Free the memory
    return execResult;
}
