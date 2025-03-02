#include "match.h"
#include <QDebug>
#include <QSqlError>
#include <QRandomGenerator>

Match::Match() {}

Match::Match(int idmatch, QString date, QString lieu, QString etat) {
    this->idmatch = idmatch;
    this->date = date;
    this->lieu = lieu;
    this->etat = etat;
}

bool Match::ajouter() {
    int id = QRandomGenerator::global()->bounded(1000, 9999);

    QSqlQuery query;
    query.prepare("INSERT INTO GS_MATCH (ID_M, DATEM, LIEU, ETAT) VALUES (:id, TO_DATE(:date, 'YYYY-MM-DD'), :lieu, :etat)");

    query.bindValue(":id", id);
    query.bindValue(":date", date);
    query.bindValue(":lieu", lieu);
    query.bindValue(":etat", etat);

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de l'ajout du match:" << query.lastError().text();
        return false;
    }
    return true;
}



bool Match::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM GS_MATCH WHERE ID_M = :id");
    query.bindValue(":id", id);
    return query.exec();
}

QVector<QVector<QString>> Match::afficher() {
    QSqlQuery query("SELECT ID_M, DATEM, LIEU, ETAT FROM GS_MATCH");
    QVector<QVector<QString>> data;

    while (query.next()) {
        QVector<QString> row;
        row.append(query.value(0).toString());
        row.append(query.value(1).toString());
        row.append(query.value(2).toString());
        row.append(query.value(3).toString());
        data.append(row);
    }
    return data;
}
