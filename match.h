#ifndef MATCH_H
#define MATCH_H

#include <QString>
#include <QSqlQuery>
#include <QVector>

class Match {
private:
    int idmatch;
    QString equipe1;
    QString equipe2;
    QString date;
    QString lieu;
    QString etat;

public:
    Match();
    Match(int,QString ,QString,QString, QString, QString);

    bool ajouter();
    bool supprimer(int);
    QVector<QVector<QString>> afficher();
    QVector<QVector<QString>> rechercher(QString team);
    QVector<QVector<QString>> trierParID();
    bool modifier(int id);

    // Getters & Setters
    int getIdMatch() const;
    QString getDate() const;
    QString getLieu() const;
    QString getEtat() const;
    void setIdMatch(int);
    void setDate(QString);
    void setLieu(QString);
    void setEtat(QString);
};

#endif // MATCH_H
