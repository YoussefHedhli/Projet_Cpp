#include "sponsor.h"
#include "ui_sponsor.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QTableWidget>
#include <QSqlError> // Ajoutez cette ligne pour inclure QSqlError
#include <QStandardPaths>
#include <QDebug>
#include <QSet>
#include <QDate>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <QtCharts>
#include <QPixmap>
#include <QPrinter>
#include <QPainter>
#include <QPdfWriter>
#include <QPageSize>  // Pour Qt 5.14 et supérieur
#include <QPainter>
#include <QTextDocument>
#include <QPageSize>



#include <QMimeData>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QFile>
#include <QFileDialog>


// Constructeur pour l'interface graphique
sponsor::sponsor(QWidget *parent) : QDialog(parent), ui(new Ui::sponsor) {
    ui->setupUi(this);

    // Connexion des boutons aux slots
    connect(ui->ajouter, &QPushButton::clicked, this, &sponsor::on_ajouter_clicked);
    connect(ui->modifier, &QPushButton::clicked, this, &sponsor::on_modifier_clicked);
    connect(ui->supprimer, &QPushButton::clicked, this, &sponsor::on_supprimer_clicked);
    connect(ui->recherche, &QPushButton::clicked, this, &sponsor::on_recherche_clicked);
    connect(ui->tri, &QPushButton::clicked, this, &sponsor::on_tri_clicked);
    connect(ui->annuler, &QPushButton::clicked, this, &sponsor::on_annuler_clicked);
    connect(ui->btnClassement, &QPushButton::clicked, this, &sponsor::loadSponsorRanking);
    connect(ui->btnLoadImage, &QPushButton::clicked, this, &sponsor::on_btnLoadImage_clicked);
        connect(ui->btnRemoveImage, &QPushButton::clicked, this, &sponsor::on_btnRemoveImage_clicked);


        // Configurer le QLabel
        ui->labelImageSponsor->setFrameShape(QFrame::Box);
        ui->labelImageSponsor->setScaledContents(true);
        ui->labelImageSponsor->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);


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
    QString idText = ui->lineEdit_id->text();
    QString nom_org = ui->lineEdit_nom_org->text();
    QString produit = ui->lineEdit_produit->text();
    QString contribution = ui->lineEdit_contribution->text();

    // Réinitialiser les styles
    ui->lineEdit_id->setStyleSheet("");
    ui->lineEdit_nom_org->setStyleSheet("");
    ui->lineEdit_produit->setStyleSheet("");
    ui->lineEdit_contribution->setStyleSheet("");

    bool valide = true;

    // Vérification ID (entier positif)
    bool idOk;
    int id_s = idText.toInt(&idOk);
    if (!idOk || id_s <= 0) {
        ui->lineEdit_id->setStyleSheet("border: 2px solid red;");
        valide = false;
    }

    // Vérification du nom et produit (lettres uniquement)
    QRegularExpression regex("^[a-zA-ZÀ-ÿ\\s\\-']+$");
    if (!regex.match(nom_org).hasMatch()) {
        ui->lineEdit_nom_org->setStyleSheet("border: 2px solid red;");
        valide = false;
    }
    if (!regex.match(produit).hasMatch()) {
        ui->lineEdit_produit->setStyleSheet("border: 2px solid red;");
        valide = false;
    }

    // Vérification contribution (nombre positif)
    bool contributionOk;
    double contributionValue = contribution.toDouble(&contributionOk);
    if (!contributionOk || contributionValue <= 0) {
        ui->lineEdit_contribution->setStyleSheet("border: 2px solid red;");
        valide = false;
    }

    if (!valide) return; // Empêche l'ajout si un champ est invalide

    // 🔹 Si tout est valide, on ajoute à la base
    QSqlQuery query;
    query.prepare("INSERT INTO GS_SPONSOR (ID_S, NOM_ORG, PRODUIT, CONTRIBUTION) "
                  "VALUES (:id_s, :nom_org, :produit, :contribution)");
    query.bindValue(":id_s", id_s);
    query.bindValue(":nom_org", nom_org);
    query.bindValue(":produit", produit);
    query.bindValue(":contribution", contributionValue);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Sponsor ajouté avec succès.");

        afficherSponsors();
        ui->lineEdit_id->clear();
        ui->lineEdit_nom_org->clear();
        ui->lineEdit_produit->clear();
        ui->lineEdit_contribution->clear();
    }
}



