#include "fennetre2.h"
#include "ui_fennetre2.h"
#include "employe.h"

fennetre2::fennetre2(QString email,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::fennetre2),
    email(email)
{
    ui->setupUi(this);
    QPixmap pix("E:/esprit-info/2éme année/semestre2/projet C++/background.jpg");
    ui->label_picc->setPixmap(pix.scaled(900,1000,Qt::KeepAspectRatio));



    QPixmap pix2("E:/esprit-info/2éme année/semestre2/projet C++/member-icon-png-0-removebg-preview.png");
    ui->label_login_img->setPixmap(pix2.scaled(100,100,Qt::KeepAspectRatio));

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
        MainWindow *mainWin = new MainWindow();
        mainWin->show();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la mise à jour du mot de passe.");
    }
}

