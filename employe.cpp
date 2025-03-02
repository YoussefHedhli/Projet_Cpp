#include "employe.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>


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




