#ifndef MATCH_H
#define MATCH_H

#include <QString>
#include <QSqlQuery>
#include <QVector>

class Match {
private:
    int idmatch;
    QString date;
    QString lieu;
    QString etat;

public:
    Match();
    Match(int, QString, QString, QString);

    bool ajouter();
    bool supprimer(int);
    QVector<QVector<QString>> afficher();

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
