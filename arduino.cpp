#include "arduino.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QMessageBox>   




arduino::arduino()
{
    data="";
    arduino_port_name="";
    arduino_is_available=false;
    serial=new QSerialPort;
}






QString arduino::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *arduino::getserial()
{
    return serial;
}
int arduino::connect_arduino()
{   // recherche du port sur lequel la carte arduino identifée par  arduino_uno_vendor_id
    // est connectée
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()){
        if(serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()){
            if(serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier()
                                                                                    == arduino_uno_producy_id) {
                arduino_is_available = true;
                arduino_port_name=serial_port_info.portName();
            } } }
    qDebug() << "arduino_port_name is :" << arduino_port_name;
    if(arduino_is_available){ // configuration de la communication ( débit...)
        serial->setPortName(arduino_port_name);
        if(serial->open(QSerialPort::ReadWrite)){
            serial->setPortName("COM3");
            serial->setBaudRate(QSerialPort::Baud9600); // débit : 9600 bits/s
            serial->setDataBits(QSerialPort::Data8); //Longueur des données : 8 bits,
            serial->setParity(QSerialPort::NoParity); //1 bit de parité optionnel
            serial->setStopBits(QSerialPort::OneStop); //Nombre de bits de stop : 1
            serial->setFlowControl(QSerialPort::NoFlowControl);
            return 0;
        }
        return 1;
    }
    return -1;
}

int arduino::close_arduino()

{

    if(serial->isOpen()){
        serial->close();
        return 0;
    }
    return 1;


}


QByteArray arduino::read_from_arduino()
{
    if(serial->isReadable()){
        data=serial->readAll(); //récupérer les données reçues

        return data;
    }
}


void arduino::write_to_arduino( QByteArray d)

{

    if(serial->isWritable()){
        serial->write(d);  // envoyer des donnés vers Arduino
    }else{
        qDebug() << "Couldn't write to serial!";
    }


}


bool arduino::check_card_password(const QByteArray &cardData)
{
    if (!serial->isOpen()) {
        QMessageBox::warning(nullptr, "Error", "Serial port not open!");
        return false;
    }

    // Query the database to check for a match
    QSqlQuery query;
    query.prepare("SELECT * FROM GS_EMPLOYER WHERE MOT_DE_PASSE = :cardPassword");
    query.bindValue(":cardPassword", QString(cardData));  // Bind the card data to the query

    if (!query.exec()) {
        QMessageBox::warning(nullptr, "Error", "Error checking card data in DB: " + query.lastError().text());
        return false;
    }

    // Check if there is a match
    if (query.next()) {
        QMessageBox::information(nullptr, "Password Match", "Password match found for employee: " + query.value("EMAIL").toString());
        return true;  // The card password is authenticated successfully
    } else {
        QMessageBox::warning(nullptr, "Error", "No matching password found in database.");
        return false;  // Card data does not match any password in the database
    }
}
