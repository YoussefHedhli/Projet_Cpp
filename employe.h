#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QDate>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableWidget>
#include <QMap>
#include <QSslSocket>
#include <QtNetwork/QSslSocket>

class employe
{
private:
    int matricule;
    QString nom_em;
    QString prenom_em;
    QDate dateN;
    QString email;
    QString Role;
    QString Mot_de_passe;

public:
    employe();
    employe(int matricule, const QString& nom_em, const QString& prenom_em,  const QDate& dateN, const QString& email, const QString& Role, const QString& Mot_de_passe);

    // Getters
    int getmatricule() const;
    QString getnom_em() const;
    QString getprenom_em() const;
    QDate getdateN() const;
    QString getemail() const;
    QString getRole() const;
    QString getMot_de_passe() const;

    // Setters
    void setmatricule(int matricule);
    void setnom_em(const QString& nom_em);
    void setprenom_em(const QString& prenom_em);
    void setdateN( const QDate& dateN);
    void setemail(const QString& email);
    void setRole(const QString& Role);
    void setMot_de_passe(const QString& Mot_de_passe);

    //CRUD
    // Fonction pour ajouter une équipe dans la base de données
    bool ajouter();
    // Fonction pour supprimer un employé par matricule
    bool supprimer(int matricule);
    bool afficher(QSqlQuery& query);
    bool modifier();
    //METIER BASCIQUE
    QVector<QVector<QString>> rechercherEmploye(const QString& searchValue);
    QVector<QVector<QString>> getAllEmployees();
    void trierEmployes(QTableWidget *tableWidget, int index);
    QMap<QString, int> statistiquesRoles();
    //METIER avancer
    bool verifierAuthentification(const QString &email, const QString &password);
    bool updatePassword(const QString &email, const QString &newPassword);
    bool emailExiste(const QString &email);
    //QString encodeFileToBase64(const QString& filePath);
    static void sendEmail(const QString& expediteur, const QString& destinataire, const QString& sujet, const QString& corps, const QString& filePath);
    //voice authentification****
    //QString reconnaitreMotDePasseParVoix(const QString &modelPath);
    //bool verifierMotDePasseVoix(const QString &motDePasseReconnu);

};

#endif // EMPLOYE_H
