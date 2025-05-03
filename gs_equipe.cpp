#include "gs_equipe.h"
#include "ui_gs_equipe.h"
#include "Equipe.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSlice>
#include <QVBoxLayout>
#include <QSqlTableModel>
#include <QProcess>
#include <QTextStream>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QPainter>


gs_equipe::gs_equipe(QWidget *parent)
    : QMainWindow(parent)
    ,  ui(new Ui::gs_equipe)
{
    ui->setupUi(this);
afficherEquipes();
    afficherStatistiques();
    // Connexion du bouton "Ajouter" à la méthode ajouterEquipe
    connect(ui->labelajout, &QPushButton::clicked, this, &gs_equipe::ajouterEquipe);
connect(ui->bsupp, &QPushButton::clicked, this, &gs_equipe::supprimerEquipe);
    connect(ui->bmodif, &QPushButton::clicked, this, &gs_equipe::modifierEquipe);
connect(ui->AFF, &QTableView::clicked, this, &gs_equipe::on_AFF_clicked);
    connect(ui->Rech, &QPushButton::clicked, this, &gs_equipe::rechercherEquipe);
connect(ui->bpdf, &QPushButton::clicked, this, &gs_equipe::exporterPDF);
 connect(ui->up, &QPushButton::clicked, this, &gs_equipe::on_updateButton_clicked);
 // Connecter le signal de changement de texte à ta fonction d’affichage
 connect(ui->comboTactique, &QComboBox::currentTextChanged, this, [&]() {
     // Appel de la méthode afficherTactiqueGraphique depuis l'instance Equipe
     equipe.afficherTactiqueGraphique(ui->comboTactique->currentText()
, ui->label_4, {ui->l1, ui->l2, ui->l3, ui->l4, ui->l5, ui->l6, ui->l7, ui->l8, ui->l9, ui->l10, ui->l11});
 });
 // Dans le constructeur MainWindow :
 connect(ui->combotri, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &gs_equipe::onComboTriChanged);
 connect(ui->up, &QPushButton::clicked, this, &gs_equipe::on_updateButton_clicked);
 connect(ui->matchpass, &QPushButton::clicked, this, &gs_equipe::on_matchpass_clicked);

    // Affiche toutes les équipes dès l'ouverture
    afficherEquipes();
}
gs_equipe::~gs_equipe()  // Changed from MainWindow
{
    delete ui;
}

