#include "fennetre1.h"  // Corrected to 'fennetre1.h'
#include "ui_fennetre1.h"
#include <QPixmap>
#include <QDebug>
#include <QImageReader>
#include <QMessageBox>
#include "employe.h"
#include <QTableWidget>
#include <QTableWidgetItem>


fennetre1::fennetre1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::fennetre1)  // Corrected to 'fennetre1' in lowercase
{
    ui->setupUi(this);

    connect(ui->pushButton_AJemp, &QPushButton::clicked, this, &fennetre1::on_pushButton_AJemp_clicked);
    connect(ui->pushButton_showEmployes, &QPushButton::clicked, this, &fennetre1::showEmployes);

    // Debug: Print supported image formats
    qDebug() << "Supported image formats:" << QImageReader::supportedImageFormats();

    // Load background image
    QPixmap pix("E:/esprit-info/2éme année/semestre2/projet C++/background.jpg");
    if (pix.isNull()) {
        qDebug() << "Failed to load background.jpg. Check the file path.";
    } else {
        ui->label_pic->setPixmap(pix.scaled(900, 1000, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    // Load logo image
    QPixmap pix2("E:/esprit-info/2éme année/semestre2/projet C++/logoc++-removebg-preview.png");
    if (pix2.isNull()) {
        qDebug() << "Failed to load logoc++-removebg-preview.png. Check the file path.";
    } else {
        ui->label_pic2->setPixmap(pix2.scaled(140, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
}

fennetre1::~fennetre1()
{
    delete ui;
}


/*void fennetre1::on_pushButton_AJemp_clicked() {
    bool ok;
    int matricule = ui->lineEdit_matricule->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "Le matricule doit être un nombre entier.");
        return;
    }

    QString nom_em = ui->lineEdit_nom->text().trimmed();
    QString prenom_em = ui->lineEdit_prenom->text().trimmed();
    QDate dateN = ui->dateEdit->date();  // Corrected: Use .date() instead of .text().trimmed()
    QString email = ui->lineEdit_email->text().trimmed();
    QString Role = ui->lineEdit_role->text().trimmed();
    QString Mot_de_passe = ui->lineEdit_motpasse->text().trimmed();

    // Vérification des champs vides
    if (nom_em.isEmpty() || prenom_em.isEmpty() || email.isEmpty() || Role.isEmpty() || Mot_de_passe.isEmpty()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs avant d'ajouter un employé.");
        return;
    }

    //QString dateNstring = dateN.toString("yyyy-MM-dd");
    // Création de l'objet employé
    employe em(matricule, nom_em, prenom_em, dateN, email, Role, Mot_de_passe);

    // Ajout à la base de données
    if (em.ajouter()) {
        QMessageBox::information(this, "Succès", "L'employé a été ajouté avec succès !");
        showEmployes();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de l'employé.");
    }
}*/

void fennetre1::on_pushButton_AJemp_clicked() {
    bool ok;
    int matricule = ui->lineEdit_matricule->text().toInt(&ok);

    if (!ok ) {
        QMessageBox::warning(this, "Erreur", "Le matricule doit être un nombre valide.");
        return;
    }


    // Check if the employee with the given matricule exists
    QSqlQuery queryCheck;
    queryCheck.prepare("SELECT * FROM GS_EMPLOYER WHERE MATRICULE = :matricule");
    queryCheck.bindValue(":matricule", matricule);

    if (!isModifying) {
        // Check if the employee with the given matricule exists
        QSqlQuery queryCheck;
        queryCheck.prepare("SELECT * FROM GS_EMPLOYER WHERE MATRICULE = :matricule");
        queryCheck.bindValue(":matricule", matricule);

        if(queryCheck.exec() && queryCheck.next())
        {
            QMessageBox::warning(this, "Erreur", "Un employé existe dejà avec ce matricule.");
            return;
        }else{
            // If the employee does not exist, we add a new employee
            QString nom_em = ui->lineEdit_nom->text().trimmed();
            QString prenom_em = ui->lineEdit_prenom->text().trimmed();
            QDate dateN = ui->dateEdit->date();  // Corrected: Use .date() instead of .text().trimmed()
            QString email = ui->lineEdit_email->text().trimmed();
            QString Role = ui->lineEdit_role->text().trimmed();
            QString Mot_de_passe = ui->lineEdit_motpasse->text().trimmed();

            // Vérification des champs vides
            if (nom_em.isEmpty() || prenom_em.isEmpty() || email.isEmpty() || Role.isEmpty() || Mot_de_passe.isEmpty()) {
                QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs avant d'ajouter un employé.");
                return;
            }

            //QString dateNstring = dateN.toString("yyyy-MM-dd");
            // Création de l'objet employé
            employe em(matricule, nom_em, prenom_em, dateN, email, Role, Mot_de_passe);

            // Ajout à la base de données
            if (em.ajouter()) {
                QMessageBox::information(this, "Succès", "L'employé a été ajouté avec succès !");
                ui->lineEdit_matricule->clear();
                ui->lineEdit_nom->clear();
                ui->lineEdit_prenom->clear();
                ui->dateEdit->setDate(QDate::currentDate()); // Reset to current date
                ui->lineEdit_email->clear();
                ui->lineEdit_role->clear();
                ui->lineEdit_motpasse->clear();
                showEmployes();
            } else {
                QMessageBox::critical(this, "Erreur", "Échec de l'ajout de l'employé.");
            }
        }


    } else if ((queryCheck.exec() && queryCheck.next()) && isModifying)  {
        // If the employee exists, we modify the existing employee's details
        QString nom = ui->lineEdit_nom->text();
        QString prenom = ui->lineEdit_prenom->text();
        QDate dateN = ui->dateEdit->date();
        QString email = ui->lineEdit_email->text();
        QString role = ui->lineEdit_role->text();
        QString motDePasse = ui->lineEdit_motpasse->text();

        employe em;
        em.setmatricule(matricule);
        em.setnom_em(nom);
        em.setprenom_em(prenom);
        em.setdateN(dateN);
        em.setemail(email);
        em.setRole(role);
        em.setMot_de_passe(motDePasse);

        // Update the existing employee
        bool success = em.modifier();  // Call a new function to handle updating

        if (success) {
            QMessageBox::information(this, "Succès", "L'employé a été modifié avec succès !");
            ui->lineEdit_matricule->clear();
            ui->lineEdit_nom->clear();
            ui->lineEdit_prenom->clear();
            ui->dateEdit->setDate(QDate::currentDate()); // Reset to current date
            ui->lineEdit_email->clear();
            ui->lineEdit_role->clear();
            ui->lineEdit_motpasse->clear();
            isModifying = false;
            showEmployes();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la modification de l'employé.");
        }
    }
}



void fennetre1::on_pushButton_suprimer_clicked() {
    bool ok;
    int matricule = ui->lineEdit_matricule_id->text().toInt(&ok);  // Read matricule input

    if (!ok) {
        QMessageBox::warning(this, "Erreur", "Le matricule doit être un nombre entier.");
        return;
    }

    // Vérification si le matricule existe (optional)
    QSqlQuery query;
    query.prepare("SELECT * FROM GS_EMPLOYER WHERE MATRICULE = :matricule");
    query.bindValue(":matricule", matricule);

    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "Erreur", "Aucun employé trouvé avec ce matricule.");
        return;
    }

    // Create the employee object to call the supprimer function
    employe em;
    if (em.supprimer(matricule)) {
        QMessageBox::information(this, "Succès", "L'employé a été supprimé avec succès !");
        ui->lineEdit_matricule_id->clear();
        showEmployes();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression de l'employé.");
    }
}

#include <QTableWidget>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableWidgetItem>

void fennetre1::showEmployes() {
    // Create a query to fetch all employees
    QSqlQuery query("SELECT MATRICULE, NOM, PRENOM, DATEN, EMAIL, ROLE FROM GS_EMPLOYER");

    // Check if the query executed successfully
    /*if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la récupération des employés : " + query.lastError().text());
        return;
    }*/

    // Clear the table widget before populating it with new data
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    // Loop through the query results and populate the table
    while (query.next()) {
        // Get data from the query
        int matricule = query.value(0).toInt();
        QString nom_em = query.value(1).toString();
        QString prenom_em = query.value(2).toString();
        QString dateN = query.value(3).toString(); // Date as a string
        QString email = query.value(4).toString();
        QString role = query.value(5).toString();

        // Add a new row to the table widget
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        // Set the values in each cell of the row
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(matricule)));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(nom_em));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(prenom_em));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(dateN));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(email));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(role));
    }
}


