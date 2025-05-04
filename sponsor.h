#ifndef SPONSOR_H
#define SPONSOR_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QTableWidget>
#include <QByteArray>
#include <QString>
//#include "arduino.h"  // Include the Arduino header file where the 'arduino' class is defined

namespace Ui {
class sponsor;
}

class sponsor : public QDialog
{
    Q_OBJECT

public:
    explicit sponsor(QWidget *parent = nullptr); // Constructeur pour l'interface graphique
    sponsor(int id_s, QString nom_org, QString produit, QString contribution); // Constructeur pour créer un objet sponsor
    ~sponsor(); // Destructeur

    // Getters
    int getId_s() const { return id_s; }
    QString getNomOrg() const { return nom_org; }
    QString getProduit() const { return produit; }
    QString getContribution() const { return contribution; }

    // Setters
    void setId_s(int id) { id_s = id; }
    void setNomOrg(QString nom) { nom_org = nom; }
    void setProduit(QString prod) { produit = prod; }
    void setContribution(QString cont) { contribution = cont; }

private slots:
    void on_ajouter_clicked();
    void on_modifier_clicked();
    void on_supprimer_clicked();
    void on_tableWidget_cellClicked(int row, int column);
    void on_recherche_clicked();
    void on_tri_clicked();
    void on_annuler_clicked();
    void on_statistique_clicked();
    void on_pdf_clicked();
    void on_btnRemoveImage_clicked();
    void on_btnLoadImage_clicked();
    void on_tri_des_clicked();

    //void updateLineEditsFromArduino(); // Slot pour lire les données Arduino
    void checkMatricule(const QString &matricule); // Vérifier le matricule

private:
    Ui::sponsor *ui;
    int id_s;
    QString nom_org, produit, contribution;

    void afficherSponsors();
    void trier();
    void rechercher();
    void annuler();
    void generatePdfForSponsor(const QString& sponsor);
    void loadTeamSponsorCount();
    void loadSponsorRanking();
    void loadSponsorImage(const QString &sponsorName);
    void paintEvent(QPaintEvent *event);
    QString getSelectedSponsor() const;
    void on_equiepass_clicked();
    void on_billetpass_clicked();
    void on_matchpass_clicked();
    void on_employerpass_clicked();


    QString matriculeBuffer; // Buffer pour accumuler les chiffres

    // 📸 Fonctions d'image
    QByteArray imageToByteArray(const QString &filePath);
    bool saveSponsorImage(const QString &filePath, const QByteArray &data);
    QTimer *serialReadTimer; // Ajouter un timer
    QString receivedData; // Données reçues d'Arduino
    //Arduino arduino;

};

#endif // SPONSOR_H