void gs_equipe::paintEvent(QPaintEvent *event) {
    // Create a QPainter object to draw on the window
    QPainter painter(this);

    // Load background image
    QPixmap pix("C:/Users/AMEN WORKSTATION/Desktop/projet/untitled/bg.jpg");
    if (pix.isNull()) {
        qDebug() << "Failed to load bg.jpg. Check the file path.";
    } else {
        // Scale the image to fit the entire window size
        pix = pix.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

        // Draw the background image directly on the window
        painter.drawPixmap(0, 0, pix);
    }

    // Optionally, you can also display the logo inside the label
    QPixmap logoPix("C:/Users/AMEN WORKSTATION/Desktop/projet/untitled/ball.png");
    if (!logoPix.isNull()) {
        // Use QLabel to display the logo and set it to fit inside the label's area
        ui->ball->setPixmap(logoPix.scaled(ui->ball->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
        ui->ball->show();  // Ensure the label is visible with the logo
    }

    // Call the parent class paintEvent to allow other painting to occur
    QMainWindow::paintEvent(event);
}






void gs_equipe::on_matchpass_clicked()
{
    this->close();  // Close only the gs_equipe window
}

void gs_equipe::ajouterEquipe()
{
    int id = ui->idline->text().toInt();
    QString nom = ui->nomline->text();
    QString pays = ui->payline->text();
    QString tactique = ui->comboTactique->currentText();

    Equipe e(id, nom, pays, tactique);
    if (e.ajouter()) {
        QMessageBox::information(this, "Succès", "Équipe ajoutée !");
        afficherEquipes(); // Rafraîchir le tableau
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'ajout.");
    }
}
void gs_equipe::afficherEquipes() {
    Equipe equipe;
    QSqlQueryModel *model = equipe.afficher();

    ui->AFF->setModel(model);  // Associe le modèle à la table view

    // Améliorer l'affichage
    ui->AFF->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->AFF->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->AFF->horizontalHeader()->setStretchLastSection(true);
    ui->AFF->setEditTriggers(QAbstractItemView::NoEditTriggers);  // Désactive l'édition
}

void gs_equipe::supprimerEquipe() {
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
//appel de modifier
void gs_equipe::modifierEquipe() {
    QModelIndex index = ui->AFF->selectionModel()->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une équipe à modifier.");
        return;
    }

    QAbstractItemModel *model = ui->AFF->model();
    bool ok;
    int id = model->data(model->index(index.row(), 0)).toInt(&ok);
    if (!ok) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer l'ID de l'équipe.");
        return;
    }

    if (!ui->nomline || !ui->payline || !ui->comboTactique) {
        QMessageBox::critical(this, "Erreur", "Champs de modification non trouvés.");
        return;
    }

    QString nom = ui->nomline->text().trimmed();
    QString pays = ui->payline->text().trimmed();
    QString tactique = ui->comboTactique->currentText();  // Récupérer la tactique sélectionnée

    if (nom.isEmpty() || pays.isEmpty() || tactique.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    // Comparer avec les données actuelles
    QString nomActuel = model->data(model->index(index.row(), 1)).toString();
    QString paysActuel = model->data(model->index(index.row(), 2)).toString();
    QString tactiqueActuelle = model->data(model->index(index.row(), 3)).toString();

    if (nom == nomActuel && pays == paysActuel && tactique == tactiqueActuelle) {
        QMessageBox::information(this, "Info", "Aucune modification détectée.");
        return;
    }

    // Appliquer la modification
    Equipe e(id, nom, pays, tactique);
    if (e.modifier(id)) {
        QMessageBox::information(this, "Succès", "L'équipe a été modifiée avec succès.");
        afficherEquipes();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification de l'équipe.");
    }
}

void gs_equipe::on_AFF_clicked(const QModelIndex &index) {
    if (!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Sélection invalide.");
        return;
    }

    // Récupérer les valeurs de la ligne sélectionnée
    QAbstractItemModel *model = ui->AFF->model();
    QString nom = model->data(model->index(index.row(), 1)).toString();
    QString pays = model->data(model->index(index.row(), 2)).toString();
    QString tactique = model->data(model->index(index.row(), 3)).toString(); // Assurez-vous que la tactique est dans la bonne colonne

    // Afficher les valeurs dans les champs
    ui->nomline->setText(nom);
    ui->payline->setText(pays);
    ui->comboTactique->setCurrentText(tactique);


    // Debug : Afficher dans la console
    qDebug() << "Équipe sélectionnée - Nom:" << nom << ", Pays:" << pays << ", Tactique:" << tactique;

    // Appel de la méthode pour afficher la tactique graphique de l'équipe sélectionnée
    equipe.afficherTactiqueGraphique(tactique, ui->label_4, {ui->l1, ui->l2, ui->l3, ui->l4, ui->l5, ui->l6, ui->l7, ui->l8, ui->l9, ui->l10, ui->l11});
}
//
//appel de recherche
void gs_equipe::rechercherEquipe() {
    QString recherche = ui->linerech->text().trimmed();
    ui->linerech->clear();

    // Si la recherche est vide, afficher toutes les équipes
    if (recherche.isEmpty()) {
        afficherEquipes();
        return;
    }

    // Appeler la méthode rechercherEquipe dans Equipe
    QSqlQueryModel* model = Equipe::rechercherEquipe(recherche);

    if (model) {
        ui->AFF->setModel(model);
    }
}

// appel pdf
void gs_equipe::exporterPDF() {
    // Assurez-vous que 'tableView' et 'fileName' sont correctement définis
    equipe.exporterPDF(ui->AFF);

}
//appel stat
void gs_equipe::afficherStatistiques() {
    // Trouver la QFrame où afficher les statistiques (par exemple, "stat")
    QFrame *stat = findChild<QFrame*>("stat");
    if (stat) {
        // Appeler la méthode de Equipe pour afficher les statistiques dans cette QFrame
        Equipe::afficherStatistiquesPaysGraph(stat);
    } else {
        QMessageBox::critical(this, "Erreur", "La frame pour les statistiques n'a pas été trouvée.");
    }
}
//appel etat de forme

void gs_equipe::on_updateButton_clicked() {

    Equipe equipe;

    // Récupérer les résultats de l'état de forme
    QList<QList<QVariant>> resultats = equipe.calculerEtatDeForme();

    // Nettoyer le tableau avant de le remplir
    ui->table->clearContents();
    ui->table->setRowCount(0);

    // Ajouter les nouvelles données au QTableWidget
    int row = 0;
    for (const auto& ligne : resultats) {
        ui->table->insertRow(row);
        ui->table->setItem(row, 0, new QTableWidgetItem(ligne[0].toString()));  // IDEQUIPE_P
        ui->table->setItem(row, 1, new QTableWidgetItem(ligne[1].toString()));  // Victoires
        ui->table->setItem(row, 2, new QTableWidgetItem(ligne[2].toString()));  // Nuls
        ui->table->setItem(row, 3, new QTableWidgetItem(ligne[3].toString()));  // Defaites
        ui->table->setItem(row, 4, new QTableWidgetItem(ligne[4].toString()));  // Forme
        row++;
    }
    // Calculer la forme moyenne
    double formeMoyenne = equipe.calculerFormeMoyenne(resultats);
    QString formeText = "Forme moyenne: " + QString::number(formeMoyenne, 'f', 2);

    if (row > 0) {
        ui->lforme->setText(formeText);
    } else {
        ui->lforme->setText("Aucune donnée disponible");
    }

    qDebug() << "Connexion réussie.";
    qDebug() << "Requête exécutée.";
}
//appel tactique
void gs_equipe::on_btnTactique_clicked()
{
    QString tactiqueChoisie = ui->comboTactique->currentText();

    // Créer une instance de la classe Equipe
    Equipe equipe;

    // Créer une liste des labels des joueurs
    QList<QLabel*> joueurs = {
        ui->l1, ui->l2, ui->l3, ui->l4, ui->l5, ui->l6, ui->l7, ui->l8, ui->l9, ui->l10, ui->l11
    };

    // Appeler la méthode pour afficher la tactique
    equipe.afficherTactiqueGraphique(tactiqueChoisie, ui->label_4, joueurs);
}
void gs_equipe::onComboTriChanged(int index) {
    QString selectedText = ui->combotri->itemText(index);
    Equipe e;
    QSqlQueryModel* model = nullptr;

    if (selectedText == "Tri par ID (croissant)") {
        model = e.trierParId(true);  // Utilise votre méthode existante
    }
    else if (selectedText == "Tri par ID (décroissant)") {
        model = e.trierParId(false);
    }
    else if (selectedText == "Tri alphabétique (A-Z)") {
        model = e.triParAlphabet(true);
    }
    else if (selectedText == "Tri alphabétique (Z-A)") {
        model = e.triParAlphabet(false);
    }

    if (model) {
        ui->AFF->setModel(model);
    }
}