void fennetre1::on_pushButton_modifier_clicked() {
    bool ok;
    int matricule = ui->lineEdit_matricule_id->text().toInt(&ok);

    if (!ok || matricule == 0) {
        QMessageBox::warning(this, "Erreur", "Le matricule doit être un nombre valide.");
        return;
    }

    // Query to find the employee by matricule
    QSqlQuery query;
    query.prepare("SELECT * FROM GS_EMPLOYER WHERE MATRICULE = :matricule");
    query.bindValue(":matricule", matricule);

    if (!query.exec() || !query.next()) {
        QMessageBox::warning(this, "Erreur", "Aucun employé trouvé avec ce matricule.");
        ui->lineEdit_matricule_id->clear();
        return;
    }

    isModifying = true; // Set the flag to indicate modification mode

    ui->lineEdit_matricule_id->clear(); // Clears just the matricule field

    // Show existing values in the QLineEdits
    ui->lineEdit_matricule->setText(query.value("MATRICULE").toString());
    ui->lineEdit_nom->setText(query.value("NOM").toString());
    ui->lineEdit_prenom->setText(query.value("PRENOM").toString());
    ui->dateEdit->setDate(query.value("DATEN").toDate());
    ui->lineEdit_email->setText(query.value("EMAIL").toString());
    ui->lineEdit_role->setText(query.value("ROLE").toString());
    ui->lineEdit_motpasse->setText(query.value("MOT_DE_PASSE").toString());
}

