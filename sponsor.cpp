#include "sponsor.h"
#include "ui_sponsor.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QTableWidget>
#include <QSqlError> // Ajoutez cette ligne pour inclure QSqlError


// Constructeur pour l'interface graphique
sponsor::sponsor(QWidget *parent) : QDialog(parent), ui(new Ui::sponsor) {
    ui->setupUi(this);

    // Connexion des boutons aux slots
    connect(ui->ajouter, &QPushButton::clicked, this, &sponsor::on_ajouter_clicked);
    connect(ui->modifier, &QPushButton::clicked, this, &sponsor::on_modifier_clicked);
    connect(ui->supprimer, &QPushButton::clicked, this, &sponsor::on_supprimer_clicked);

    // Initialisation de l'affichage des sponsors
    afficherSponsors();
}

// Constructeur pour créer un objet sponsor sans UI
sponsor::sponsor(int id_s, QString nom_org, QString produit, QString contribution)
    : id_s(id_s), nom_org(nom_org), produit(produit), contribution(contribution) {
}

// Destructeur
sponsor::~sponsor() {
    delete ui;
}




void sponsor::on_ajouter_clicked() {
    int id_s = ui->lineEdit_id->text().toInt();
    QString nom_org = ui->lineEdit_nom_org->text();
    QString produit = ui->lineEdit_produit->text();
    QString contribution = ui->lineEdit_contribution->text();

    // Vérifier que les champs ne sont pas vides
    if (nom_org.isEmpty() || produit.isEmpty() || contribution.isEmpty()) {
        return; // Ne rien faire si les champs sont vides
    }

    // Vérifier si l'ID existe déjà
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT ID_S FROM GS_SPONSOR WHERE ID_S = :id_s");
    checkQuery.bindValue(":id_s", id_s);

    if (checkQuery.exec() && checkQuery.next()) {
        return; // Ne rien faire si l'ID existe déjà
    }

    // Ajouter le sponsor
    QSqlQuery query;
    query.prepare("INSERT INTO GS_SPONSOR (ID_S, NOM_ORG, PRODUIT, CONTRIBUTION) "
                  "VALUES (:id_s, :nom_org, :produit, :contribution)");
    query.bindValue(":id_s", id_s);
    query.bindValue(":nom_org", nom_org);
    query.bindValue(":produit", produit);
    query.bindValue(":contribution", contribution);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Sponsor ajouté avec succès.");
        afficherSponsors(); // Actualiser l'affichage

        // Vider les champs après un ajout réussi
        ui->lineEdit_id->clear();
        ui->lineEdit_nom_org->clear();
        ui->lineEdit_produit->clear();
        ui->lineEdit_contribution->clear();
    }
}




void sponsor::on_modifier_clicked() {
    int id_s = ui->lineEdit_id->text().toInt();
    QString nom_org = ui->lineEdit_nom_org->text();
    QString produit = ui->lineEdit_produit->text();
    QString contribution = ui->lineEdit_contribution->text();

    // Vérifier que les champs ne sont pas vides
    if (nom_org.isEmpty() || produit.isEmpty() || contribution.isEmpty()) {
        return; // Ne rien faire si les champs sont vides
    }

    // Modifier le sponsor
    QSqlQuery query;
    query.prepare("UPDATE GS_SPONSOR SET NOM_ORG = :nom_org, PRODUIT = :produit, CONTRIBUTION = :contribution "
                  "WHERE ID_S = :id_s");
    query.bindValue(":id_s", id_s);
    query.bindValue(":nom_org", nom_org);
    query.bindValue(":produit", produit);
    query.bindValue(":contribution", contribution);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Sponsor modifié avec succès.");
        afficherSponsors(); // Actualiser l'affichage

        // Vider les champs après une modification réussie
        ui->lineEdit_id->clear();
        ui->lineEdit_nom_org->clear();
        ui->lineEdit_produit->clear();
        ui->lineEdit_contribution->clear();
    }
}

void sponsor::on_supprimer_clicked() {
    int id_s = ui->lineEdit_id->text().toInt();

    // Supprimer le sponsor
    QSqlQuery query;
    query.prepare("DELETE FROM GS_SPONSOR WHERE ID_S = :id_s");
    query.bindValue(":id_s", id_s);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Sponsor supprimé avec succès.");
        afficherSponsors(); // Actualiser l'affichage

        // Vider les champs après une suppression réussie
        ui->lineEdit_id->clear();
        ui->lineEdit_nom_org->clear();
        ui->lineEdit_produit->clear();
        ui->lineEdit_contribution->clear();
    }
}
// Slot pour le clic sur une ligne du QTableWidget
void sponsor::on_tableWidget_cellClicked(int row, int column) {
    Q_UNUSED(column); // Ignorer le paramètre column, car nous n'en avons pas besoin

    // Récupérer les données de la ligne sélectionnée
    QTableWidgetItem *idItem = ui->tableWidget->item(row, 0); // Colonne ID
    QTableWidgetItem *nomOrgItem = ui->tableWidget->item(row, 1); // Colonne Nom Organisation
    QTableWidgetItem *produitItem = ui->tableWidget->item(row, 2); // Colonne Produit
    QTableWidgetItem *contributionItem = ui->tableWidget->item(row, 3); // Colonne Contribution

    // Remplir les champs avec les données de la ligne sélectionnée
    if (idItem && nomOrgItem && produitItem && contributionItem) {
        ui->lineEdit_id->setText(idItem->text());
        ui->lineEdit_nom_org->setText(nomOrgItem->text());
        ui->lineEdit_produit->setText(produitItem->text());
        ui->lineEdit_contribution->setText(contributionItem->text());
    }
}

// Méthode pour afficher les sponsors dans le QTableWidget
void sponsor::afficherSponsors() {
    QSqlQuery query("SELECT * FROM GS_SPONSOR");

    // Effacer le contenu actuel du tableau
    ui->tableWidget->setRowCount(0);

    // Remplir le tableau avec les résultats de la requête
    while (query.next()) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("ID_S").toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("NOM_ORG").toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("PRODUIT").toString()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("CONTRIBUTION").toString()));
    }
}
