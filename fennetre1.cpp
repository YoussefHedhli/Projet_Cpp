#include "fennetre1.h"  // Corrected to 'fennetre1.h'
#include "ui_fennetre1.h"
#include <QPixmap>
#include <QDebug>
#include <QImageReader>
#include <QMessageBox>
#include "employe.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QPdfWriter>
#include <QPainter>
#include <QSqlQuery>
#include <QFileDialog>
#include <QtGui/QPainter>




fennetre1::fennetre1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::fennetre1)  // Corrected to 'fennetre1' in lowercase
{
    ui->setupUi(this);

    connect(ui->pushButton_AJemp, &QPushButton::clicked, this, &fennetre1::on_pushButton_AJemp_clicked);
    connect(ui->pushButton_showEmployes, &QPushButton::clicked, this, &fennetre1::showEmployes);
    connect(ui->pushButton_PDF, &QPushButton::clicked, this, &fennetre1::on_pushButton_PDF_clicked);
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_comboBox_currentIndexChanged(int)));
    ui->dateEdit->setDate(QDate::currentDate()); // Reset to current date
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
    QSqlQuery query("SELECT MATRICULE, NOM, PRENOM, DATEN, EMAIL, ROLE, MOT_DE_PASSE FROM GS_EMPLOYER");

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
        QString Mot_de_passe = query.value(6).toString();

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
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(Mot_de_passe));
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

void fennetre1::on_pushButton_recherche_clicked() {
    QString searchValue = ui->lineEdit_matricule_id->text().trimmed();

    // If the search value is empty, do nothing
    if (searchValue.isEmpty()) {
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM GS_EMPLOYER WHERE NOM LIKE :search OR PRENOM LIKE :search OR MATRICULE LIKE :search OR DATEN LIKE :search OR EMAIL LIKE :search OR ROLE LIKE :search OR MOT_DE_PASSE LIKE :search");
    query.bindValue(":search", "%" + searchValue + "%");

    if (query.exec()) {
        // Clear the table before displaying search results
        ui->tableWidget->clearContents();
        int row = 0;

        // Loop through the query results
        while (query.next()) {
            int matricule = query.value("MATRICULE").toInt();
            QString nom = query.value("NOM").toString();
            QString prenom = query.value("PRENOM").toString();
            QDate dateN = query.value("DATEN").toDate();
            QString email = query.value("EMAIL").toString();
            QString role = query.value("ROLE").toString();
            QString motdepasse = query.value("MOT_DE_PASSE").toString();

            // Set data into the table for each matching employee
            //ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(matricule)));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(nom));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(prenom));
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(dateN.toString("yyyy-MM-dd")));
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(email));
            ui->tableWidget->setItem(row, 5, new QTableWidgetItem(role));
            ui->tableWidget->setItem(row, 6, new QTableWidgetItem(motdepasse));

            row++;
        }

        // If no employee found, display message
        if (row == 0) {
            QMessageBox::information(this, "Aucun résultat", "Aucun employé trouvé avec cette recherche.");
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la recherche dans la base de données.");
    }
    ui->lineEdit_matricule_id->clear(); // Clears just the matricule field

}

void fennetre1::on_pushButton_PDF_clicked()
{
    // Open a file dialog to choose the location to save the PDF
    QString filePath = QFileDialog::getSaveFileName(this, "Save PDF", "", "PDF Files (*.pdf)");
    if (filePath.isEmpty()) {
        return;  // Exit if no file path is selected
    }

    // Create a QPdfWriter object to write the PDF
    QPdfWriter writer(filePath);

    // Set page size to A4
    //writer.setPageSize(QPagedPaintDevice::A4);  // Use QPagedPaintDevice::A4 for A4 page size
    //writer.setPageSize(QPdfWriter::A4);


    writer.setResolution(300);  // Set resolution
    QPainter painter(&writer);

    // Check if the painter was successfully initialized
    if (!painter.isActive()) {
        qDebug() << "Failed to initialize painter.";
        return;
    }

    // Query the database for employee data
    QSqlQuery query("SELECT * FROM GS_EMPLOYER");
    int yPos = 100;  // Initial Y position for the text


    // Set initial X position for each field label
    int labelX = 100;  // X position for labels
    int dataX = 350;   // Increased X position for data (shifted further right)
    int ySpacing = 50; // Increased vertical spacing between lines

    // Loop through the query results and add them to the PDF
    while (query.next()) {
        QString empMatricule = query.value("MATRICULE").toString();
        QString empName = query.value("NOM").toString();
        QString empPrenom = query.value("PRENOM").toString();
        QString empDaten = query.value("DATEN").toString();
        QString empEmail = query.value("EMAIL").toString();
        QString empRole = query.value("ROLE").toString();
        QString empMot_de_passe = query.value("MOT_DE_PASSE").toString();

        // Draw employee data onto the PDF with proper alignment
        painter.drawText(labelX, yPos, "Matricule: ");
        painter.drawText(dataX, yPos, empMatricule);

        painter.drawText(labelX, yPos + ySpacing, "Name: ");
        painter.drawText(dataX, yPos + ySpacing, empName);

        painter.drawText(labelX, yPos + 2 * ySpacing, "Prenom: ");
        painter.drawText(dataX, yPos + 2 * ySpacing, empPrenom);

        painter.drawText(labelX, yPos + 3 * ySpacing, "Daten: ");
        painter.drawText(dataX, yPos + 3 * ySpacing, empDaten);

        painter.drawText(labelX, yPos + 4 * ySpacing, "Email: ");
        painter.drawText(dataX, yPos + 4 * ySpacing, empEmail);

        painter.drawText(labelX, yPos + 5 * ySpacing, "Role: ");
        painter.drawText(dataX, yPos + 5 * ySpacing, empRole);

        painter.drawText(labelX, yPos + 6 * ySpacing, "Mot de passe: ");
        painter.drawText(dataX , yPos + 6 * ySpacing, empMot_de_passe);

        // Increase yPos to avoid overlap for the next employee
        yPos += 9 * ySpacing;  // Adjust this value for the next employee's data
    }

    // Finalize and close the painter
    painter.end();

    // Notify the user that the PDF was saved
    qDebug() << "PDF saved to" << filePath;
}

void fennetre1::on_comboBox_currentIndexChanged(int index) {
    int column = -1;  // Default invalid column
    Qt::SortOrder order = Qt::AscendingOrder;

    switch (index) {
    case 0: column = 1; order = Qt::AscendingOrder; break;  // Nom (A → Z)
    case 1: column = 1; order = Qt::DescendingOrder; break; // Nom (Z → A)
    case 2: column = 2; order = Qt::AscendingOrder; break;  // Prénom (A → Z)
    case 3: column = 2; order = Qt::DescendingOrder; break; // Prénom (Z → A)
    case 4: column = 3; order = Qt::AscendingOrder; break;  // Date (Oldest → Newest)
    case 5: column = 3; order = Qt::DescendingOrder; break; // Date (Newest → Oldest)
    case 6: column = 0; order = Qt::AscendingOrder; break;  // Matricule (Small → Big)
    case 7: column = 0; order = Qt::DescendingOrder; break; // Matricule (Big → Small)
    }

    if (column != -1) {
        ui->tableWidget->sortItems(column, order);
    }
}
