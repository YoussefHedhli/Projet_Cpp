#include "equipe.h"
#include "qpushbutton.h"
#include <QDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QFileDialog>  // Ajouter cette ligne pour éviter l'erreur
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPieSeries>
#include <QPieSlice>
#include <QChart>
#include <QChartView>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDebug>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSlice>
#include <QSqlTableModel>
#include <QtCharts/QChartView>
#include <QObject>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QLineEdit>
#include <QTimer>
#include <QPushButton>
#include <QProcess>
#include <QTextStream>



QMap<QString, QString> Equipe::tactiquesCache;
// Constructeurs
Equipe::Equipe() : idEquipe(0), nom(""), pays(""), tactique("") {}

Equipe::Equipe(int idEquipe, const QString& nom, const QString& pays, const QString &tactique)
    : idEquipe(idEquipe), nom(nom), pays(pays), tactique(tactique) {}
// Getters
int Equipe::getIdEquipe() const { return idEquipe; }
QString Equipe::getNom() const { return nom; }
QString Equipe::getPays() const { return pays; }
QString Equipe::gettactique() const { return tactique; }
// Setters
void Equipe::setIdEquipe(int idEquipe) { this->idEquipe = idEquipe; }
void Equipe::setNom(const QString& nom) { this->nom = nom; }
void Equipe::setPays(const QString& pays) { this->pays = pays; }
void Equipe::settactique(const QString& tactique) {
    this->tactique = tactique;
}
//

// Ajouter une équipe à la base de données
bool Equipe::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO GS_EQUIPE (ID_E, NOM_E, PAYS, TACTIQUE) VALUES (:id, :nom, :pays, :tactique)");
    query.bindValue(":id", idEquipe);
    query.bindValue(":nom", nom);
    query.bindValue(":pays", pays);
    query.bindValue(":tactique", tactique);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'ajout de l'équipe:" << query.lastError().text();
        return false;
    }


    qDebug() << "Équipe ajoutée: ID =" << idEquipe << ", Nom =" << nom << ", Pays =" << pays << ", Tactique =" << tactique;
    return true;
}

// Afficher les équipes
QSqlQueryModel* Equipe::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT ID_E, NOM_E, PAYS, TACTIQUE FROM GS_EQUIPE");

    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors de l'affichage des équipes:" << model->lastError().text();
    } else {
        qDebug() << "Affichage réussi, nombre de lignes:" << model->rowCount();
    }

    return model;
}
//modifier
bool Equipe::modifier(int id) {
    QSqlQuery query;
    query.prepare("UPDATE GS_EQUIPE SET NOM_E = :nom, PAYS = :pays, TACTIQUE = :tactique WHERE ID_E = :id");
    query.bindValue(":nom", nom);
    query.bindValue(":pays", pays);
    query.bindValue(":tactique", tactique);  // Ajouté ici
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification de l'équipe:" << query.lastError().text();
        return false;
    }
    if (!query.exec()) {
        qDebug() << "Erreur lors de la modification de l'équipe:" << query.lastError().text();
        return false;
    }

    if (query.numRowsAffected() == 0) {
        qDebug() << "Aucune ligne modifiée. Vérifie si l'ID existe et si les valeurs sont différentes.";
    }

    return true;

    return true;
}


// Supprimer une équipe par son ID
bool Equipe::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM GS_EQUIPE WHERE ID_E = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la suppression de l'équipe:" << query.lastError().text();
        return false;
    }

    qDebug() << "Équipe supprimée avec succès.";
    return true;
}


QSqlQueryModel* Equipe::trierParId(bool asc) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QString order = asc ? "ASC" : "DESC";
    QString query = "SELECT ID_E, NOM_E, PAYS, TACTIQUE FROM GS_EQUIPE ORDER BY ID_E " + order;

    model->setQuery(query);

    // Vérification des erreurs SQL
    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors du tri par ID:" << model->lastError().text();
        delete model;
        return nullptr;
    }

    // Vérifier si le modèle contient des données
    if (model->rowCount() == 0) {
        qDebug() << "Aucune donnée trouvée après tri";
    }

    return model;
}


// Trier les équipes par nom (alphabetiquement)
QSqlQueryModel* Equipe::triParAlphabet(bool asc) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QString order = asc ? "ASC" : "DESC";
    QString query = "SELECT ID_E, NOM_E, PAYS, TACTIQUE FROM GS_EQUIPE ORDER BY NOM_E " + order;

    model->setQuery(query);

    // Vérification des erreurs SQL
    if (model->lastError().isValid()) {
        qDebug() << "Erreur lors du tri par nom:" << model->lastError().text();
        delete model; // Libérer la mémoire si une erreur se produit
        return nullptr; // Retourner nullptr si une erreur survient
    }

    return model;
}
//pdf

