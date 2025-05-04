#include "fennetre1.h"
#include "ui_fennetre1.h"
#include <QPixmap>
#include <QDebug>
#include <QImageReader>
#include <QMessageBox>
#include "employe.h"
//#include <QTableWidget>
//#include <QTableWidgetItem>
#include <QPdfWriter>
#include <QPainter>
#include <QSqlQuery>
#include <QFileDialog>
#include <QtGui/QPainter>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QVBoxLayout>
#include <QWidget>
#include <QSslSocket>
#include "global.h"
#include "gs_match.h"
#include "mainwindow.h"
#include "gs_equipe.h"
#include "sponsor.h"
#include "gs_billet.h"// for the login window
#include <QMessageBox>



fennetre1::fennetre1(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::fennetre1)  // Corrected to 'fennetre1' in lowercase
{
    ui->setupUi(this);

    connect(ui->pushButton_AJemp_3, &QPushButton::clicked, this, &fennetre1::on_pushButton_AJemp_3_clicked);
    connect(ui->pushButton_showEmployes, &QPushButton::clicked, this, &fennetre1::showEmployes);
    connect(ui->pushButton_PDF, &QPushButton::clicked, this, &fennetre1::on_pushButton_PDF_clicked);
    //connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_comboBox_currentIndexChanged(int)));
    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &fennetre1::on_comboBox_currentIndexChanged);
    connect(ui->btnShowChart_3, &QPushButton::clicked, this, &fennetre1::on_btnShowChart_3_clicked);
    connect(ui->match, &QPushButton::clicked, this, &fennetre1::on_match_clicked);
    connect(ui->equipe, &QPushButton::clicked, this, &fennetre1::on_equipe_clicked);
    connect(ui->billet, &QPushButton::clicked, this, &fennetre1::on_billet_clicked);



    ui->dateEdit_3->setDate(QDate::currentDate()); // Reset to current date

}

fennetre1::~fennetre1()
{
    delete ui;
}

