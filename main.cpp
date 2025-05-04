#include "mainwindow.h"  // Include MainWindow (authentication)
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
// #include "arduino.h"  // Arduino code is disabled

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool dbTest = c.createconnect();  // Test database connection

    // // Create and connect an instance of the Arduino class
    // Arduino* Arduino = new ::Arduino;
    // int arduinoTest = Arduino->connect_arduino();

    // if (arduinoTest == 0) {
    //     qDebug() << "Arduino connected successfully.";
    // } else {
    //     qDebug() << "Failed to connect to Arduino.";
    // }

    // Show MainWindow (authentication) first
    MainWindow w(nullptr);  // Pass nullptr since Arduino is disabled

    if (dbTest /* && arduinoTest == 0 */) {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("Connection Successful"),
                                 QObject::tr("Database connected successfully."),
                                 QMessageBox::Ok);
    } else {
        QString errorMsg = "Connection failed.";
        if (!dbTest) errorMsg += "\nDatabase connection failed.";
        // if (arduinoTest != 0) errorMsg += "\nArduino connection failed.";

        QMessageBox::critical(nullptr, QObject::tr("Connection Error"),
                              QObject::tr(qPrintable(errorMsg)),
                              QMessageBox::Cancel);
    }

    int execResult = a.exec();
    // delete Arduino; // Clean up Arduino (disabled)
    return execResult;
}
