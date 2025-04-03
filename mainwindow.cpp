#include "mainwindow.h"
#include "ui_mainwindow.h"
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




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
afficherEquipes();

    afficherStatistiquesPaysGraph();


    // Connexion du bouton "Ajouter" à la méthode ajouterEquipe
    connect(ui->labelajout, &QPushButton::clicked, this, &MainWindow::ajouterEquipe);
connect(ui->bsupp, &QPushButton::clicked, this, &MainWindow::supprimerEquipe);
    connect(ui->bmodif, &QPushButton::clicked, this, &MainWindow::modifierEquipe);
connect(ui->AFF, &QTableView::clicked, this, &MainWindow::on_AFF_clicked);
    connect(ui->Rech, &QPushButton::clicked, this, &MainWindow::rechercherEquipe);
connect(ui->bpdf, &QPushButton::clicked, this, &MainWindow::exporterPDF);
 connect(ui->btri, &QPushButton::clicked, this, &MainWindow::on_btri_clicked);
<<<<<<< HEAD
 connect(ui->up, &QPushButton::clicked, this, &MainWindow::on_updateButton_clicked);
=======

>>>>>>> ab0bf032062a63f601f25ec60cb258c7aea77f06
    // Chargement des images
    QPixmap pix("C:/Users/MSI/Pictures/ft2.png");
    ui->label->setPixmap(pix.scaled(1200, 1100, Qt::KeepAspectRatio));

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

    int id = ui->idline->text().toInt();

    if ( id <= 0) {
        QMessageBox::warning(this, "Erreur", "L'ID doit être un nombre entier positif.");
        return;
    }

    QString nom = ui->nomline->text().trimmed();
    QString pays = ui->payline->text().trimmed();

    if (nom.isEmpty() || pays.isEmpty()) {
        QMessageBox::warning(this, "Champs vides", "Veuillez remplir tous les champs.");
        return;
    }

    // Expression régulière mise à jour : entre 2 et 15 caractères requis
    QRegularExpression regex("^[A-Za-zÀ-ÖØ-öø-ÿ\\s-]{2,15}$");
    if (!regex.match(nom).hasMatch() || !regex.match(pays).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom et le pays doivent contenir entre 2 et 15 lettres uniquement.");
        return;
    }

    Equipe e(id, nom, pays);
    if (e.ajouter()) {
        QMessageBox::information(this, "Succès", "L'équipe a été ajoutée avec succès !");
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
    // Vérifier si une ligne est sélectionnée
    QModelIndex index = ui->AFF->selectionModel()->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une équipe à modifier.");
        return;
    }

    // Récupérer l'ID de l'équipe sélectionnée (Colonne 0)
    QAbstractItemModel *model = ui->AFF->model();
    bool ok;
    int id = model->data(model->index(index.row(), 0)).toInt(&ok);
    if (!ok) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer l'ID de l'équipe.");
        return;
    }

    // Vérifier l'existence des champs
    if (!ui->nomline || !ui->payline) {
        QMessageBox::critical(this, "Erreur", "Champs de modification non trouvés.");
        return;
    }

    // Récupérer les nouvelles valeurs
    QString nom = ui->nomline->text().trimmed();
    QString pays = ui->payline->text().trimmed();

    // Validation : Vérifier que les champs ne sont pas vides
    if (nom.isEmpty() || pays.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs.");
        return;
    }

    // Si les données n'ont pas changé, ne rien faire
    QString nomActuel = model->data(model->index(index.row(), 1)).toString();
    QString paysActuel = model->data(model->index(index.row(), 2)).toString();
    if (nom == nomActuel && pays == paysActuel) {
        QMessageBox::information(this, "Info", "Aucune modification détectée.");
        return;
    }

    // Modifier l'équipe dans la base de données
    Equipe e(id, nom, pays);
    if (e.modifier(id)) {
        QMessageBox::information(this, "Succès", "L'équipe a été modifiée avec succès.");
        afficherEquipes();  // Mettre à jour l'affichage
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification de l'équipe.");
    }
}
void MainWindow::on_AFF_clicked(const QModelIndex &index) {
    if (!index.isValid()) {
        QMessageBox::warning(this, "Erreur", "Sélection invalide.");
        return;
    }

    // Récupérer les valeurs de la ligne sélectionnée
    QAbstractItemModel *model = ui->AFF->model();
    QString nom = model->data(model->index(index.row(), 1)).toString();
    QString pays = model->data(model->index(index.row(), 2)).toString();

    // Afficher les valeurs dans les champs
    ui->nomline->setText(nom);
    ui->payline->setText(pays);

    // Debug : Afficher dans la console
    qDebug() << "Équipe sélectionnée - Nom:" << nom << ", Pays:" << pays;
}
void MainWindow::rechercherEquipe() {
    QString recherche = ui->linerech->text().trimmed();
ui->linerech->clear();
    // Si la recherche est vide, afficher toutes les équipes
    if (recherche.isEmpty()) {
        afficherEquipes();
        return;
    }

    // Préparer le modèle et la requête
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    // Assurez-vous que les noms de colonnes sont corrects et insensibles à la casse
    query.prepare("SELECT * FROM GS_EQUIPE WHERE UPPER(\"NOM_E\") LIKE UPPER(:recherche) OR UPPER(\"PAYS\") LIKE UPPER(:recherche)");

    // Ajouter le paramètre avec des jokers pour une recherche partielle
    query.bindValue(":recherche", "%" + recherche + "%");

    // Exécuter la requête et vérifier les erreurs
    if (query.exec()) {
        model->setQuery(std::move(query));  // Utiliser std::move pour éviter l'erreur de copie
        ui->AFF->setModel(model);
    } else {
        QString errorMsg = "Échec de la recherche : " + query.lastError().text();
        QMessageBox::critical(this, "Erreur", errorMsg);

    }
}
//pdf
void MainWindow::exporterPDF() {
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setResolution(300);  // Améliore la qualité
    QPainter painter(&writer);

    // Charger le logo
    QImage logo("C:/Users/MSI/Pictures/A1.png");  // Remplace par le chemin correct si nécessaire
    if (!logo.isNull()) {
        painter.drawImage(QRect(50, 50, 200, 200), logo);  // Ajuste la position et la taille
    }

    // Titre du PDF
    painter.setFont(QFont("Helvetica", 20, QFont::Bold));
    painter.drawText(QRect(0, 50, writer.width(), 100), Qt::AlignCenter, "Liste des équipes");

    // Souligner le titre
    painter.drawLine(200, 200, writer.width() - 200, 200);

    // Position initiale pour le tableau
    int x = 200;
    int y = 300;
    int rowHeight = 200;
    int colWidth = 700;

    // Définir la police en gras pour l'en-tête
    painter.setFont(QFont("Helvetica", 12, QFont::Bold));

    // Dessiner les bordures et centrer le texte dans chaque cellule
    painter.drawRect(x, y, colWidth, rowHeight);
    painter.drawText(QRect(x, y, colWidth, rowHeight), Qt::AlignCenter, "ID");

    painter.drawRect(x + colWidth, y, colWidth, rowHeight);
    painter.drawText(QRect(x + colWidth, y, colWidth, rowHeight), Qt::AlignCenter, "Nom");

    painter.drawRect(x + 2 * colWidth, y, colWidth, rowHeight);
    painter.drawText(QRect(x + 2 * colWidth, y, colWidth, rowHeight), Qt::AlignCenter, "Pays");

    y += rowHeight;

    // Récupérer les données du QTableView
    QAbstractItemModel *model = ui->AFF->model();
    if (!model) {
        QMessageBox::warning(this, "Erreur", "Aucun modèle de données trouvé !");
        return;
    }

    painter.setFont(QFont("Helvetica", 10));

    for (int row = 0; row < model->rowCount(); ++row) {
        QString id = model->data(model->index(row, 0)).toString();
        QString nom = model->data(model->index(row, 1)).toString();
        QString pays = model->data(model->index(row, 2)).toString();

        // ID


        painter.drawRect(x, y, colWidth, rowHeight);
         painter.drawText(QRect(x, y, colWidth, rowHeight), Qt::AlignCenter, id);

        // Nom
        painter.drawRect(x + colWidth, y, colWidth, rowHeight);
       painter.drawText(QRect(x + colWidth, y, colWidth, rowHeight), Qt::AlignCenter, nom);
        // Pays
        painter.drawRect(x + 2 * colWidth, y, colWidth, rowHeight);
        painter.drawText(QRect(x + 2 * colWidth, y, colWidth, rowHeight), Qt::AlignCenter, pays);
     y += rowHeight;

        // Passe à une nouvelle page si nécessaire
        if (y > writer.height() - 100) {
            writer.newPage();
            y = 200;  // Revenir en haut pour la nouvelle page
        }
    }


    painter.end();
    QMessageBox::information(this, "Succès", "Exportation PDF terminée !");
}