void fennetre1::paintEvent(QPaintEvent *event) {
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

void fennetre1::on_match_clicked()
{
    if (isRoleAllowedForPage(CURRENT_USER_ROLE, "gs_match")) {
        gs_match *matchWindow = new gs_match(arduino, this);
        matchWindow->show();
        this->close();  // Close the fennetre1 window after opening gs_match
    } else {
        QMessageBox::warning(this, "Accès refusé", "Seuls les Coordinateurs de match peuvent accéder à cette page.");

        this->hide();  // Hide the current window (dashboard)

        MainWindow *loginWindow = new MainWindow(nullptr);
        loginWindow->show();
    }
}

void fennetre1::on_equipe_clicked()
{
    if (CURRENT_USER_ROLE == "Responsable équipe") {
        gs_equipe *window = new gs_equipe();
        window->show();
        this->close();  // Close the fennetre1 window after opening gs_equipe
    } else {
        QMessageBox::warning(this, "Accès refusé", "Vous n'avez pas le rôle requis pour accéder à cette page.");

        this->hide();
        MainWindow *loginWindow = new MainWindow(nullptr);
        loginWindow->show();
    }
}

void fennetre1::on_billet_clicked()
{
    if (CURRENT_USER_ROLE == "Responsable billets") {
        gs_billet *window = new gs_billet(this);
        window->show();
        this->close();  // Close the fennetre1 window after opening gs_billet
    } else {
        QMessageBox::warning(this, "Accès refusé", "Vous n'avez pas le rôle requis pour accéder à cette page.");

        this->hide();
        MainWindow *loginWindow = new MainWindow(nullptr);
        loginWindow->show();
    }
}

void fennetre1::on_sponsor_clicked()
{
    if (CURRENT_USER_ROLE == "Responsable sponsors") {
        sponsor *dialog = new sponsor(this);
        dialog->exec();  // Show as modal QDialog
        // No need to close fennetre1 if dialog is modal
    } else {
        QMessageBox::warning(this, "Accès refusé", "Vous n'avez pas le rôle requis pour accéder à cette page.");
        this->hide();
        QDialog *loginWindow = new QDialog(nullptr);
        loginWindow->show();
    }
}







//CRUD
void fennetre1::on_pushButton_AJemp_3_clicked() {
    bool ok;
    int matricule = ui->lineEdit_matricule_3->text().toInt(&ok);

    if (!ok) {
        QMessageBox::warning(this, "Erreur", "Le matricule doit être un nombre valide.");
        return;
    }

    // Regular expression for Gmail validation
    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@gmail\.com$)");

    // Get email input
    QString email = ui->lineEdit_email_3->text().trimmed();

    // Validate email format
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Email invalide", "Veuillez entrer une adresse Gmail valide (ex: exemple@gmail.com).");
        return;
    }

    // Role validation
    QString role = ui->lineEdit_role_3->text().trimmed();
    QStringList validRoles = {
        "Responsable équipe",
        "Coordinateur match",
        "Responsable RH",
        "Responsable billets",
        "Responsable sponsors"
    };

    if (!validRoles.contains(role)) {
        QMessageBox::warning(this, "Rôle invalide",
                             "Veuillez choisir un rôle valide : Responsable équipe, Coordinateur match, Responsable RH, Responsable billets, Responsable sponsors.");
        return;
    }

    // Password validation
    QString Mot_de_passe = ui->lineEdit_motpasse_3->text().trimmed();
    if (Mot_de_passe.length() < 6) {
        QMessageBox::warning(this, "Mot de passe invalide", "Le mot de passe doit contenir au moins 6 caractères.");
        return;
    }

    // Check if the employee with the given matricule exists
    QSqlQuery queryCheck;
    queryCheck.prepare("SELECT * FROM GS_EMPLOYER WHERE MATRICULE = :matricule");
    queryCheck.bindValue(":matricule", matricule);

    // Debug: Check if the query executes properly
    if (!queryCheck.exec()) {
        qDebug() << "Error executing check query: " << queryCheck.lastError().text();
        return;
    }

    // Check if we are modifying an existing employee or adding a new one
    if (!isModifying) {
        // If the employee does not exist, we add a new employee
        if (queryCheck.next()) {
            QMessageBox::warning(this, "Erreur", "Un employé existe déjà avec ce matricule.");
            return;
        }

        // Get other input fields
        QString nom_em = ui->lineEdit_nom_3->text().trimmed();
        QString prenom_em = ui->lineEdit_prenom_3->text().trimmed();
        QDate dateN = ui->dateEdit_3->date();

        // Vérification des champs vides
        if (nom_em.isEmpty() || prenom_em.isEmpty() || email.isEmpty() || role.isEmpty() || Mot_de_passe.isEmpty()) {
            QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs avant d'ajouter un employé.");
            return;
        }

        // Création de l'objet employé
        employe em(matricule, nom_em, prenom_em, dateN, email, role, Mot_de_passe, NULL);

        // Add the new employee to the database
        if (em.ajouter()) {
            QMessageBox::information(this, "Succès", "L'employé a été ajouté avec succès !");

            // Clear all fields after successful addition
            ui->lineEdit_matricule_3->clear();
            ui->lineEdit_nom_3->clear();
            ui->lineEdit_prenom_3->clear();
            ui->dateEdit_3->setDate(QDate::currentDate());
            ui->lineEdit_email_3->clear();
            ui->lineEdit_role_3->clear();
            ui->lineEdit_motpasse_3->clear();

            // Refresh the employee list
            showEmployes();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de l'ajout de l'employé.");

            // Debugging: Print error message from SQL
            qDebug() << "Error adding employee: " << queryCheck.lastError().text();
        }

    } else if ((queryCheck.exec() && queryCheck.next()) && isModifying) {
        // If we are modifying an existing employee, proceed with the modification

        QString nom = ui->lineEdit_nom_3->text();
        QString prenom = ui->lineEdit_prenom_3->text();
        QDate dateN = ui->dateEdit_3->date();

        employe em;
        em.setmatricule(matricule);
        em.setnom_em(nom);
        em.setprenom_em(prenom);
        em.setdateN(dateN);
        em.setemail(email);
        em.setRole(role);
        em.setMot_de_passe(Mot_de_passe);

        bool success = em.modifier();

        if (success) {
            QMessageBox::information(this, "Succès", "L'employé a été modifié avec succès !");

            // Clear all fields after successful modification
            ui->lineEdit_matricule_3->clear();
            ui->lineEdit_nom_3->clear();
            ui->lineEdit_prenom_3->clear();
            ui->dateEdit_3->setDate(QDate::currentDate());
            ui->lineEdit_email_3->clear();
            ui->lineEdit_role_3->clear();
            ui->lineEdit_motpasse_3->clear();

            isModifying = false;
            showEmployes();
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la modification de l'employé.");

            // Debugging: Print error message from SQL
            qDebug() << "Error modifying employee: " << queryCheck.lastError().text();
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



void fennetre1::showEmployes() {
    employe emp;
    QSqlQuery query;

    if (!emp.afficher(query)) {
        QMessageBox::critical(this, "Erreur", "Aucune donnée trouvée ou erreur de récupération.");
        return;
    }

    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(query.value(5).toString()));
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(query.value(6).toString()));

        row++;
    }

    qDebug() << "Total rows inserted: " << row;
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
    ui->lineEdit_matricule_3->setText(query.value("MATRICULE").toString());
    ui->lineEdit_nom_3->setText(query.value("NOM").toString());
    ui->lineEdit_prenom_3->setText(query.value("PRENOM").toString());
    ui->dateEdit_3->setDate(query.value("DATEN").toDate());
    ui->lineEdit_email_3->setText(query.value("EMAIL").toString());
    ui->lineEdit_role_3->setText(query.value("ROLE").toString());
    ui->lineEdit_motpasse_3->setText(query.value("MOT_DE_PASSE").toString());
}


