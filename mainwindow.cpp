#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QInputDialog>
#include "fennetre1.h"
#include <QSqlQuery>
#include <QMessageBox>
#include "arduino.h"
#include <QThread>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("E:/esprit-info/2éme année/semestre2/projet C++/background.jpg");
    ui->label_picc->setPixmap(pix.scaled(900,1000,Qt::KeepAspectRatio));



    QPixmap pix2("E:/esprit-info/2éme année/semestre2/projet C++/member-icon-png-0-removebg-preview.png");
    ui->label_login_img->setPixmap(pix2.scaled(100,100,Qt::KeepAspectRatio));

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

    serial = new QSerialPort(this);

    // Adjust the port name, baud rate and other settings as needed
    //serial->setPortName("COM3"); // Change this to your actual port
    //connect(serial, &QSerialPort::readyRead, this, &MainWindow::readCardData);
    connect(ui->pushButton_readCardData, &QPushButton::clicked, this, &MainWindow::pushButton_readCardData_clicked);
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

void MainWindow::on_pushButton_login_clicked()
{
    // Get email and password from the line edits
    QString email = ui->lineEdit_email->text().trimmed();
    QString password = ui->lineEdit_mdp->text().trimmed();

    // Check if both fields are not empty
    if (email.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    // Create an instance of the employe class and check authentication
    employe emp;
    if (emp.verifierAuthentification(email, password)) {
        // Authentication successful, hide the login window and show the next window
        this->hide();
        fennetre1 *window = new fennetre1();
        window->show();
    } /*else {
        // Authentication failed
        QMessageBox::warning(this, "Erreur", "Email ou mot de passe incorrect.");
    }*/
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
    fennetre2 *resetWindow = new fennetre2(email);  // Pass email to fennetre2
    resetWindow->show();
}


/*void MainWindow::on_btn_voice_login_clicked()
{
    employe e;
    QString modelPath = "E:\esprit-info\2éme année\semestre2\projet C++\login\vosk-model-small-fr-0.22"; // Path to your Vosk model
    QString motDePasseReconnu = e.reconnaitreMotDePasseParVoix(modelPath);

    qDebug() << "Mot de passe reconnu :" << motDePasseReconnu;

    if (e.verifierMotDePasseVoix(motDePasseReconnu)) {
        QMessageBox::information(this, "Succès", "Authentification vocale réussie !");
        // TODO: redirect to main menu or dashboard
    } else {
        QMessageBox::warning(this, "Échec", "Mot de passe incorrect !");
    }
}*/

void MainWindow::pushButton_readCardData_clicked()
{
    QByteArray data;

    // Clear any existing data in the serial buffer
    serial->clear();

    // Ensure we wait for data to arrive within 7 seconds using a loop and checking periodically
    qint64 startTime = QDateTime::currentMSecsSinceEpoch();
    const qint64 timeout = 7000;  // 7 seconds timeout

    // Keep checking until data is ready or the timeout is reached
    while (QDateTime::currentMSecsSinceEpoch() - startTime < timeout) {
        if (serial->bytesAvailable() > 0) {
            // If data is available, read it
            //data = serial->readAll();
            QByteArray rawData = serial->readAll();
            qDebug() << "Raw Data: " << rawData;
            break;
        }
        QThread::msleep(50);  // Sleep for 50 ms to avoid busy-waiting and consume less CPU
    }

    // Check if data was received
    if (data.isEmpty()) {
        QMessageBox::warning(this, "Error", "Timeout waiting for card data.");
        return;
    }

    // Print the raw data for debugging
    QString rawData = QString(data.toHex());  // Convert to hex for easier debugging
    QMessageBox::information(this, "Raw Data", "Raw data from RFID reader: " + rawData);

    // Check if the length of the data matches what you expect (16 bytes)
    if (data.size() == 16) {
        QMessageBox::information(this, "Data Length", "Card data length is correct (16 bytes).");

        // Strip any extra spaces from the data (since the card has trailing spaces)
        QString cardDataString = QString(data);  // Convert QByteArray to QString
        cardDataString = cardDataString.trimmed();  // Remove any leading or trailing spaces

        // Print the trimmed data for debugging
        QMessageBox::information(this, "Trimmed Data", "Trimmed card data: " + cardDataString);

        // Pass the cleaned card data (without spaces) for authentication check
        arduino arduinoObj;  // Create an instance of the arduino class
        bool isAuthenticated = arduinoObj.check_card_password(cardDataString.toUtf8());  // Pass cleaned card data

        if (isAuthenticated) {
            // If the authentication is successful, hide MainWindow and show fennetre1
            QMessageBox::information(this, "Success", "Card authentication successful!");
            this->hide();  // Hide the current window (MainWindow)
            fennetre1 *window = new fennetre1();  // Create and show the new window
            window->show();
        } else {
            QMessageBox::warning(this, "Error", "Unrecognized card or invalid password.");
        }
    } else {
        QMessageBox::warning(this, "Error", "Received data length is incorrect. Expected 16 bytes, received: " + QString::number(data.size()));
    }
}