// Function to sort by ID
void MainWindow::triParId() {
    // Check if descending is selected
    bool descending = ui->checkdesc->isChecked();

    // SQL query to sort by ID
    QString sql = "SELECT * FROM GS_EQUIPE ORDER BY ID_E";
    if (descending)
        sql += " DESC";

    qDebug() << "ID Sort Query:" << sql;

    QSqlQuery query;
    if (query.exec(sql)) {
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(query);
        ui->AFF->setModel(model);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la requête : " + query.lastError().text());
        qDebug() << "Query Error:" << query.lastError().text();
    }
}

// Function to sort alphabetically by NOM_E
void MainWindow::triParAlphabet() {
    bool descending = ui->checkdesc->isChecked();

    // Compatible with SQLite and MySQL
    QString sql = "SELECT * FROM GS_EQUIPE ORDER BY LOWER(NOM_E)";
    if (descending) {
        sql += " DESC";
    }

    qDebug() << "Alphabet Sort Query:" << sql;

    QSqlQuery query;
    if (query.exec(sql)) {
        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(query);
        ui->AFF->setModel(model);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la requête : " + query.lastError().text());
        qDebug() << "Query Error:" << query.lastError().text();
    }
}

// Sort by ID when clicking on btri
void MainWindow::on_btri_clicked() {
    triParId();
}

