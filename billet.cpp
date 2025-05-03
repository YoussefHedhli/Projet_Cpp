#include "billet.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Billet::Billet() : prix(0) {}

void Billet::setPrix(int prix) {
    this->prix = prix;
}

int Billet::getPrix() const {
    return prix;
}

void Billet::setType(const QString &type) {
    this->type = type;
}

QString Billet::getType() const {
    return type;
}

void Billet::setDateB(const QDate &date) {
    this->dateB = date;
}

QDate Billet::getDateB() const {
    return dateB;
}

void Billet::setQrId(const QString &qrId) {
    this->qrId = qrId;
}

QString Billet::getQrId() const {
    return qrId;
}

// Fetch a specific ticket by ID_B
bool Billet::fetchBilletById(int id_b) {
    QSqlQuery query;
    query.prepare("SELECT * FROM GS_BILLET WHERE ID_B = :id_b");
    query.bindValue(":id_b", id_b);

    if (query.exec() && query.next()) {
        qrId = query.value("QRID").toString();
        dateB = query.value("DATEB").toDate();
        return true;
    }
    return false;
}
void Billet::setIdMatch(int id) {
    idMatch_b = id;
}

// Add a ticket to the database
bool Billet::ajouterBillet(int id_b) {
    QSqlQuery query;
    query.prepare("INSERT INTO GS_BILLET (ID_B, PRIX, TYPE, DATEB, QRID, IDMATCH_B) "
                  "VALUES (:id_b, :prix, :type, :dateb, :qrid, :idmatch_b)");
    query.bindValue(":id_b", id_b);
    query.bindValue(":prix", prix);
    query.bindValue(":type", type);
    query.bindValue(":dateb", dateB);
    query.bindValue(":qrid", qrId);
    query.bindValue(":idmatch_b", idMatch_b);

    return query.exec();
}


// Modify a ticket in the database
bool Billet::modifierBillet(int id_b, const QDate &newDateB, const QString &new_qrid) {
    // Determine the new type and prix based on the new QRID (first digit)
    QString newType;
    int newPrix = 0;

    if (new_qrid.startsWith("1")) {
        newType = "Virage";
        newPrix = 20;
    } else if (new_qrid.startsWith("2")) {
        newType = "Pelouse";
        newPrix = 40;
    } else if (new_qrid.startsWith("3")) {
        newType = "Enceinte";
        newPrix = 80;
    } else {
        qDebug() << "QRID invalide.";
        return false;
    }

    // Update the database with the new QRID, TYPE, PRIX, and DATEB
    QSqlQuery query;
    query.prepare("UPDATE GS_BILLET SET QRID = :qrid, TYPE = :type, PRIX = :prix, DATEB = :dateb WHERE ID_B = :id_b");
    query.bindValue(":qrid", new_qrid);
    query.bindValue(":type", newType);
    query.bindValue(":prix", newPrix);
    query.bindValue(":dateb", newDateB);
    query.bindValue(":id_b", id_b);

    return query.exec();
}

// Delete a ticket from the database
bool Billet::deleteBillet(int id_b) {
    QSqlQuery query;
    query.prepare("DELETE FROM GS_BILLET WHERE ID_B = :id_b");
    query.bindValue(":id_b", id_b);

    return query.exec();
}
QSqlQuery Billet::searchBillets(const QString &searchTerm) {
    QSqlQuery query;
    query.prepare("SELECT ID_B, PRIX, TYPE, DATEB, QRID FROM GS_BILLET "
                  "WHERE ID_B LIKE :searchTerm OR QRID LIKE :searchTerm OR TYPE LIKE :searchTerm");
    query.bindValue(":searchTerm", "%" + searchTerm + "%");
    query.exec();
    return query;
}


// Fetch all tickets in the database
QSqlQuery Billet::fetchAllBillets() {
    QSqlQuery query;
    query.prepare("SELECT ID_B, PRIX, TYPE, DATEB, QRID FROM GS_BILLET");
    query.exec();
    return query;
}