//METIER BASCIQUE

void fennetre1::on_pushButton_recherche_clicked() {
    QString searchValue = ui->lineEdit_matricule_id->text().trimmed();

    if (searchValue.isEmpty()) {
        return;
    }

    employe emp;
    QVector<QVector<QString>> results = emp.rechercherEmploye(searchValue);

    ui->tableWidget->clearContents();
    int row = 0;

    for (const auto& emp : results) {
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(emp[0])); // Matricule
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(emp[1])); // Nom
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(emp[2])); // Prénom
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(emp[3])); // DateN
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(emp[4])); // Email
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(emp[5])); // Role
        ui->tableWidget->setItem(row, 6, new QTableWidgetItem(emp[6])); // Mot de passe

        row++;
    }

    if (row == 0) {
        QMessageBox::information(this, "Aucun résultat", "Aucun employé trouvé avec cette recherche.");
    }

    ui->lineEdit_matricule_id->clear();
}

//*********

void fennetre1::on_pushButton_PDF_clicked() {
    QString filePath = QFileDialog::getSaveFileName(this, "Save PDF", "", "PDF Files (*.pdf)");
    if (filePath.isEmpty()) {
        return;
    }

    QPdfWriter writer(filePath);
    writer.setResolution(300);
    QPainter painter(&writer);

    if (!painter.isActive()) {
        qDebug() << "Failed to initialize painter.";
        return;
    }

    // Add Logo and App Name to the top of the PDF
    QImage logo("E:/esprit-info/2éme année/semestre2/projet C++/logoc++-removebg-preview.png");  // Path to your logo image
    painter.drawImage(150, 5, logo.scaled(400, 400, Qt::KeepAspectRatio));

    QFont font("Arial", 16, QFont::Bold);
    painter.setFont(font);
    painter.drawText(150, 390, "REMONTADA");  // Position the app name next to the logo

    // Add some space before the employee data starts
    int yPos = 550;
    int labelX = 200, dataX = 550, ySpacing = 50;

    // Fetch employee data
    employe emp;
    QVector<QVector<QString>> employees = emp.getAllEmployees();

    // Draw employee data
    for (const auto& emp : employees) {
        painter.setFont(QFont("Arial", 12));  // Set smaller font for employee data

        painter.drawText(labelX, yPos, "Matricule: ");
        painter.drawText(dataX, yPos, emp[0]);

        painter.drawText(labelX, yPos + ySpacing, "Name: ");
        painter.drawText(dataX, yPos + ySpacing, emp[1]);

        painter.drawText(labelX, yPos + 2 * ySpacing, "Prenom: ");
        painter.drawText(dataX, yPos + 2 * ySpacing, emp[2]);

        painter.drawText(labelX, yPos + 3 * ySpacing, "Daten: ");
        painter.drawText(dataX, yPos + 3 * ySpacing, emp[3]);

        painter.drawText(labelX, yPos + 4 * ySpacing, "Email: ");
        painter.drawText(dataX, yPos + 4 * ySpacing, emp[4]);

        painter.drawText(labelX, yPos + 5 * ySpacing, "Role: ");
        painter.drawText(dataX, yPos + 5 * ySpacing, emp[5]);

        painter.drawText(labelX, yPos + 6 * ySpacing, "Mot de passe: ");
        painter.drawText(dataX, yPos + 6 * ySpacing, emp[6]);

        yPos += 9 * ySpacing;  // Adjust position for the next employee
    }

    painter.end();
    qDebug() << "PDF saved to" << filePath;
}