// Sort alphabetically when clicking on btri2
void MainWindow::on_btri2_clicked() {
    triParAlphabet();
}

//stat
void MainWindow::afficherStatistiquesPaysGraph()
{
    // Créer un QPieSeries pour le graphique en secteurs
    QPieSeries *series = new QPieSeries();

    // Créer la requête SQL pour récupérer les données depuis la table GS_EQUIPE
    QSqlQuery query;
    query.prepare("SELECT pays, COUNT(*) FROM GS_EQUIPE GROUP BY pays");

    // Exécuter la requête
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur SQL", "Impossible de récupérer les données : " + query.lastError().text());
        return;
    }

    // Calculer le total des équipes
    double totalEquipes = 0;
    while (query.next()) {
        int nombreEquipes = query.value(1).toInt();
        totalEquipes += nombreEquipes;
    }

    // Revenir à la première ligne de la requête
    query.first();

    // Ajouter les résultats de la requête à la série
    while (query.next()) {
        QString pays = query.value(0).toString();  // Récupérer le nom du pays
        int nombreEquipes = query.value(1).toInt();  // Récupérer le nombre d'équipes pour ce pays
        QPieSlice *slice = series->append(pays, nombreEquipes);  // Ajouter les données à la série

        // Calcul du pourcentage pour chaque pays
        double pourcentage = (nombreEquipes / totalEquipes) * 100;

        // Créer un label formaté avec le pourcentage
        QString label = QString("%1\n%2%").arg(pays).arg(pourcentage, 0, 'f', 1); // Par exemple: "Pays A\n45.0%"

        // Affecter le label avec le pourcentage
        slice->setLabel(label);
        slice->setLabelVisible(true); // Rendre le label visible

        // Personnalisation de l'apparence du label (facultatif)
        slice->setLabelBrush(Qt::black);  // Définir la couleur du texte du label
    }

    // Créer un graphique avec le QPieSeries
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des équipes par pays");

    // Créer un QChartView pour afficher le graphique
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Créer un QLabel pour afficher le pourcentage en dehors du graphique (zone de texte)
    QLabel *pourcentageLabel = new QLabel("Sélectionner un secteur pour voir le pourcentage", this);
    pourcentageLabel->setAlignment(Qt::AlignCenter);

    // Connecter un signal pour détecter la sélection d'un secteur
    connect(series, &QPieSeries::clicked, [this, pourcentageLabel, totalEquipes](QPieSlice *slice) {
        // Récupérer le nombre d'équipes pour le pays du slice sélectionné
        int nombreEquipes = slice->value();

        // Calculer le pourcentage
        double pourcentage = (nombreEquipes / totalEquipes) * 100;

        // Mettre à jour le label avec le pourcentage
        QString label = QString("Pourcentage de %1: %2%").arg(slice->label()).arg(pourcentage, 0, 'f', 1);
        pourcentageLabel->setText(label); // Afficher le pourcentage dans la zone de texte
    });

    // Accéder à la QFrame dans laquelle afficher le graphique (par exemple frameStatistiques)
    QFrame *stat = findChild<QFrame*>("stat");
    if (stat) {
        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(chartView);
        layout->addWidget(pourcentageLabel); // Ajouter le label en dessous du graphique
        stat->setLayout(layout); // Ajouter le QChartView et le QLabe au layout de la QFrame
    } else {
        QMessageBox::critical(this, "Erreur", "La frame pour les statistiques n'a pas été trouvée.");
    }
}
<<<<<<< HEAD
//etat de forme
void MainWindow::on_updateButton_clicked()
{
    // Vérifier si la connexion existe déjà
    QSqlDatabase db;
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        db = QSqlDatabase::addDatabase("QODBC");
        db.setDatabaseName("Source_Remontada");
        db.setUserName("projet");
        db.setPassword("remontada");
    }

    // Vérifier si la connexion s'ouvre correctement
    if (!db.open()) {
        QMessageBox::warning(this, "Erreur", "Impossible de se connecter à la base de données");
        return;
    }

    // Préparer la requête SQL avec protection contre la division par zéro
    QSqlQuery query;
    query.prepare("SELECT IDEQUIPE_P, "
                  "COUNT(CASE WHEN SCORE = 'V' THEN 1 END) AS Victoires, "
                  "COUNT(CASE WHEN SCORE = 'N' THEN 1 END) AS Nuls, "
                  "COUNT(CASE WHEN SCORE = 'D' THEN 1 END) AS Defaites, "
                  "(COUNT(CASE WHEN SCORE = 'V' THEN 1 END) * 3 + COUNT(CASE WHEN SCORE = 'N' THEN 1 END)) / "
                  "NULLIF(COUNT(CASE WHEN SCORE IN ('V', 'N', 'D') THEN 1 END), 0) AS Forme "
                  "FROM participer "
                  "GROUP BY IDEQUIPE_P");

    // Exécuter la requête et vérifier les erreurs
    if (!query.exec()) {
        QMessageBox::warning(this, "Erreur", "Erreur dans l'exécution de la requête : " + query.lastError().text());
        return;
    }

    // Nettoyer le tableau avant de le remplir
    ui->table->clearContents();
    ui->table->setRowCount(0);

    // Variables pour calculer la forme moyenne
    double totalForme = 0;
    int countForme = 0;

    // Ajouter les nouvelles données au QTableWidget
    int row = 0;
    while (query.next()) {
        ui->table->insertRow(row);
        ui->table->setItem(row, 0, new QTableWidgetItem(query.value(0).toString()));  // IDEQUIPE_P
        ui->table->setItem(row, 1, new QTableWidgetItem(query.value(1).toString()));  // Victoires
        ui->table->setItem(row, 2, new QTableWidgetItem(query.value(2).toString()));  // Nuls
        ui->table->setItem(row, 3, new QTableWidgetItem(query.value(3).toString()));  // Defaites
        ui->table->setItem(row, 4, new QTableWidgetItem(query.value(4).toString()));  // Forme

        // Calculer la forme moyenne
        totalForme += query.value(4).toDouble();
        countForme++;

        row++;
    }

    // Vérifier s'il y a des résultats
    if (row > 0 && countForme > 0) {
        double formeMoyenne = totalForme / countForme;
        QString formeText = "Forme moyenne: " + QString::number(formeMoyenne, 'f', 2);
        qDebug() << "Valeur de Forme moyenne:" << formeMoyenne; // Debug
        ui->lforme->setText(formeText);
    } else {
        ui->lforme->setText("Aucune donnée disponible");
    }

    qDebug() << "Connexion réussie.";
    qDebug() << "Requête exécutée.";
}
=======
>>>>>>> ab0bf032062a63f601f25ec60cb258c7aea77f06
