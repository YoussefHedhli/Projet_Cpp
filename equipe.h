#ifndef EQUIPE_H
#define EQUIPE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Equipe {
private:
    int idEquipe;
    QString nom;
    QString pays;

public:
    // Constructeurs
    Equipe();
    Equipe(int idEquipe, const QString& nom, const QString& pays);

    // Getters
    int getIdEquipe() const;
    QString getNom() const;
    QString getPays() const;

    // Setters
    void setIdEquipe(int idEquipe);
    void setNom(const QString& nom);
    void setPays(const QString& pays);

    // Méthodes
    bool ajouter();                // Ajouter une équipe
    QSqlQueryModel* afficher();    // Afficher toutes les équipes
    bool modifier(int id);
};

#endif // EQUIPE_H
