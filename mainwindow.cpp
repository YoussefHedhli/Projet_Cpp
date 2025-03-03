#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Equipe.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);  // Appelé une seule fois
afficherEquipes();

    // Connexion du bouton "Ajouter" à la méthode ajouterEquipe
    connect(ui->labelajout, &QPushButton::clicked, this, &MainWindow::ajouterEquipe);
connect(ui->bsupp, &QPushButton::clicked, this, &MainWindow::supprimerEquipe);
    connect(ui->bmodif, &QPushButton::clicked, this, &MainWindow::modifierEquipe);

    // Chargement des images
    QPixmap pix("C:/Users/MSI/Pictures/ft2.png");
    ui->label->setPixmap(pix.scaled(1000, 1000, Qt::KeepAspectRatio));

    QPixmap pix2("C:/Users/MSI/Pictures/dimensions-arcs-cercle-terrain-foot.png");
    ui->label_31->setPixmap(pix2.scaled(450, 450, Qt::KeepAspectRatio));

    QPixmap pix3("C:/Users/MSI/Pictures/A1.png");
    ui->label_6->setPixmap(pix3.scaled(100, 100, Qt::KeepAspectRatio));

    // Affiche toutes les équipes dès l'ouverture
    afficherEquipes();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ajouterEquipe() {
    bool ok;
    int id = ui->idline->text().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Erreur", "L'ID doit être un nombre entier.");
        return;
    }

    QString nom = ui->nomline->text().trimmed();
    QString pays = ui->payline->text().trimmed();

    if (nom.isEmpty() || pays.isEmpty()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs.");
        return;
    }

    Equipe e(id, nom, pays);
    if (e.ajouter()) {
        QMessageBox::information(this, "Succès", "L'équipe a été ajoutée avec succès !");

        // Mettre à jour l'affichage après l'ajout
        afficherEquipes();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout de l'équipe.");
    }
}


void MainWindow::afficherEquipes() {
    Equipe equipe;
    QSqlQueryModel *model = equipe.afficher();

    ui->AFF->setModel(model);  // Associe le modèle à la table view

    // Améliorer l'affichage
    ui->AFF->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->AFF->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->AFF->horizontalHeader()->setStretchLastSection(true);
    ui->AFF->setEditTriggers(QAbstractItemView::NoEditTriggers);  // Désactive l'édition
}

void MainWindow::supprimerEquipe() {
    // Vérifier si une ligne est sélectionnée dans QTableView
    QModelIndex index = ui->AFF->selectionModel()->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner une équipe à supprimer.");
        return;
    }

    // Récupérer l'ID de l'équipe sélectionnée (Colonne 0)
    QString id = ui->AFF->model()->index(index.row(), 0).data().toString();

    // Demande de confirmation avant suppression
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                  "Voulez-vous vraiment supprimer cette équipe ?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) {
        return;
    }

    // Effectuer la suppression dans la base de données
    QSqlQuery query;
    query.prepare("DELETE FROM GS_EQUIPE WHERE ID_E = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "L'équipe a été supprimée avec succès.");

        // Rafraîchir l'affichage du QTableView après suppression
        afficherEquipes();

    } else {
        QMessageBox::critical(this, "Erreur", QString("Échec de la suppression : %1").arg(query.lastError().text()));
    }
}

void MainWindow::modifierEquipe() {
    // Vérifier qu'une ligne est bien sélectionnée dans QTableView
    QModelIndex index = ui->AFF->selectionModel()->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une équipe à modifier.");
        return;
    }

    // Récupérer l'ID de l'équipe sélectionnée (Colonne 0)
    bool ok;
    int id = ui->AFF->model()->index(index.row(), 0).data().toInt(&ok);
    if (!ok) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer l'ID de l'équipe.");
        return;
    }

    // Vérifier que les champs de modification existent
    if (!ui->nomline || !ui->payline) {
        QMessageBox::critical(this, "Erreur", "Champs de modification non trouvés.");
        return;
    }

    // Récupérer les nouvelles valeurs depuis les champs de modification
    QString nom = ui->nomline->text().trimmed();  // Trim pour éviter les espaces inutiles
    QString pays = ui->payline->text().trimmed();

    // Vérifier que les champs ne sont pas vides
    if (nom.isEmpty() || pays.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    // Modifier l'équipe dans la base de données
    Equipe e(id, nom, pays);
    if (e.modifier()) {  // Assurez-vous que la fonction `modifier()` prend bien ces paramètres
        QMessageBox::information(this, "Succès", "L'équipe a été modifiée.");
        afficherEquipes();  // Rafraîchir l'affichage du tableau après modification
    } else {
        QMessageBox::critical(this, "Erreur", "La modification a échoué.");
    }
}