void sponsor::on_modifier_clicked() {
    QString idText = ui->lineEdit_id->text();
    QString nom_org = ui->lineEdit_nom_org->text();
    QString produit = ui->lineEdit_produit->text();
    QString contribution = ui->lineEdit_contribution->text();

    // Réinitialiser les styles
    ui->lineEdit_id->setStyleSheet("");
    ui->lineEdit_nom_org->setStyleSheet("");
    ui->lineEdit_produit->setStyleSheet("");
    ui->lineEdit_contribution->setStyleSheet("");

    bool valide = true;

    // Vérification ID (entier positif)
    bool idOk;
    int id_s = idText.toInt(&idOk);
    if (!idOk || id_s <= 0) {
        ui->lineEdit_id->setStyleSheet("border: 2px solid red;");
        valide = false;
    }

    // Vérification du nom et produit (lettres uniquement)
    QRegularExpression regex("^[a-zA-ZÀ-ÿ\\s\\-']+$");
    if (!regex.match(nom_org).hasMatch()) {
        ui->lineEdit_nom_org->setStyleSheet("border: 2px solid red;");
        valide = false;
    }
    if (!regex.match(produit).hasMatch()) {
        ui->lineEdit_produit->setStyleSheet("border: 2px solid red;");
        valide = false;
    }

    // Vérification contribution (nombre positif)
    bool contributionOk;
    double contributionValue = contribution.toDouble(&contributionOk);
    if (!contributionOk || contributionValue <= 0) {
        ui->lineEdit_contribution->setStyleSheet("border: 2px solid red;");
        valide = false;
    }

    if (!valide) return; // Empêche la modification si un champ est invalide

    // 🔹 Si tout est valide, on modifie dans la base
    QSqlQuery query;
    query.prepare("UPDATE GS_SPONSOR SET NOM_ORG = :nom_org, PRODUIT = :produit, CONTRIBUTION = :contribution "
                  "WHERE ID_S = :id_s");
    query.bindValue(":id_s", id_s);
    query.bindValue(":nom_org", nom_org);
    query.bindValue(":produit", produit);
    query.bindValue(":contribution", contributionValue);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Sponsor modifié avec succès.");

        afficherSponsors(); // Rafraîchir la liste après modification

        // Vider les champs après modification
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
    Q_UNUSED(column);

    QTableWidgetItem *idItem = ui->tableWidget->item(row, 0);
    QTableWidgetItem *nomOrgItem = ui->tableWidget->item(row, 1);
    QTableWidgetItem *produitItem = ui->tableWidget->item(row, 2);
    QTableWidgetItem *contributionItem = ui->tableWidget->item(row, 3);

    if (idItem && nomOrgItem && produitItem && contributionItem) {
        ui->lineEdit_id->setText(idItem->text());
        ui->lineEdit_nom_org->setText(nomOrgItem->text());
        ui->lineEdit_produit->setText(produitItem->text());
        ui->lineEdit_contribution->setText(contributionItem->text());

        QTableWidgetItem *nomOrgItem = ui->tableWidget->item(row, 1);
            if (nomOrgItem) {
                loadSponsorImage(nomOrgItem->text());
            }

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




void sponsor::on_recherche_clicked()
{
    QString nomRecherche = ui->lineEditrecherche->text().trimmed();

        QSqlQuery query;
        query.prepare("SELECT ID_S, NOM_ORG, PRODUIT, CONTRIBUTION FROM GS_SPONSOR WHERE NOM_ORG LIKE :nom");
        query.bindValue(":nom", "%" + nomRecherche + "%");
        query.exec();

        ui->tableWidget->setRowCount(0);
        int row = 0;

        while (query.next()) {
            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // ID
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Nom
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // Produit
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // Contribution
            row++;
        }
}

void sponsor::on_tri_clicked()
{
    QSqlQuery query("SELECT ID_S, NOM_ORG, PRODUIT, CONTRIBUTION FROM GS_SPONSOR ORDER BY ID_S ASC");

        ui->tableWidget->setRowCount(0); // Réinitialiser la table
        int row = 0;

        while (query.next()) {
            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // ID
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Nom
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // Produit
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // Contribution
            row++;
        }
}




void sponsor::on_annuler_clicked()
{
    ui->lineEditrecherche->clear(); // Effacer le champ de recherche
       afficherSponsors();
}


void sponsor::on_statistique_clicked() {
    // Effectuer une requête pour obtenir les statistiques des sponsors
    QSqlQuery query;
    query.prepare("SELECT NOM_ORG, COUNT(*) AS Nombre FROM GS_SPONSOR GROUP BY NOM_ORG");
    if (!query.exec()) {
        qDebug() << "Erreur lors de la récupération des statistiques des sponsors";
        return;
    }

    // Créer une série de données pour le diagramme circulaire
    QPieSeries *series = new QPieSeries();

    // Ajouter les données de chaque sponsor à la série
    int total = 0; // Variable pour stocker le total des sponsors
    while (query.next()) {
        QString sponsorName = query.value(0).toString();
        int count = query.value(1).toInt();
        total += count;
        series->append(sponsorName, count);
    }

    // Créer une vue de diagramme circulaire
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Statistiques des sponsors");

    // Créer un QChartView
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(800, 600);

    // Ajouter des annotations avec le pourcentage formaté
    for (QPieSlice *slice : series->slices()) {
        double percentage = (slice->value() / total) * 100;
        QString label = QString("%1 (%2%)").arg(slice->label()).arg(QString::number(percentage, 'f', 0)); // 'f', 0 pour 0 décimales
        slice->setLabelVisible(true);
        slice->setLabel(label);
        slice->setLabelFont(QFont("Arial", 8));
    }

    // Prendre une capture d'écran du diagramme
    QPixmap chartPixmap = chartView->grab();

    // Afficher la statistique dans une boîte de dialogue
    QMessageBox msgBox;
    msgBox.setWindowTitle("Statistiques des sponsors");
    msgBox.setIconPixmap(chartPixmap);
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();
}
void sponsor::on_pdf_clicked() {
    QSqlQuery query;
    query.prepare("SELECT DISTINCT NOM_ORG FROM GS_SPONSOR");
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Échec de récupération des sponsors: " + query.lastError().text());
        return;
    }

    QStringList sponsors;
    while (query.next()) {
        sponsors.append(query.value(0).toString());
    }

    int successCount = 0;
    foreach (const QString& sponsor, sponsors) {
        generatePdfForSponsor(sponsor); // Appel simple sans vérification de retour
        successCount++; // On considère que c'est toujours un succès dans cette version
    }

    QMessageBox::information(this, "Rapport PDF",
                             QString("%1 PDF(s) généré(s)").arg(successCount));
}

void sponsor::generatePdfForSponsor(const QString& sponsor) {
    // Configuration du PDF
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString filename = QString("%1/%2_Contribution.pdf").arg(desktopPath).arg(sponsor);

    QPdfWriter pdfWriter(filename);
    pdfWriter.setPageSize(QPageSize(QPageSize::A4));
    pdfWriter.setTitle("Rapport de Contributions - " + sponsor);
    pdfWriter.setResolution(300); // Haute résolution

    QPainter painter(&pdfWriter);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::TextAntialiasing, true);

    // Dimensions utiles
    const int margin = 50; // marge en pixels (1cm ≈ 37.8 pixels à 300dpi)
    const int contentWidth = pdfWriter.width() - 2 * margin;
    int yPos = margin;

    // Logo et en-tête (optionnel)
    QFont headerFont("Arial", 20, QFont::Bold);
    painter.setFont(headerFont);
    painter.drawText(QRect(margin, yPos, contentWidth, 60),
                     Qt::AlignCenter,
                     "Rapport des Contributions");
    yPos += 70;

    QFont subHeaderFont("Arial", 16, QFont::Normal);
    painter.setFont(subHeaderFont);
    painter.drawText(QRect(margin, yPos, contentWidth, 40),
                     Qt::AlignCenter,
                     "Sponsor: " + sponsor);
    yPos += 50;

    // Ligne de séparation
    painter.drawLine(margin, yPos, pdfWriter.width() - margin, yPos);
    yPos += 30;

    // Requête des données
    QSqlQuery query;
    query.prepare("SELECT ID_S, PRODUIT, CONTRIBUTION FROM GS_SPONSOR WHERE NOM_ORG = :sponsor");
    query.bindValue(":sponsor", sponsor);

    if (!query.exec()) {
        qWarning() << "Erreur requête pour" << sponsor;
        return;
    }

    // Paramètres du tableau
    const int rowHeight = 40;
    const int headerHeight = 50;
    const QList<int> colWidths = {contentWidth/6, contentWidth/2, contentWidth/3};
    QList<QString> headers = {"ID", "Produit/Service", "Contribution (€)"};

    // Fonction pour calculer la position X cumulée
    auto calcXPos = [&colWidths](int col) {
        int x = 0;
        for (int i = 0; i < col; ++i) {
            x += colWidths[i];
        }
        return x;
    };

    // En-tête du tableau
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    painter.setBrush(QBrush(QColor(230, 230, 250))); // Fond bleu clair
    for (int col = 0; col < headers.size(); ++col) {
        painter.drawRect(margin + calcXPos(col), yPos, colWidths[col], headerHeight);
        painter.drawText(QRect(margin + calcXPos(col), yPos, colWidths[col], headerHeight),
                         Qt::AlignCenter, headers[col]);
    }
    yPos += headerHeight;

    // Contenu du tableau
    painter.setFont(QFont("Arial", 11));
    painter.setBrush(Qt::NoBrush);

    double totalContribution = 0;
    int rowCount = 0;

    while (query.next()) {
        // Alternance de couleur des lignes
        if (rowCount % 2 == 0) {
            painter.setBrush(QBrush(QColor(245, 245, 245)));
        } else {
            painter.setBrush(QBrush(Qt::white));
        }

        for (int col = 0; col < 3; ++col) {
            QString text = query.value(col).toString();

            // Formatage spécial pour la colonne Contribution
            if (col == 2) {
                bool ok;
                double value = text.toDouble(&ok);
                if (ok) {
                    text = QString::number(value, 'f', 2);
                    totalContribution += value;
                }
            }

            painter.drawRect(margin + calcXPos(col), yPos, colWidths[col], rowHeight);
            painter.drawText(QRect(margin + calcXPos(col), yPos, colWidths[col], rowHeight),
                             col == 2 ? Qt::AlignRight|Qt::AlignVCenter : Qt::AlignCenter,
                             text);
        }
        yPos += rowHeight;
        rowCount++;
    }

    // Ligne de total
    yPos += 10;
    painter.setFont(QFont("Arial", 12, QFont::Bold));
    painter.setBrush(QBrush(QColor(200, 230, 200)));

    painter.drawRect(margin + calcXPos(2), yPos, colWidths[2], rowHeight);
    painter.drawText(QRect(margin + calcXPos(2), yPos, colWidths[2], rowHeight),
                     Qt::AlignRight|Qt::AlignVCenter,
                     "Total: " + QString::number(totalContribution, 'f', 2) + " €");

    yPos += rowHeight + 30;

    // Pied de page
    QFont footerFont("Arial", 10);
    painter.setFont(footerFont);
    painter.drawText(QRect(margin, yPos, contentWidth, 30),
                     Qt::AlignRight,
                     "Généré le " + QDate::currentDate().toString("dd/MM/yyyy"));

    painter.drawText(QRect(margin, yPos, contentWidth, 30),
                     Qt::AlignLeft,
                     "© MonApplication");

    painter.end();

    qDebug() << "PDF généré avec succès:" << filename;
}


















    void sponsor::loadSponsorRanking() {
        QSqlQuery query;
        // Requête pour obtenir la somme des contributions par sponsor, triée par ordre décroissant
        query.prepare("SELECT NOM_ORG, SUM(CONTRIBUTION) as TOTAL_CONTRIBUTION "
                      "FROM GS_SPONSOR "
                      "GROUP BY NOM_ORG "
                      "ORDER BY TOTAL_CONTRIBUTION DESC");

        if (!query.exec()) {
            QMessageBox::critical(this, "Erreur", "Échec de récupération du classement des sponsors: " + query.lastError().text());
            return;
        }

        // Configurer le tableau avec les colonnes appropriées
        ui->tableClassement->setRowCount(0);
        ui->tableClassement->setColumnCount(4); // Rang, Sponsor, Contribution, Catégorie
        ui->tableClassement->setHorizontalHeaderLabels({"Rang", "Sponsor", "Contribution Totale", "Catégorie"});

        int row = 0;
        int rank = 1;
        while (query.next()) {
            QString name = query.value(0).toString();
            double totalContribution = query.value(1).toDouble();

            // Déterminer la catégorie
            QString category = (totalContribution >= 5000) ? "Gold" :
                                   (totalContribution >= 1000) ? "Silver" : "Bronze";

            // Ajouter une nouvelle ligne
            ui->tableClassement->insertRow(row);

            // Colonne Rang (1)
            QTableWidgetItem *rankItem = new QTableWidgetItem(QString::number(rank));
            rankItem->setTextAlignment(Qt::AlignCenter);
            ui->tableClassement->setItem(row, 0, rankItem);

            // Colonne Sponsor (2)
            QTableWidgetItem *nameItem = new QTableWidgetItem(name);
            ui->tableClassement->setItem(row, 1, nameItem);

            // Colonne Contribution Totale (3)
            QTableWidgetItem *contributionItem = new QTableWidgetItem(QString::number(totalContribution, 'f', 2));
            contributionItem->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
            ui->tableClassement->setItem(row, 2, contributionItem);

            // Colonne Catégorie (4)
            QTableWidgetItem *categoryItem = new QTableWidgetItem(category);
            categoryItem->setTextAlignment(Qt::AlignCenter);
            ui->tableClassement->setItem(row, 3, categoryItem);

            // Colorisation selon la catégorie
            QColor bgColor;
            if (category == "Gold") {
                bgColor = QColor(255, 215, 0); // Or
            } else if (category == "Silver") {
                bgColor = QColor(192, 192, 192); // Argent
            } else {
                bgColor = QColor(205, 127, 50); // Bronze
            }

            // Appliquer la couleur à toute la ligne
            for (int col = 0; col < 4; ++col) {
                ui->tableClassement->item(row, col)->setBackground(bgColor);
            }

            row++;
            rank++;
        }

        // Ajustement de la largeur des colonnes
        ui->tableClassement->resizeColumnsToContents();
        // Optionnel: Définir des largeurs spécifiques
        ui->tableClassement->setColumnWidth(0, 60);   // Rang
        ui->tableClassement->setColumnWidth(1, 150);  // Sponsor
        ui->tableClassement->setColumnWidth(2, 150);  // Contribution
        ui->tableClassement->setColumnWidth(3, 100);  // Catégorie
    }


    QString sponsor::getSelectedSponsor() const {
        int currentRow = ui->tableWidget->currentRow();
        if (currentRow >= 0) {
            return ui->tableWidget->item(currentRow, 1)->text(); // Colonne 1 = NOM_ORG
        }
        return QString();
    }







    // Conversion d'image en tableau de bytes
    QByteArray sponsor::imageToByteArray(const QString &filePath) {
        QFile file(filePath);
        if (!file.open(QIODevice::ReadOnly))
            return QByteArray();
        return file.readAll();
    }

    // Sauvegarde de l'image dans la base de données
    void sponsor::saveSponsorImage(const QString &sponsorName, const QByteArray &imageData) {
        QSqlQuery query;
        query.prepare("UPDATE GS_SPONSOR SET IMAGE_DATA = :image WHERE NOM_ORG = :sponsor");
        query.bindValue(":image", imageData);
        query.bindValue(":sponsor", sponsorName);

        if (!query.exec()) {
            QMessageBox::critical(this, "Erreur", "Erreur de sauvegarde: " + query.lastError().text());
        }
    }

    // Chargement de l'image depuis la base de données   selected table yafichli il image
    void sponsor::loadSponsorImage(const QString &sponsorName) {
        QSqlQuery query;
        query.prepare("SELECT IMAGE_DATA FROM GS_SPONSOR WHERE NOM_ORG = :sponsor");
        query.bindValue(":sponsor", sponsorName);

        if (query.exec() && query.next()) {
            QByteArray imageData = query.value(0).toByteArray();
            if (!imageData.isEmpty()) {
                QPixmap pixmap;
                pixmap.loadFromData(imageData);
                ui->labelImageSponsor->setPixmap(pixmap.scaled(ui->labelImageSponsor->size(),
                                                             Qt::KeepAspectRatio,
                                                             Qt::SmoothTransformation));
            } else {
                ui->labelImageSponsor->clear();
            }
        }
    }

    // Bouton pour supprimer l'image
    void sponsor::on_btnRemoveImage_clicked() {
        QString sponsorName = getSelectedSponsor();
        if (sponsorName.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Aucun sponsor sélectionné.");
            return;
        }

        QSqlQuery query;
        query.prepare("UPDATE GS_SPONSOR SET IMAGE_DATA = NULL WHERE NOM_ORG = :sponsor");
        query.bindValue(":sponsor", sponsorName);

        if (query.exec()) {
            ui->labelImageSponsor->clear();
            QMessageBox::information(this, "Succès", "Image supprimée avec succès.");
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression: " + query.lastError().text());
        }
    }

    // Bouton pour charger une nouvelle image
    void sponsor::on_btnLoadImage_clicked() {
        QString sponsorName = getSelectedSponsor();
        if (sponsorName.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un sponsor d'abord.");
            return;
        }

        QString filePath = QFileDialog::getOpenFileName(this,
                                                      "Choisir une image",
                                                      QStandardPaths::writableLocation(QStandardPaths::PicturesLocation),
                                                      "Images (*.png *.jpg *.jpeg *.bmp)");

        if (!filePath.isEmpty()) {
            QPixmap pixmap(filePath);
            if (pixmap.isNull()) {
                QMessageBox::warning(this, "Erreur", "Impossible de charger l'image.");
                return;
            }

            ui->labelImageSponsor->setPixmap(pixmap.scaled(ui->labelImageSponsor->size(),
                                                         Qt::KeepAspectRatio,
                                                         Qt::SmoothTransformation));

            QByteArray imageData = imageToByteArray(filePath);
            saveSponsorImage(sponsorName, imageData);
        }
    }

    void sponsor::on_tri_des_clicked()
    {
        QSqlQuery query("SELECT ID_S, NOM_ORG, PRODUIT, CONTRIBUTION FROM GS_SPONSOR ORDER BY ID_S DESC");

        ui->tableWidget->setRowCount(0); // Réinitialiser la table
        int row = 0;

        while (query.next()) {
            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value(0).toString())); // ID
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value(1).toString())); // Nom
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value(2).toString())); // Produit
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value(3).toString())); // Contribution
            row++;
        }
    }

