#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "arduino.h" // Include your arduino class

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;

    bool db_ok = c.createconnect();

    // --- Arduino setup ---
    arduino ard;
    int arduino_status = ard.connect_arduino();

    if (!db_ok) {
        QMessageBox::critical(nullptr, QObject::tr("Database error"),
                              QObject::tr("Failed to connect to database.\n"), QMessageBox::Ok);
        return -1;
    }

    if (arduino_status == 0) {
        QMessageBox::information(nullptr, QObject::tr("Arduino Connected"),
                                 QObject::tr("Arduino connection successful.\n"
                                             "Port: %1").arg(ard.getarduino_port_name()), QMessageBox::Ok);
    } else if (arduino_status == 1) {
        QMessageBox::warning(nullptr, QObject::tr("Arduino Not Found"),
                             QObject::tr("Arduino detected but failed to open port."), QMessageBox::Ok);
    } else {
        QMessageBox::warning(nullptr, QObject::tr("Arduino Not Connected"),
                             QObject::tr("Arduino not available or not connected.\n"
                                         "Check USB connection and try again."), QMessageBox::Ok);
    }

    w.show();
    return a.exec();
}
