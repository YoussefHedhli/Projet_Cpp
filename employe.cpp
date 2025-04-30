#include "employe.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QTableWidget>
#include <QMessageBox>
#include <QtCore/QDebug>
#include <QFile>
#include <QFileInfo>
//#include <vosk_api.h>
//#include <portaudio.h>

//#include <QRegExp>
//#include <QTableWidgetItem>
//#define SAMPLE_RATE 16000
//#define FRAMES_PER_BUFFER 512

QString encodeFileToBase64(const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Erreur lors de l'ouverture du fichier:" << file.errorString();
        return QString();
    }
    QByteArray fileContent = file.readAll();
    file.close();
    return fileContent.toBase64();
}

employe::employe() : matricule(0), nom_em(""), prenom_em(""), dateN(QDate::currentDate()), email(""), Role(""), Mot_de_passe("") {}


employe::employe(int m, const QString& n, const QString& p, const QDate& d, const QString& e, const QString& r, const QString& mp)
    : matricule(m), nom_em(n), prenom_em(p), dateN(d), email(e), Role(r), Mot_de_passe(mp) {}



// Getters
int employe::getmatricule() const { return matricule; }
QString employe::getnom_em() const { return nom_em; }
QString employe::getprenom_em() const { return prenom_em; }
QDate employe::getdateN() const { return dateN; }
QString employe::getemail() const { return email; }
QString employe::getRole() const { return Role; }
QString employe::getMot_de_passe() const { return Mot_de_passe; }

// Setters
void employe::setmatricule(int m) { this->matricule = m; }
void employe::setnom_em(const QString&n) { this->nom_em = n; }
void employe::setprenom_em(const QString& p) { this->prenom_em = p; }
void employe::setdateN(const QDate& d) { this->dateN = d; }
void employe::setemail(const QString& e) { this->email = e; }
void employe::setRole(const QString& r) { this->Role = r; }
void employe::setMot_de_passe(const QString& mp) {  this->Mot_de_passe = mp; }


// Fonction pour ajouter une équipe dans la base de données
bool employe::ajouter() {
    QSqlQuery query;

    // Debugging: Check the extracted date before insertion
    qDebug() << "Inserting date: " << dateN.toString("yyyy-MM-dd");

    query.prepare("INSERT INTO GS_EMPLOYER (MATRICULE, NOM, PRENOM, DATEN, EMAIL, ROLE, MOT_DE_PASSE) "
                  "VALUES (:matricule, :nom, :prenom, :daten, :email, :role, :mot_de_passe)");

    query.bindValue(":matricule", matricule);
    query.bindValue(":nom", nom_em);
    query.bindValue(":prenom", prenom_em);
    query.bindValue(":daten", dateN.toString("yyyy-MM-dd"));     // Ensure correct date format
    query.bindValue(":email", email);
    query.bindValue(":role", Role);
    query.bindValue(":mot_de_passe", Mot_de_passe);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout de l'employé : " << query.lastError().text();
        qDebug() << "Requête exécutée : " << query.lastQuery();
        return false;
    }

    return true;
}

// Fonction pour supprimer un employé par matricule
bool employe::supprimer(int m) {
    QSqlQuery query;

    query.prepare("DELETE FROM GS_EMPLOYER WHERE MATRICULE = :matricule");
    query.bindValue(":matricule", m);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression de l'employé : " << query.lastError().text();
        return false;
    }

    return true;
}


// Fonction pour modifier un employé
bool employe::modifier() {
    QSqlQuery query;
    query.prepare("UPDATE GS_EMPLOYER SET NOM = :nom, PRENOM = :prenom, DATEN = :daten, "
                  "EMAIL = :email, ROLE = :role, MOT_DE_PASSE = :mot_de_passe WHERE MATRICULE = :matricule");

    query.bindValue(":matricule", matricule); // assuming matricule is a member variable
    query.bindValue(":nom", nom_em); // assuming nom_em is a member variable
    query.bindValue(":prenom", prenom_em); // assuming prenom_em is a member variable
    query.bindValue(":daten", dateN.toString("yyyy-MM-dd")); // assuming dateN is a member variable
    query.bindValue(":email", email); // assuming email is a member variable
    query.bindValue(":role", Role); // assuming role is a member variable
    query.bindValue(":mot_de_passe", Mot_de_passe); // assuming mot_de_passe is a member variable

    return query.exec();
}


// Fonction pour afficher un employé
bool employe::afficher(QSqlQuery& query) {
    query.prepare("SELECT MATRICULE, NOM, PRENOM, DATEN, EMAIL, ROLE, MOT_DE_PASSE FROM GS_EMPLOYER");

    if (!query.exec()) {
        qDebug() << "Query execution failed: " << query.lastError().text();
        return false;
    }

    return query.isActive() > 0; // Return true if data is found
}