void Equipe::exporterPDF(QTableView *tableView) {  // Si vous ne voulez pas utiliser fileName
    QString fileToSave = QFileDialog::getSaveFileName(nullptr, "Exporter en PDF", "", "Fichiers PDF (*.pdf)");
    if (fileToSave.isEmpty()) return;

    QPdfWriter writer(fileToSave);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setResolution(300);  // Améliorer la qualité de l'image
    QPainter painter(&writer);

    // Charger et dessiner le logo
    QImage logo("C:/Users/MSI/Pictures/A1.png");  // Remplacez par le chemin correct si nécessaire
    if (!logo.isNull()) {
        painter.drawImage(QRect(50, 50, 200, 200), logo);  // Ajuste la position et la taille du logo
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
    int colWidth = 500;  // Réduire la largeur des autres colonnes pour plus d'espace

    // Définir la police pour les en-têtes du tableau
    painter.setFont(QFont("Helvetica", 12, QFont::Bold));

    // Dessiner les bordures et centrer le texte dans chaque cellule pour l'en-tête
    painter.drawRect(x, y, colWidth, rowHeight);
    painter.drawText(QRect(x, y, colWidth, rowHeight), Qt::AlignCenter, "ID");

    painter.drawRect(x + colWidth, y, colWidth, rowHeight);
    painter.drawText(QRect(x + colWidth, y, colWidth, rowHeight), Qt::AlignCenter, "Nom");

    painter.drawRect(x + 2 * colWidth, y, colWidth, rowHeight);
    painter.drawText(QRect(x + 2 * colWidth, y, colWidth, rowHeight), Qt::AlignCenter, "Pays");

    painter.drawRect(x + 3 * colWidth, y, colWidth, rowHeight);  // Nouvelle colonne pour la tactique
    painter.drawText(QRect(x + 3 * colWidth, y, colWidth, rowHeight), Qt::AlignCenter, "Tactique");

    y += rowHeight;  // Déplacer la position pour les données

    // Récupérer les données du QTableView
    QAbstractItemModel *model = tableView->model();
    if (!model) {
        QMessageBox::warning(nullptr, "Erreur", "Aucun modèle de données trouvé !");
        return;
    }

    // Définir la police pour les données du tableau
    painter.setFont(QFont("Helvetica", 10));

    // Dessiner les données du tableau
    for (int row = 0; row < model->rowCount(); ++row) {
        QString id = model->data(model->index(row, 0)).toString();
        QString nom = model->data(model->index(row, 1)).toString();
        QString pays = model->data(model->index(row, 2)).toString();
        QString tactique = model->data(model->index(row, 3)).toString();  // Récupérer la tactique de la quatrième colonne

        // Dessiner les données de chaque ligne
        painter.drawRect(x, y, colWidth, rowHeight);
        painter.drawText(QRect(x, y, colWidth, rowHeight), Qt::AlignCenter, id);

        painter.drawRect(x + colWidth, y, colWidth, rowHeight);
        painter.drawText(QRect(x + colWidth, y, colWidth, rowHeight), Qt::AlignCenter, nom);

        painter.drawRect(x + 2 * colWidth, y, colWidth, rowHeight);
        painter.drawText(QRect(x + 2 * colWidth, y, colWidth, rowHeight), Qt::AlignCenter, pays);

        painter.drawRect(x + 3 * colWidth, y, colWidth, rowHeight);  // Nouvelle colonne pour la tactique
        painter.drawText(QRect(x + 3 * colWidth, y, colWidth, rowHeight), Qt::AlignCenter, tactique);

        y += rowHeight;

        // Si nécessaire, ajouter une nouvelle page
        if (y > writer.height() - 100) {
            writer.newPage();
            y = 200;  // Revenir en haut pour la nouvelle page
        }
    }

    // Terminer le dessin
    painter.end();
    QMessageBox::information(nullptr, "Succès", "Exportation PDF terminée !");
}
//recherche
QSqlQueryModel* Equipe::rechercherEquipe(const QString& recherche) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // Préparer la requête pour rechercher par nom ou pays (insensible à la casse)
    query.prepare("SELECT * FROM GS_EQUIPE WHERE UPPER(\"NOM_E\") LIKE UPPER(:recherche) OR UPPER(\"PAYS\") LIKE UPPER(:recherche)");

    // Ajouter le paramètre avec des jokers pour une recherche partielle
    query.bindValue(":recherche", "%" + recherche + "%");

    // Exécuter la requête et vérifier les erreurs
    if (query.exec()) {
        model->setQuery(std::move(query));  // Utiliser std::move pour éviter l'erreur de copie
    } else {
        // Si la requête échoue, on peut retourner un modèle vide ou un message d'erreur
        QString errorMsg = "Échec de la recherche : " + query.lastError().text();
        QMessageBox::critical(nullptr, "Erreur", errorMsg);
        return nullptr;
    }

    return model;
}
//fcte statistique
void Equipe::afficherStatistiquesPaysGraph(QFrame* stat) {
    QPieSeries *series = new QPieSeries();

    QSqlQuery query;
    query.prepare("SELECT pays, COUNT(*) FROM GS_EQUIPE GROUP BY pays");

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Erreur SQL", "Impossible de récupérer les données : " + query.lastError().text());
        return;
    }

    double totalEquipes = 0;
    while (query.next()) {
        totalEquipes += query.value(1).toInt();
    }

    // Réexécuter la requête pour ajouter les tranches
    query.exec();

    QLabel *pourcentageLabel = new QLabel("Survolez un secteur pour voir le pourcentage");
    pourcentageLabel->setAlignment(Qt::AlignCenter);

    while (query.next()) {
        QString pays = query.value(0).toString();
        int nombreEquipes = query.value(1).toInt();
        double pourcentage = (nombreEquipes / totalEquipes) * 100;

        QPieSlice *slice = series->append(pays, nombreEquipes);
        slice->setLabelVisible(true);
        slice->setLabel(QString("%1\n%2%").arg(pays).arg(pourcentage, 0, 'f', 1));
        slice->setLabelBrush(Qt::black);

        // 🔁 Connecter le signal de survol;;
        QObject::connect(slice, &QPieSlice::hovered, [=](bool hovered) {
            if (hovered) {
                pourcentageLabel->setText(QString("Pays : %1 — %2% des équipes").arg(pays).arg(pourcentage, 0, 'f', 1));
            } else {
                pourcentageLabel->setText("Survolez un secteur pour voir le pourcentage");
            }
        });
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des équipes par pays");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    if (stat) {
        // Supprimer ancien layout s’il existe
        if (stat->layout()) {
            QLayoutItem *item;
            while ((item = stat->layout()->takeAt(0))) {
                delete item->widget();
                delete item;
            }
            delete stat->layout();
        }

        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(chartView);
        layout->addWidget(pourcentageLabel);
        stat->setLayout(layout);
    } else {
        QMessageBox::critical(nullptr, "Erreur", "La frame pour les statistiques n'a pas été trouvée.");
    }
}