/*void fennetre1::on_pushButton_PDF_clicked() {
    QString filePath = QFileDialog::getSaveFileName(this, "Save PDF", "", "PDF Files (*.pdf)");
    if (filePath.isEmpty()) {
        return;
    }

    QPdfWriter writer(filePath);
    writer.setResolution(300);
    QPainter painter(&writer);

    if (!painter.isActive()) {
        qDebug() << "Failed to initialize painter.";
        return;
    }

    employe emp;
    QVector<QVector<QString>> employees = emp.getAllEmployees();

    int yPos = 100;
    int labelX = 100, dataX = 350, ySpacing = 50;

    for (const auto& emp : employees) {
        painter.drawText(labelX, yPos, "Matricule: ");
        painter.drawText(dataX, yPos, emp[0]);

        painter.drawText(labelX, yPos + ySpacing, "Name: ");
        painter.drawText(dataX, yPos + ySpacing, emp[1]);

        painter.drawText(labelX, yPos + 2 * ySpacing, "Prenom: ");
        painter.drawText(dataX, yPos + 2 * ySpacing, emp[2]);

        painter.drawText(labelX, yPos + 3 * ySpacing, "Daten: ");
        painter.drawText(dataX, yPos + 3 * ySpacing, emp[3]);

        painter.drawText(labelX, yPos + 4 * ySpacing, "Email: ");
        painter.drawText(dataX, yPos + 4 * ySpacing, emp[4]);

        painter.drawText(labelX, yPos + 5 * ySpacing, "Role: ");
        painter.drawText(dataX, yPos + 5 * ySpacing, emp[5]);

        painter.drawText(labelX, yPos + 6 * ySpacing, "Mot de passe: ");
        painter.drawText(dataX, yPos + 6 * ySpacing, emp[6]);

        yPos += 9 * ySpacing;
    }

    painter.end();
    qDebug() << "PDF saved to" << filePath;
}*/



void fennetre1::on_comboBox_currentIndexChanged(int index) {
    employe emp;
    emp.trierEmployes(ui->tableWidget, index);
}


void fennetre1::afficherStatistiquesEmployes() {
    // Get statistics data
    employe emp;
    QMap<QString, int> stats = emp.statistiquesRoles();

    // Check if there's already a chart view and remove it
    QLayoutItem *child;
    while ((child = ui->chartContainer_3->layout()->takeAt(0)) != nullptr) {
        delete child->widget();  // Remove the existing chart
        delete child;
    }

    // Create the pie chart series
    QPieSeries *series = new QPieSeries();
    for (auto it = stats.begin(); it != stats.end(); ++it) {
        series->append(it.key(), it.value());
    }

    // Create the chart and add the series
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des employés par rôle");

    // Create the chart view
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(250, 200);

    // Add the chart to the layout
    ui->chartContainer_3->layout()->addWidget(chartView);
}

void fennetre1::on_btnShowChart_3_clicked() {
    afficherStatistiquesEmployes();
}

//mailing
bool fennetre1::verifyEmailExistsInDB(const QString& email)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM GS_EMPLOYER WHERE LOWER(TRIM(email)) = LOWER(TRIM(:email))");
    query.bindValue(":email", email);

    if (!query.exec()) {
        qDebug() << "Erreur de requête SQL:" << query.lastError();
        return false;
    }

    if (query.next()) {
        int count = query.value(0).toInt();
        qDebug() << "Email match count:" << count;
        return count > 0;
    }
    return false;
}

