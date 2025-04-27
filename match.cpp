#include "match.h"
#include <QDebug>
#include <QSqlError>
#include <QRandomGenerator>
#include <QDate>

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


QVector<QVector<QString>> Match::trierPar(const QString& sortOption) {
    QString orderByClause;

    // Determine the sorting order based on the selected option
    if (sortOption == "ID Ascending") {
        orderByClause = "ORDER BY ID_M ASC";
    } else if (sortOption == "ID Descending") {
        orderByClause = "ORDER BY ID_M DESC";
    } else if (sortOption == "A-Z") {
        orderByClause = "ORDER BY EQUIPE1 ASC";  // Sort by Team 1 (Equipe 1)
    } else if (sortOption == "Z-A") {
        orderByClause = "ORDER BY EQUIPE1 DESC";  // Sort by Team 1 (Equipe 1)
    } else if (sortOption == "Date Ascending") {
        orderByClause = "ORDER BY DATEM ASC";  // Sort by Date
    } else if (sortOption == "Date Descending") {
        orderByClause = "ORDER BY DATEM DESC";  // Sort by Date
    }

    // Construct the SQL query with dynamic ORDER BY clause
    QString queryStr = QString("SELECT ID_M, EQUIPE1, EQUIPE2, DATEM, LIEU, ETAT FROM GS_MATCH %1").arg(orderByClause);
    QSqlQuery query(queryStr);

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

QMap<QDate, QList<QString>> Match::getMatchStatesPerDate() {
    QMap<QDate, QList<QString>> map;
    QSqlQuery query("SELECT DATEM, ETAT FROM GS_MATCH");

    while (query.next()) {
        QString dateStr = query.value(0).toString();
        QString etat = query.value(1).toString();

        QDateTime datetime = QDateTime::fromString(dateStr, Qt::ISODate);
        QDate date = datetime.date();

        qDebug() << "Date:" << date << "Etat:" << etat;

        if (date.isValid()) {
            map[date].append(etat);
        } else {
            qDebug() << "Invalid date:" << dateStr;
        }
    }

    return map;
}

void Match::updateMatchScore(bool isMatchCancelled, int scoreTeamA, int scoreTeamB)
{
    QSqlQuery query;

    // If the match is cancelled, we set score to 0
    if (isMatchCancelled) {
        scoreTeamA = 0;
        scoreTeamB = 0;
    }

    // Debugging: Ensure the function is being called correctly and scores are being passed
    qDebug() << "Updating match score: Match Cancelled? " << isMatchCancelled
             << " Score Team A: " << scoreTeamA << " Score Team B: " << scoreTeamB;

    // Generate random match and team IDs to insert them into the tables (only for testing purposes)
    int randomMatchID = QRandomGenerator::global()->bounded(1000); // Random match ID
    int randomEquipID = QRandomGenerator::global()->bounded(1000); // Random team ID

    // Insert random match into GS_MATCH to ensure IDMATCH_P is valid
    query.prepare("INSERT INTO GS_MATCH (ID_M) VALUES (?)");
    query.addBindValue(randomMatchID);
    if (!query.exec()) {
        qDebug() << "Error inserting match into GS_MATCH: " << query.lastError().text();
        return;
    }

    // Insert random team into GS_EQUIPE to ensure IDEQUIP_P is valid
    query.prepare("INSERT INTO GS_EQUIPE (ID_E) VALUES (?)");
    query.addBindValue(randomEquipID);
    if (!query.exec()) {
        qDebug() << "Error inserting team into GS_EQUIPE: " << query.lastError().text();
        return;
    }

    // Insert the match score into the 'participer' table with valid random IDs
    query.prepare("INSERT INTO participer (IDMATCH_P, IDEQUIPE_P, score) VALUES (?, ?, ?)");
    query.addBindValue(randomMatchID); // Match ID from GS_MATCH
    query.addBindValue(randomEquipID); // Team ID from GS_EQUIPE
    query.addBindValue(scoreTeamA);    // Score for team A
    query.addBindValue(scoreTeamB);    // Score for team B

    // If the match is cancelled, ensure that score is set to 0
    if (isMatchCancelled) {
        query.addBindValue(0);  // Set score to 0 for both teams if match is cancelled
    }

    if (!query.exec()) {
        qDebug() << "Error inserting match score into participer: " << query.lastError().text();
    } else {
        qDebug() << "Match score successfully updated!";
    }
}