//fcte etat de forme

QList<QList<QVariant>> Equipe::calculerEtatDeForme() {
    QSqlDatabase db;

    QSqlQuery query;
    query.prepare("SELECT IDEQUIPE_P, "
                  "COUNT(CASE WHEN TO_NUMBER(REGEXP_SUBSTR(SCORE, '^[0-9]+')) < TO_NUMBER(REGEXP_SUBSTR(SCORE, '[0-9]+$', 1)) THEN 1 END) AS Victoires, "
                  "COUNT(CASE WHEN TO_NUMBER(REGEXP_SUBSTR(SCORE, '^[0-9]+')) = TO_NUMBER(REGEXP_SUBSTR(SCORE, '[0-9]+$', 1)) THEN 1 END) AS Nuls, "
                  "COUNT(CASE WHEN TO_NUMBER(REGEXP_SUBSTR(SCORE, '^[0-9]+')) > TO_NUMBER(REGEXP_SUBSTR(SCORE, '[0-9]+$', 1)) THEN 1 END) AS Defaites, "
                  "((COUNT(CASE WHEN TO_NUMBER(REGEXP_SUBSTR(SCORE, '^[0-9]+')) < TO_NUMBER(REGEXP_SUBSTR(SCORE, '[0-9]+$', 1)) THEN 1 END) * 3) + "
                  " COUNT(CASE WHEN TO_NUMBER(REGEXP_SUBSTR(SCORE, '^[0-9]+')) = TO_NUMBER(REGEXP_SUBSTR(SCORE, '[0-9]+$', 1)) THEN 1 END)) / "
                  "NULLIF(COUNT(SCORE), 0) AS Forme "
                  "FROM participer "
                  "WHERE REGEXP_LIKE(SCORE, '^[0-9]+-[0-9]+$') "
                  "GROUP BY IDEQUIPE_P");



    if (!query.exec()) {
        QMessageBox::warning(nullptr, "Erreur", "Erreur dans l'exécution de la requête : " + query.lastError().text());
        return {};
    }

    QList<QList<QVariant>> resultats;

    while (query.next()) {
        QList<QVariant> ligne;
        ligne.append(query.value(0)); // IDEQUIPE_P
        ligne.append(query.value(1)); // Victoires
        ligne.append(query.value(2)); // Nuls
        ligne.append(query.value(3)); // Defaites
        ligne.append(query.value(4)); // Forme
        resultats.append(ligne);
    }

    return resultats;
}