//METIER BASCIQUE

QVector<QVector<QString>> employe::rechercherEmploye(const QString& searchValue) {
    QVector<QVector<QString>> results;

    QSqlQuery query;
    query.prepare("SELECT * FROM GS_EMPLOYER WHERE NOM LIKE :search OR PRENOM LIKE :search OR MATRICULE LIKE :search OR DATEN LIKE :search OR EMAIL LIKE :search OR ROLE LIKE :search OR MOT_DE_PASSE LIKE :search");
    query.bindValue(":search", "%" + searchValue + "%");

    if (query.exec()) {
        while (query.next()) {
            QVector<QString> row;
            row.append(query.value("MATRICULE").toString());
            row.append(query.value("NOM").toString());
            row.append(query.value("PRENOM").toString());
            row.append(query.value("DATEN").toDate().toString("yyyy-MM-dd"));
            row.append(query.value("EMAIL").toString());
            row.append(query.value("ROLE").toString());
            row.append(query.value("MOT_DE_PASSE").toString());

            results.append(row);
        }
    }

    return results;
}

QVector<QVector<QString>> employe::getAllEmployees() {
    QVector<QVector<QString>> employees;

    QSqlQuery query("SELECT * FROM GS_EMPLOYER");
    while (query.next()) {
        QVector<QString> row;
        row.append(query.value("MATRICULE").toString());
        row.append(query.value("NOM").toString());
        row.append(query.value("PRENOM").toString());
        row.append(query.value("DATEN").toString());
        row.append(query.value("EMAIL").toString());
        row.append(query.value("ROLE").toString());
        row.append(query.value("MOT_DE_PASSE").toString());

        employees.append(row);
    }

    return employees;
}


void employe::trierEmployes(QTableWidget *tableWidget, int index) {
    int column = -1;
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
        tableWidget->sortItems(column, order);
    }
}

QMap<QString, int> employe::statistiquesRoles() {
    QMap<QString, int> stats;
    QSqlQuery query("SELECT ROLE, COUNT(*) FROM GS_EMPLOYER GROUP BY ROLE");

    while (query.next()) {
        QString role = query.value(0).toString();
        int count = query.value(1).toInt();
        stats[role] = count;
    }

    return stats;
}

//METIER AVANCER

bool employe::verifierAuthentification(const QString &email, const QString &password) {
    QSqlQuery query;
    query.prepare("SELECT * FROM GS_EMPLOYER WHERE EMAIL = :email");
    query.bindValue(":email", email);

    if (query.exec() && query.next()) {
        // If the email exists, compare the password with the one in the database
        QString storedPassword = query.value("MOT_DE_PASSE").toString();
        if (password == storedPassword) {
            return true;  // Authentication successful
        } else {
            // Password is incorrect
            QMessageBox::warning(nullptr, "Erreur", "Mot de passe incorrect.");
        }
    } else {
        // Email not found
        QMessageBox::warning(nullptr, "Erreur", "Email non trouvé.");
    }
    return false;  // Authentication failed (either email not found or incorrect password)
}

bool employe::updatePassword(const QString &email, const QString &newPassword) {
    QSqlQuery query;
    query.prepare("UPDATE GS_EMPLOYER SET MOT_DE_PASSE = :password WHERE EMAIL = :email");
    query.bindValue(":password", newPassword);
    query.bindValue(":email", email);

    if (query.exec()) {
        return true;  // Password updated successfully
    } else {
        return false;  // Failed to update password
    }
}

bool employe::emailExiste(const QString &email) {
    QSqlQuery query;
    query.prepare("SELECT EMAIL FROM GS_EMPLOYER WHERE EMAIL = :email");
    query.bindValue(":email", email);

    if (query.exec() && query.next()) {
        return true; // Email found
    }
    return false; // Email not found
}


