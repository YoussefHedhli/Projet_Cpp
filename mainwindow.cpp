#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QInputDialog>
#include "fennetre1.h"
#include <QSqlQuery>
#include <QMessageBox>
#include "arduino.h"
#include <QThread>
#include <QSqlError>
#include <QTimer>
#include <QPainter>
#include "global.h"





MainWindow::MainWindow(::Arduino* a, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), Arduino(a)
{
    ui->setupUi(this);

    // If no Arduino is passed, don't initialize Arduino-related code
    if (Arduino == nullptr) {
        qDebug() << "No Arduino object passed.";
    }

    // Style for the password input
    ui->lineEdit_mdp->setPlaceholderText("  Mot de passe");
    ui->lineEdit_mdp->setStyleSheet("QLineEdit {"
                                  "font-family: 'Segoe UI', sans-serif; "
                                  "font-size: 14px; "
                                  "font-weight: 500; "
                                  "letter-spacing: 0.5px; "
                                  "color: #FFFFFF; "                        // White text for contrast
                                  "border: 1px solid #ADD8E6; "             // Light blue border for elegance
                                  "border-radius: 20px; "
                                  "padding: 5px; "
                                  "background-color: #1D3C6A; "             // Persian blue background
                                  "}"

                                  "QLineEdit::placeholder {"
                                  "color: #A9A9A9; "
                                  "font-style: italic;"
                                  "}");

    ui->lineEdit_mdp->setEchoMode(QLineEdit::Password);
    // Style for the email address input
    ui->lineEdit_email->setPlaceholderText("  Adresse mail");
    ui->lineEdit_email->setStyleSheet("QLineEdit {"
                                  "font-family: 'Segoe UI', sans-serif; "
                                  "font-size: 14px; "
                                  "font-weight: 500; "
                                  "letter-spacing: 0.5px; "
                                  "color: #FFFFFF; "                        // White text for contrast
                                  "border: 1px solid #ADD8E6; "             // Light blue border for elegance
                                  "border-radius: 20px; "
                                  "padding: 5px; "
                                  "background-color: #1D3C6A; "             // Persian blue background
                                  "}"

                                  "QLineEdit::placeholder {"
                                  "color: #A9A9A9; "
                                  "font-style: italic;"
                                  "}");
    fenetre1Window = new fennetre1(this);

    //serial = new QSerialPort(this);

    /*if (Arduino && Arduino->getserial()->isOpen()) {
        qDebug() << "Simulation: Using shared Arduino instance (connected).";
    } else {
        qDebug() << "Simulation: Arduino instance not connected.";
    }*/
    // Create and start the timer to call readSerial automatically
    QTimer *arduinoTimer = new QTimer(this);
    //connect(arduinoTimer, &QTimer::timeout, this, &MainWindow::readSerial);
   // arduinoTimer->start(100); // Check Arduino data every 100 ms


    // Adjust the port name, baud rate and other settings as needed
    //serial->setPortName("COM3"); // Change this to your actual port
    //connect(serial, &QSerialPort::readyRead, this, &MainWindow::readCardData);
    //connect(ui->pushButton_readCardData, &QPushButton::clicked, this, &MainWindow::pushButton_readCardData_clicked);
    //connect(ui->btnShowChart_3, &QPushButton::clicked, this, &fennetre1::on_btnShowChart_3_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete fenetre1Window;
}

/*void MainWindow::on_pushButton_login_clicked()
{
    // Here, you would validate the login, but for now, we just proceed to the next window

    // Hide the main window
    this->hide();

    // Show the second window (fennetre1)
    fenetre1Window->show();
}*/

