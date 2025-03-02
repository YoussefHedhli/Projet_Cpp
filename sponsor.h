#ifndef SPONSOR_H
#define SPONSOR_H

#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QTableWidget>

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
    void on_ajouter_clicked(); // Slot pour le bouton "Ajouter"
    void on_modifier_clicked(); // Slot pour le bouton "Modifier"
    void on_supprimer_clicked(); // Slot pour le bouton "Supprimer"
    void on_tableWidget_cellClicked(int row, int column); // Slot pour le clic sur une ligne du tableau

private:
    Ui::sponsor *ui; // Interface utilisateur
    int id_s; // Attributs de la classe
    QString nom_org, produit, contribution;

    void afficherSponsors(); // Méthode pour afficher les sponsors dans le QTableWidget
};

#endif // SPONSOR_H