/*
void fennetre1::on_pushButton_mailing_clicked()
{
    QString serveur = "smtp.gmail.com";
    int port = 587; // Port pour SMTP avec STARTTLS

    // Informations de l'expéditeur et du destinataire
    QString expediteur = "yhedhly15@gmail.com";
    QString destinataire = ui->lineEdit_gmail->text(); // Remplacé ici

    QString subject = "Cher client";

    // Détails du message
    QString corps = ui->textEdit_5->toPlainText(); // Remplacé ici

    // Connexion au serveur SMTP
    QSslSocket socket;
    socket.connectToHost(serveur, port);
    if (!socket.waitForConnected()) {
        qDebug() << "Échec de connexion au serveur SMTP:" << socket.errorString();
        return;
    }

    // Attente de la réponse du serveur
    if (!socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP:" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Afficher la réponse initiale du serveur

    // Envoi de la commande EHLO
    socket.write("EHLO localhost\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP (EHLO):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Afficher la réponse après EHLO

    // Envoi de la commande STARTTLS
    socket.write("STARTTLS\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP (STARTTLS):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Afficher la réponse après STARTTLS

    // Démarrer le chiffrement
    socket.startClientEncryption();
    if (!socket.waitForEncrypted()) {
        qDebug() << "Échec du chiffrement:" << socket.errorString();
        return;
    }

    // Envoi de la commande AUTH LOGIN
    socket.write("AUTH LOGIN\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP (AUTH LOGIN):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Afficher la réponse après AUTH LOGIN

    // Envoi du nom d'utilisateur encodé en Base64
    socket.write(QByteArray().append(expediteur.toUtf8()).toBase64() + "\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP (Nom d'utilisateur):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Afficher la réponse après l'envoi du nom d'utilisateur

    // Envoi du mot de passe encodé en Base64
    socket.write(QByteArray().append("ijdx nluv ozpm omie").toBase64() + "\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Échec de l'authentification SMTP (Mot de passe):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Afficher la réponse après l'envoi du mot de passe

    // Envoi de la commande MAIL FROM
    socket.write("MAIL FROM:<" + expediteur.toUtf8() + ">\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP (MAIL FROM):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Afficher la réponse après MAIL FROM

    // Envoi de la commande RCPT TO
    socket.write("RCPT TO:<" + destinataire.toUtf8() + ">\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP (RCPT TO):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Afficher la réponse après RCPT TO

    // Envoi de la commande DATA
    socket.write("DATA\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP (DATA):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Afficher la réponse après DATA

    // Envoi des en-têtes et du corps du message
    socket.write("From: " + expediteur.toUtf8() + "\r\n");
    socket.write("To: " + destinataire.toUtf8() + "\r\n");
    socket.write("Subject: " + subject.toUtf8() + "\r\n");
    socket.write("\r\n");
    socket.write(corps.toUtf8() + "\r\n");
    socket.write(".\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Échec d'envoi des données du mail:" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Afficher la réponse après l'envoi des données du mail

    // Envoi de la commande QUIT
    socket.write("QUIT\r\n");
    if (!socket.waitForBytesWritten()) {
        qDebug() << "Échec d'envoi de la commande QUIT:" << socket.errorString();
        return;
    }

    // Fermeture de la connexion
    socket.close();
    QMessageBox::information(this, "Succès", "L'email a été envoyé avec succès à " + destinataire);
}
*/

// In your fennetre1 class:
void fennetre1::on_pushButton_selectFile_clicked()
{
    attachedFilePath = QFileDialog::getOpenFileName(this, "Choisir un fichier à joindre");
    if (!attachedFilePath.isEmpty()) {
        ui->label_selectedFile->setText(QFileInfo(attachedFilePath).fileName());
    } else {
        ui->label_selectedFile->setText("Aucun fichier sélectionné");
    }
}

void fennetre1::on_pushButton_mailing_clicked()
{
    QString email = ui->lineEdit_gmail->text();
    QString corps = ui->textEdit_5->toPlainText();
    QString filePath = ui->label_selectedFile->text(); // Or however you store the file path

    // Ensure email is provided, and either message or file should be filled
    if (email.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez remplir l'email.");
        return;
    }

    // If neither the message nor the file is provided, show a warning
    if (corps.isEmpty() && filePath.isEmpty()) {
        QMessageBox::warning(this, "Champs manquants", "Veuillez saisir un message ou sélectionner un fichier.");
        return;
    }

    // Check if email exists in the database
    if (!verifyEmailExistsInDB(email)) {
        QMessageBox::warning(this, "Email non trouvé", "L'email que vous avez saisi n'existe pas.");
        return;
    }

    QString expediteur = "yhedhly15@gmail.com";
    QString subject = "Cher client";

    // Send email with or without an attachment
    employe::sendEmail(expediteur, email, subject, corps, filePath);

    // Success message
    QMessageBox::information(this, "Succès", "L'email a été envoyé avec succès.");

    // Clear fields after sending the email
    ui->lineEdit_gmail->clear();
    ui->textEdit_5->clear();
    ui->label_selectedFile->clear(); // Reset file label
}