void employe::sendEmail(const QString& expediteur, const QString& destinataire, const QString& sujet, const QString& corps, const QString& filePath)
{
    QSslSocket socket;
    socket.connectToHost("smtp.gmail.com", 587);
    if (!socket.waitForConnected()) {
        qDebug() << "Échec de connexion au serveur SMTP:" << socket.errorString();
        return;
    }

    // Waiting for the server response
    if (!socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP:" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Initial server response

    // Send EHLO command
    socket.write("EHLO localhost\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP (EHLO):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Response after EHLO

    // Start TLS encryption
    socket.write("STARTTLS\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP (STARTTLS):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Response after STARTTLS

    socket.startClientEncryption();
    if (!socket.waitForEncrypted()) {
        qDebug() << "Échec du chiffrement:" << socket.errorString();
        return;
    }

    // Send AUTH LOGIN command
    socket.write("AUTH LOGIN\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP (AUTH LOGIN):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Response after AUTH LOGIN

    // Send base64 encoded email and password (replace with App password for Gmail)
    socket.write(QByteArray::fromStdString(expediteur.toUtf8().toStdString()).toBase64() + "\r\n");

    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP (Email):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Response after email

    socket.write(QByteArray().append("ijdx nluv ozpm omie").toBase64() + "\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Échec de l'authentification SMTP (Mot de passe):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Response after password

    // Send MAIL FROM command
    socket.write("MAIL FROM:<" + expediteur.toUtf8() + ">\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP (MAIL FROM):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Response after MAIL FROM

    // Send RCPT TO command
    socket.write("RCPT TO:<" + destinataire.toUtf8() + ">\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP (RCPT TO):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Response after RCPT TO

    // Send DATA command
    socket.write("DATA\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Délai d'attente de réponse du serveur SMTP (DATA):" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Response after DATA

    // Send email headers and body
    QString boundary = "====BOUNDARY====";
    QString header = QString(
                         "From: %1\r\n"
                         "To: %2\r\n"
                         "Subject: %3\r\n"
                         "MIME-Version: 1.0\r\n"
                         "Content-Type: multipart/mixed; boundary=\"%4\"\r\n"
                         "\r\n"
                         "--%4\r\n"
                         "Content-Type: text/plain; charset=\"UTF-8\"\r\n"
                         "Content-Transfer-Encoding: 7bit\r\n"
                         "\r\n"
                         "%5\r\n"
                         ).arg(expediteur, destinataire, sujet, boundary, corps);

    socket.write(header.toUtf8());

    if (!filePath.isEmpty()) {
        QFileInfo info(filePath);
        QString fileContentEncoded = encodeFileToBase64(filePath);
        QString attachment = QString(
                                 "--%1\r\n"
                                 "Content-Type: application/octet-stream; name=\"%2\"\r\n"
                                 "Content-Transfer-Encoding: base64\r\n"
                                 "Content-Disposition: attachment; filename=\"%2\"\r\n"
                                 "\r\n"
                                 "%3\r\n"
                                 ).arg(boundary, info.fileName(), fileContentEncoded);
        socket.write(attachment.toUtf8());
    }

    socket.write("--" + boundary.toUtf8() + "--\r\n");
    socket.write(".\r\n");
    if (!socket.waitForBytesWritten() || !socket.waitForReadyRead()) {
        qDebug() << "Échec d'envoi des données du mail:" << socket.errorString();
        return;
    }
    qDebug() << socket.readAll(); // Response after sending data

    // Send QUIT command to close the session
    socket.write("QUIT\r\n");
    if (!socket.waitForBytesWritten()) {
        qDebug() << "Échec d'envoi de la commande QUIT:" << socket.errorString();
        return;
    }

    socket.close();
}


// Recognize voice and return text
/*QString employe::reconnaitreMotDePasseParVoix(const QString &modelPath)
{
    vosk_set_log_level(0);
    Pa_Initialize();

    VoskModel *model = vosk_model_new(modelPath.toStdString().c_str());
    VoskRecognizer *recognizer = vosk_recognizer_new(model, 16000.0f);

    PaStream *stream;
    Pa_OpenDefaultStream(&stream, 1, 0, paInt16, 16000, 512, nullptr, nullptr);
    Pa_StartStream(stream);

    qDebug() << "🎤 Speak your password...";

    short buffer[512];
    QString resultText;

    for (int i = 0; i < 100; ++i) {
        Pa_ReadStream(stream, buffer, 512);
        if (vosk_recognizer_accept_waveform(recognizer, (const char*)buffer, sizeof(buffer))) {
            const char *result = vosk_recognizer_result(recognizer);
            resultText = QString::fromUtf8(result);
            break;
        }
    }

    Pa_StopStream(stream);
    Pa_CloseStream(stream);
    Pa_Terminate();

    vosk_recognizer_free(recognizer);
    vosk_model_free(model);

    // Extract only the "text" value
    QRegExp rx("\"text\"\\s*:\\s*\"([^\"]+)\"");
    if (rx.indexIn(resultText) != -1) {
        return rx.cap(1);
    }

    return "";
}

// Check if the recognized password exists in the database
bool employe::verifierMotDePasseVoix(const QString &motDePasseReconnu)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM GS_EMPLOYER WHERE Mot_de_passe = :mdp");
    query.bindValue(":mdp", motDePasseReconnu);

    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }

    return false;
}*/