double Equipe::calculerFormeMoyenne(const QList<QList<QVariant>>& resultats) {
    double totalForme = 0;
    int countForme = 0;

    for (const auto& ligne : resultats) {
        totalForme += ligne[4].toDouble();
        countForme++;
    }

    if (countForme > 0) {
        return totalForme / countForme;
    }
    return 0;
}

//tactique
void Equipe::placerJoueur(QWidget *joueur, int x, int y)
{
    joueur->move(x, y);
    joueur->show();
}

void Equipe::afficherTactiqueGraphique(const QString &tactique, QWidget *label, QList<QLabel*> joueurs)
{
    int w = label->width();
    int h = label->height();
   //exemple :
    qDebug() << "Width of label: " << w;

    if (tactique == "4-4-2") {
        // Horizontale : Défense à gauche → Attaque à droite
        int def_x = 50;
        int mid_x = 160;
        int att_x = 270;
        int spacing_y = h / 6;

        // Défense (4)
        placerJoueur(joueurs[0], def_x, spacing_y * 1);
        placerJoueur(joueurs[1], def_x, spacing_y * 2);
        placerJoueur(joueurs[2], def_x, spacing_y * 3);
        placerJoueur(joueurs[3], def_x, spacing_y * 4);

        // Milieu (4)
        placerJoueur(joueurs[4], mid_x, spacing_y * 1);
        placerJoueur(joueurs[5], mid_x, spacing_y * 2);
        placerJoueur(joueurs[6], mid_x, spacing_y * 3);
        placerJoueur(joueurs[7], mid_x, spacing_y * 4);

        // Attaque (2)
        placerJoueur(joueurs[8], att_x, spacing_y * 2);
        placerJoueur(joueurs[9], att_x, spacing_y * 3);
    }
    else if (tactique == "5-4-1") {
        int def_x = 50;
        int mid_x = 160;
        int att_x = 270;
        int spacing_y = h / 6;

        // Défense (5)
        placerJoueur(joueurs[0], def_x, spacing_y * 1);
        placerJoueur(joueurs[1], def_x, spacing_y * 2);
        placerJoueur(joueurs[2], def_x, spacing_y * 3);
        placerJoueur(joueurs[3], def_x, spacing_y * 4);
        placerJoueur(joueurs[4], def_x, spacing_y * 5);

        // Milieu (4)
        placerJoueur(joueurs[5], mid_x, spacing_y * 2);
        placerJoueur(joueurs[6], mid_x, spacing_y * 3);
        placerJoueur(joueurs[7], mid_x, spacing_y * 4);
        placerJoueur(joueurs[8], mid_x, spacing_y * 5);

        // Attaque (1)
        placerJoueur(joueurs[9], att_x, spacing_y * 3);
    }
    else if (tactique == "4-3-3") {
        int def_x = 40;
        int mid_x = 150;
        int att_x = 260;
        int spacing_y = h / 6;

        // Défense (4)
        placerJoueur(joueurs[0], def_x, spacing_y * 1);
        placerJoueur(joueurs[1], def_x, spacing_y * 2);
        placerJoueur(joueurs[2], def_x, spacing_y * 3);
        placerJoueur(joueurs[3], def_x, spacing_y * 4);

        // Milieu (3)
        placerJoueur(joueurs[4], mid_x, spacing_y * 2);
        placerJoueur(joueurs[5], mid_x, spacing_y * 3);
        placerJoueur(joueurs[6], mid_x, spacing_y * 4);

        // Attaque (3)
        placerJoueur(joueurs[7], att_x, spacing_y * 1.5);
        placerJoueur(joueurs[8], att_x, spacing_y * 3);
        placerJoueur(joueurs[9], att_x, spacing_y * 4.5);
    }

    // Gardien : toujours fixe en bas au centre
    placerJoueur(joueurs[10], 20, h / 2 - joueurs[10]->height() / 2);
}
