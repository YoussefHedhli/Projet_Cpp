#include "match.h"
#include <QDebug>
#include <QSqlError>
#include <QRandomGenerator>

Match::Match() {}

Match::Match(int idmatch, QString equipe1, QString equipe2, QString date, QString lieu, QString etat) {
    this->equipe1 = equipe1;
    this->equipe2 = equipe2;
    this->idmatch = idmatch;
    this->date = date;
    this->lieu = lieu;
    this->etat = etat;
}

bool Match::ajouter() {
    int id = QRandomGenerator::global()->bounded(1000, 9999);

    QSqlQuery query;
    query.prepare("INSERT INTO GS_MATCH (ID_M,EQUIPE1,EQUIPE2, DATEM, LIEU, ETAT) VALUES (:id,:equipe1, :equipe2, TO_DATE(:date, 'YYYY-MM-DD'), :lieu, :etat)");

    query.bindValue(":id", id);
    query.bindValue(":equipe1",equipe1);
    query.bindValue(":equipe2",equipe2);
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
QVector<QVector<QString>> Match::rechercher(QString team) {
    QSqlQuery query;
    query.prepare("SELECT ID_M, EQUIPE1, EQUIPE2, DATEM, LIEU, ETAT FROM GS_MATCH WHERE EQUIPE1 LIKE :team OR EQUIPE2 LIKE :team");
    query.bindValue(":team", "%" + team + "%");

    QVector<QVector<QString>> data;
    if (query.exec()) {
        while (query.next()) {
            QVector<QString> row;
            row.append(query.value(0).toString()); // ID
            row.append(query.value(1).toString()); // Equipe 1
            row.append(query.value(2).toString()); // Equipe 2
            row.append(query.value(3).toString()); // Date
            row.append(query.value(4).toString()); // Lieu
            row.append(query.value(5).toString()); // Etat
            data.append(row);
        }
    } else {
        qDebug() << "Erreur SQL lors de la recherche:" << query.lastError().text();
    }
    return data;
}


QVector<QVector<QString>> Match::afficher() {
    QSqlQuery query("SELECT ID_M, EQUIPE1, EQUIPE2, DATEM, LIEU, ETAT FROM GS_MATCH");  // Added missing comma
    QVector<QVector<QString>> data;

    while (query.next()) {
        QVector<QString> row;
        row.append(query.value(0).toString());
        row.append(query.value(1).toString());
        row.append(query.value(2).toString());
        row.append(query.value(3).toString());
        row.append(query.value(4).toString());
        row.append(query.value(5).toString());
        data.append(row);
    }
    return data;
}


QVector<QVector<QString>> Match::trierParID() {
    QSqlQuery query("SELECT ID_M, EQUIPE1, EQUIPE2, DATEM, LIEU, ETAT FROM GS_MATCH ORDER BY ID_M ASC");

    QVector<QVector<QString>> data;
    while (query.next()) {
        QVector<QString> row;
        row.append(query.value(0).toString()); // ID
        row.append(query.value(1).toString()); // Equipe 1
        row.append(query.value(2).toString()); // Equipe 2
        row.append(query.value(3).toString()); // Date
        row.append(query.value(4).toString()); // Lieu
        row.append(query.value(5).toString()); // Etat
        data.append(row);
    }
    return data;
}


bool Match::modifier(int id) {
    QSqlQuery query;
    query.prepare("UPDATE GS_MATCH SET EQUIPE1 = :equipe1, EQUIPE2 = :equipe2, DATEM = TO_DATE(:date, 'YYYY-MM-DD'), LIEU = :lieu, ETAT = :etat WHERE ID_M = :id");
    query.bindValue(":equipe1", equipe1);
    query.bindValue(":equipe2", equipe2);
    query.bindValue(":date", date);  // Ensure this is in YYYY-MM-DD format
    query.bindValue(":lieu", lieu);
    query.bindValue(":etat", etat);
    query.bindValue(":id", id);  // ID remains unchanged

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la modification du match:" << query.lastError().text();
        return false;
    }
    return true;

}

QVector<QVector<QString>> Match::getMatchesByDate(const QString &selectedDate) {
    QVector<QVector<QString>> matches;
    QSqlQuery query;

    query.prepare("SELECT ID_M, EQUIPE1, EQUIPE2, DATEM, LIEU, ETAT FROM GS_MATCH WHERE DATEM = TO_DATE(:date, 'YYYY-MM-DD')");
    query.bindValue(":date", selectedDate);

    if (query.exec()) {
        while (query.next()) {
            QVector<QString> match;
            for (int i = 0; i < 6; ++i) {
                match.append(query.value(i).toString());
            }
            matches.append(match);
        }
    } else {
        qDebug() << "Query failed:" << query.lastError().text();
    }

    return matches;
}