void MainWindow::paintEvent(QPaintEvent *event) {
    // Create a QPainter object to draw on the window
    QPainter painter(this);

    // Load background image
    QPixmap pix("C:/Users/AMEN WORKSTATION/Desktop/projet/untitled/bg.jpg");
    if (pix.isNull()) {
        qDebug() << "Failed to load bg.jpg. Check the file path.";
    } else {
        // Scale the image to fit the entire window size
        pix = pix.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

        // Draw the background image directly on the window
        painter.drawPixmap(0, 0, pix);
    }

    // Optionally, you can also display the logo inside the label
    QPixmap logoPix("C:/Users/AMEN WORKSTATION/Desktop/projet/untitled/ball.png");
    if (!logoPix.isNull()) {
        // Use QLabel to display the logo and set it to fit inside the label's area
        ui->ball->setPixmap(logoPix.scaled(ui->ball->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->ball->show();  // Ensure the label is visible with the logo
    }

    // Call the parent class paintEvent to allow other painting to occur
    QMainWindow::paintEvent(event);
}
void MainWindow::on_pushButton_login_clicked()
{
    QString email = ui->lineEdit_email->text().trimmed();
    QString password = ui->lineEdit_mdp->text().trimmed();

    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    employe emp;
    if (emp.verifierAuthentification(email, password)) {
        // Role and email are already set globally in verifierAuthentification()

        // Optionally print for debug
        qDebug() << "Login success: " << CURRENT_USER_EMAIL << " with role " << CURRENT_USER_ROLE;

        // Open the main application window (fennetre1)
        this->hide();
        fennetre1 *window = new fennetre1();
        window->show();
    } else {
        QMessageBox::warning(this, "Erreur", "Email ou mot de passe incorrect.");
    }
}


void MainWindow::on_pushButton_mdp_oublie_clicked()
{
    // Get the email from the line edit
    QString email = ui->lineEdit_email->text().trimmed();

    // Check if the email field is empty
    if (email.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer votre email.");
        return;
    }

    // Verify if the email exists in the database using the employe class
    employe emp;
    if (!emp.emailExiste(email)) {
        QMessageBox::warning(this, "Erreur", "L'email n'existe pas.");
        return;
    }

    // If email exists, open the password reset window (fennetre2)
    this->hide();
    fennetre2 *resetWindow = new fennetre2(Arduino, email); // Pass email et Arduino to fennetre2
    resetWindow->show();
}



void MainWindow::checkEtatAndOpenDoor(const QString& email)
{
    QSqlQuery query;
    query.prepare("SELECT ETAT FROM GS_EMPLOYER WHERE EMAIL = :email");
    query.bindValue(":email", email);

    if (query.exec() && query.next()) {
        int etat = query.value(0).toInt();

        if (etat == 1) {
            // Send command to Arduino to open the door
            Arduino->write_to_arduino("open");

            qDebug() << "Door command sent to Arduino.";

            // Call the function to check if the door is closed and update ETAT in the database
            //readSerialAndUpdateEtat(email);  // Pass the email parameter to track the user
        } else {
            qDebug() << "Etat is not 1. Nothing to do.";
        }
    } else {
        qDebug() << "Erreur SQL:" << query.lastError().text();
    }
}

void MainWindow::checkEtatAndOpenDoorRFID(const QByteArray& cardData)
{
    qDebug() << "check RFID fonction.";
    // Convert QByteArray to QString for comparison with database
    QString password = QString::fromUtf8(cardData);

    QSqlQuery query;
    query.prepare("SELECT ETAT FROM GS_EMPLOYER WHERE MOT_DE_PASSE = :mdp");
    query.bindValue(":mdp", password);  // Use the password as a QString

    if (query.exec() && query.next()) {
        int etat = query.value(0).toInt();

        if (etat == 1) {
            // Send command to Arduino to open the door
            Arduino->write_to_arduino("open");

            qDebug() << "Door command sent to Arduino.";

            // Call the function to check if the door is closed and update ETAT in the database
            //readSerialAndUpdateEtat(email);  // Pass the email parameter to track the user
        } else {
            qDebug() << "Etat is not 1. Nothing to do.";
        }
    } else {
        qDebug() << "Erreur SQL:" << query.lastError().text();
    }
}

/*void MainWindow::readSerial()
{
    if (Arduino && Arduino->getserial()->isOpen())
    {
        QByteArray data = Arduino->read_from_arduino();

        if (!data.isEmpty())
        {
            qDebug() << "Received data from Arduino: " << data;

            QString keyPressed = QString::fromUtf8(data);
            keyPressed.replace(QRegularExpression("[\r\n]"), "");

            // Filter keypad vs RFID
            if (keyPressed != "CB49213" && keyPressed != "D575CC1")  // keypad char
            {
                QString currentText = ui->lineEdit_mdp->text();
                ui->lineEdit_mdp->setText(currentText + keyPressed);
            }
            else  // it's RFID
            {
                qDebug() << "RFID UID detected: " << keyPressed;
                QByteArray cardData = keyPressed.toUtf8();

                if (Arduino->check_card_password(cardData)) {
                    qDebug() << "RFID access granted!";
                    QString password = QString::fromUtf8(cardData);
                    QSqlQuery query;
                    query.prepare("UPDATE GS_EMPLOYER SET ETAT = 1 WHERE MOT_DE_PASSE = :mdp");
                    query.bindValue(":mdp", password);
                    if (!query.exec()) {
                        qDebug() << "Erreur lors de la mise à jour de l'état:" << query.lastError().text();
                    }
                    checkEtatAndOpenDoorRFID(cardData);  // Pass cardData to the function
                    query.prepare("UPDATE GS_EMPLOYER SET ETAT = 0 WHERE MOT_DE_PASSE = :mdp");
                    query.bindValue(":mdp", password);
                    if (!query.exec()) {
                        qDebug() << "Erreur lors de la mise à jour de l'état:" << query.lastError().text();
                    }
                    this->hide();
                    fennetre1 *window = new fennetre1();
                    window->show();
                } else {
                    qDebug() << "RFID access denied!";
                }
            }
        }
        else
        {
            qDebug() << "No data received from Arduino.";
        }
    }
}*/
