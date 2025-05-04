#include "fennetre2.h"
#include "ui_fennetre2.h"
#include "employe.h"
#include <QPainter>
fennetre2::fennetre2(::Arduino* a,QString email,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::fennetre2),
    email(email),
    Arduino(a)
{
    ui->setupUi(this);

    // Style for the email address input
    ui->lineEdit_2->setPlaceholderText("  Confirmer nouveau mot de passe");
    ui->lineEdit_2->setStyleSheet("QLineEdit {"
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
    // Hide the confirmation password field
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);

    // Style for the password input
    ui->lineEdit_3->setPlaceholderText("  Nouveau mot de passe");
    ui->lineEdit_3->setStyleSheet("QLineEdit {"
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
    // Hide the new password field
    ui->lineEdit_3->setEchoMode(QLineEdit::Password);
}

fennetre2::~fennetre2()
{
    delete ui;
}

void fennetre2::paintEvent(QPaintEvent *event) {
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
    QDialog::paintEvent(event);
}

void fennetre2::on_pushButton_sauvgrd_clicked()
{
    QString newPassword = ui->lineEdit_3->text().trimmed();  // New password
    QString confirmPassword = ui->lineEdit_2->text().trimmed();  // Confirm password

    if (newPassword.isEmpty() || confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    if (newPassword != confirmPassword) {
        QMessageBox::warning(this, "Erreur", "Les mots de passe ne correspondent pas.");
        return;
    }

    // Update the password in the database
    employe emp;
    bool result = emp.updatePassword(email, newPassword);

    if (result) {
        QMessageBox::information(this, "Succès", "Votre mot de passe a été changé avec succès.");
        this->close();  // Close the password reset window

        // Open the MainWindow again
        MainWindow *mainWin = new MainWindow(Arduino);//pass Arduino au mainwindow
        mainWin->show();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la mise à jour du mot de passe.");
    }
}

