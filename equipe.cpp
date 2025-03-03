#include "Equipe.h"
#include <QDebug>
#include <QSqlError>

// Constructeurs
Equipe::Equipe() : idEquipe(0), nom(""), pays("") {}

Equipe::Equipe(int idEquipe, const QString& nom, const QString& pays)
    : idEquipe(idEquipe), nom(nom), pays(pays) {}

// Getters
int Equipe::getIdEquipe() const { return idEquipe; }
QString Equipe::getNom() const { return nom; }
QString Equipe::getPays() const { return pays; }

// Setters
void Equipe::setIdEquipe(int idEquipe) { this->idEquipe = idEquipe; }
void Equipe::setNom(const QString& nom) { this->nom = nom; }
void Equipe::setPays(const QString& pays) { this->pays = pays; }

// Ajouter une équipe à la base de données
bool Equipe::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO GS_EQUIPE (ID_E, NOM_E, PAYS) VALUES (:id, :nom, :pays)");
    query.bindValue(":id", idEquipe);
    query.bindValue(":nom", nom);
    query.bindValue(":pays", pays);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout de l'équipe:" << query.lastError().text();
        return false;
    }

    qDebug() << "Équipe ajoutée: ID =" << idEquipe << ", Nom =" << nom << ", Pays =" << pays;
    return true;
}

// Afficher les équipes
QSqlQueryModel* Equipe::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_E, NOM_E, PAYS FROM GS_EQUIPE");

    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de l'affichage des équipes:" << model->lastError().text();
    } else {
        qDebug() << "Affichage réussi, nombre de lignes:" << model->rowCount();
    }

    return model;
}
bool Equipe::modifier(int id) {
    QSqlQuery query;
    query.prepare("UPDATE GS_EQUIPE SET NOM_E = :nom, PAYS = :pays WHERE ID_E = :id");
    query.bindValue(":nom", nom);
    query.bindValue(":pays", pays);
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification de l'équipe:" << query.lastError().text();
        return false;
    }
    return true;
}
