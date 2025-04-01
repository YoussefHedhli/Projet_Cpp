#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "connection.h"
#include "match.h"
#include <QMessageBox>
#include <QDebug>
#include <QDate>
#include <QPdfWriter>
#include <QPainter>
#include <QTableWidget>
#include <QDesktopServices>
#include <QUrl>
#include <QDir>
#include <QtCharts>
#include <QMap>
#include <QBarSeries>
#include <QBarSet>
#include <QChartView>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QVBoxLayout>
#include <QPixmap>
#include <QFont>
#include <numeric> // For std::accumulate
#include "simulation.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    displayStatistics();


    Connection c;
    bool connectionSuccess = c.createconnect();
    if (connectionSuccess) {
        QMessageBox::information(this, "Database", "Connexion réussie !");
    } else {
        QMessageBox::critical(this, "Database", "Échec de connexion !");
    }

    connect(ui->btnAjouter, &QPushButton::clicked, this, &MainWindow::addMatchToDatabase);
    connect(ui->btnSupprimer, &QPushButton::clicked, this, &MainWindow::deleteMatch);
    connect(ui->btnModifier, &QPushButton::clicked, this, &MainWindow::modifyMatch);
    connect(ui->tableWidget, &QTableWidget::itemSelectionChanged, this, &MainWindow::on_tableWidget_itemSelectionChanged);
    connect(ui->recherche, &QPushButton::clicked, this, &MainWindow::searchMatch);
    connect(ui->tri, &QPushButton::clicked, this, &MainWindow::sortMatchesByID);
    connect(ui->pdfButton, &QPushButton::clicked, this, &MainWindow::generatePDF);
    connect(ui->sim, &QPushButton::clicked, this, &MainWindow::on_sim_clicked);
    connect(ui->calendar, &QCalendarWidget::clicked, this, &MainWindow::onCalendarDateSelected);
    updateMatchDisplay();
    displayStatistics();

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_sim_clicked() {
    Simulation *simulationWindow = new Simulation(this);
    simulationWindow->exec();  // Open as a modal dialog
}

    void MainWindow::paintEvent(QPaintEvent *event)
{
    // Load background image
    QPixmap pix("C:/Users/AMEN WORKSTATION/Desktop/projet/untitled/bg.jpg");  // Use resource path if image is part of Qt resource system
    if (pix.isNull()) {
        qDebug() << "Failed to load bg.jpg. Check the file path.";
    } else {
        // Scale the image to fit the size of the label
        ui->label_pic->setPixmap(pix.scaled(900, 1000, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    QPixmap logoPix("C:/Users/AMEN WORKSTATION/Desktop/projet/untitled/ball.png");  // Assuming the logo is also stored as a resource
    if (logoPix.isNull()) {
        qDebug() << "Failed to load logo.png. Check the file path.";
    } else {
        // Scale the logo to a desired size
        ui->ball->setPixmap(logoPix.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }


    // Optionally, you can also use QPainter for other custom drawing if needed
    QMainWindow::paintEvent(event);  // Ensure the parent class paintEvent is called
}

void MainWindow::updateMatchDisplay() {
    QVector<QVector<QString>> data = m.afficher();

    ui->tableWidget->setRowCount(data.size());
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels({"ID", "Equipe 1", "Equipe 2", "Date", "Lieu", "État"});

    for (int row = 0; row < data.size(); ++row) {
        for (int col = 0; col < 6; ++col) {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(data[row][col]));
        }
    }
}

void MainWindow::addMatchToDatabase() {
    QString dateInput = ui->lineEditDate->text().trimmed();
    QString lieu = ui->lineEditLieu->text().trimmed();
    QString etat = ui->comboEtat->currentText();
    QString equipe1 = ui->lineEditTeam1->text().trimmed();
    QString equipe2 = ui->lineEditTeam2->text().trimmed();

    if (dateInput.isEmpty() || lieu.isEmpty() || etat.isEmpty() || equipe1.isEmpty() || equipe2.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    QDate formattedDate = QDate::fromString(dateInput, "dd/MM/yyyy");
    if (!formattedDate.isValid()) {
        QMessageBox::warning(this, "Erreur", "Format de date invalide! Utilisez JJ/MM/AAAA.");
        return;
    }
    QString formattedDateString = formattedDate.toString("yyyy-MM-dd");

    Match m(0, equipe1, equipe2, formattedDateString, lieu, etat);
    if (m.ajouter()) {
        QMessageBox::information(this, "Succès", "Match ajouté !");
        updateMatchDisplay();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du match.");

        displayStatistics();

    }
}

void MainWindow::deleteMatch() {
    int row = ui->tableWidget->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un match à supprimer !");
        return;
    }

    int id = ui->tableWidget->item(row, 0)->text().toInt();
    if (m.supprimer(id)) {
        QMessageBox::information(this, "Succès", "Match supprimé !");
        updateMatchDisplay();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
    }
}

void MainWindow::on_tableWidget_itemSelectionChanged() {
    int row = ui->tableWidget->currentRow();
    if (row == -1) return;

    ui->lineEditTeam1->setText(ui->tableWidget->item(row, 1)->text());
    ui->lineEditTeam2->setText(ui->tableWidget->item(row, 2)->text());
    ui->lineEditDate->setText(ui->tableWidget->item(row, 3)->text());
    ui->lineEditLieu->setText(ui->tableWidget->item(row, 4)->text());
    ui->comboEtat->setCurrentText(ui->tableWidget->item(row, 5)->text());
}
void MainWindow::on_btnModifier_clicked() {
    modifyMatch();
}


void MainWindow::modifyMatch() {
    int row = ui->tableWidget->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un match à modifier !");
        return;
    }

    int id = ui->tableWidget->item(row, 0)->text().toInt();
    QString newEquipe1 = ui->lineEditTeam1->text().trimmed();
    QString newEquipe2 = ui->lineEditTeam2->text().trimmed();
    QString newDate = ui->lineEditDate->text().trimmed();
    QString newLieu = ui->lineEditLieu->text().trimmed();
    QString newEtat = ui->comboEtat->currentText();

    if (newEquipe1.isEmpty() || newEquipe2.isEmpty() || newDate.isEmpty() || newLieu.isEmpty() || newEtat.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    QDate formattedDate = QDate::fromString(newDate, "dd/MM/yyyy");
    if (!formattedDate.isValid()) {
        QMessageBox::warning(this, "Erreur", "Format de date invalide! Utilisez JJ/MM/AAAA.");
        return;
    }
    QString formattedDateString = formattedDate.toString("yyyy-MM-dd");

    Match m(id, newEquipe1, newEquipe2, formattedDateString, newLieu, newEtat);
    if (m.modifier(id)) {
        QMessageBox::information(this, "Succès", "Match modifié !");
        updateMatchDisplay();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification.");
    }
}

void MainWindow::searchMatch() {
    QString teamName = ui->rechtxt->text().trimmed();
    QVector<QVector<QString>> data = m.rechercher(teamName);

    ui->tableWidget->setRowCount(data.size());
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels({"ID", "Equipe 1", "Equipe 2", "Date", "Lieu", "État"});

    for (int row = 0; row < data.size(); ++row) {
        for (int col = 0; col < 6; ++col) {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(data[row][col]));
        }
    }
}

void MainWindow::sortMatchesByID() {
    QVector<QVector<QString>> data = m.trierParID();

    ui->tableWidget->setRowCount(data.size());
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels({"ID", "Equipe 1", "Equipe 2", "Date", "Lieu", "État"});

    for (int row = 0; row < data.size(); ++row) {
        for (int col = 0; col < 6; ++col) {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(data[row][col]));
        }
    }
}

void MainWindow::generatePDF() {
    QString filePath = QDir::currentPath() + "/matches_list.pdf";
    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize::A4);
    writer.setResolution(300); // High quality

    QPainter painter(&writer);
    if (!painter.isActive()) {  // Check if it failed
        QMessageBox::warning(this, "Error", "Failed to generate PDF");
        return;
    }

    // 📌 Adjust dimensions for proper scaling
    int pageWidth = writer.width();
    int pageHeight = writer.height();

    int marginLeft = 100, marginTop = 600, rowHeight = 100;
    QVector<int> colWidths = {150, 350, 350, 250, 250, 250};
    int tableWidth = std::accumulate(colWidths.begin(), colWidths.end(), 0);

    if (marginLeft + tableWidth > pageWidth) {
        marginLeft = (pageWidth - tableWidth) / 2;  // Center table
    }

    // 📌 Function to Draw Header
    auto drawHeader = [&]() {
        QFont headerFont("Arial", 14, QFont::Bold);
        painter.setFont(headerFont);
        painter.setBrush(QColor(200, 200, 200));
        QStringList headers = {"ID", "Equipe 1", "Equipe 2", "Date", "Lieu", "Etat"};

        int x = marginLeft, y = marginTop;
        for (int i = 0; i < headers.size(); ++i) {
            QRect rect(x, y, colWidths[i], rowHeight);
            painter.drawRect(rect);
            painter.drawText(rect, Qt::AlignCenter, headers[i]);
            x += colWidths[i];
        }
        return y + rowHeight;  // New starting y position
    };

    // 🎨 Load and Draw Logo (Only on the first page)
    QPixmap logo("C:/Users/AMEN WORKSTATION/Desktop/projet/untitled/ball.png");
    if (!logo.isNull()) {
        int logoWidth = 600, logoHeight = 300;
        QRect logoRect((pageWidth - logoWidth) / 2, 50, logoWidth, logoHeight);
        painter.drawPixmap(logoRect, logo);
    }

    // 🏆 Title (Only on the first page)
    QFont titleFont("Arial", 24, QFont::Bold);
    painter.setFont(titleFont);
    painter.drawText(QRect(0, 400, pageWidth, 100), Qt::AlignCenter, "Matches List Report");

    // 🏷️ Draw Table Header
    int y = drawHeader();

    // 🏁 Draw Table Rows (Handling Multiple Pages)
    painter.setFont(QFont("Arial", 12));
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        int x = marginLeft;
        painter.setBrush(row % 2 == 0 ? QColor(240, 240, 240) : Qt::NoBrush);

        for (int col = 0; col < colWidths.size(); ++col) {
            QRect rect(x, y, colWidths[col], rowHeight);
            painter.drawRect(rect);
            if (ui->tableWidget->item(row, col)) {
                painter.drawText(rect, Qt::AlignCenter, ui->tableWidget->item(row, col)->text());
            }
            x += colWidths[col];
        }
        y += rowHeight;

        // 📌 Start a new page if needed
        if (y + rowHeight > pageHeight - 100) {
            writer.newPage();  // New Page!
            y = drawHeader();  // Redraw the header at the top of the new page
        }
    }

    // ✅ End Painting
    painter.end();

    // 📂 Open the generated PDF
    QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));

    // 🎉 Notify the user
    QMessageBox::information(this, "PDF Generated", "The PDF of the matches list has been successfully created.");
}


void MainWindow::displayStatistics() {
    if (ui->stat->layout() == nullptr) {
        ui->stat->setLayout(new QVBoxLayout());
    }

    QMap<QString, int> teamCount;
    int rowCount = ui->tableWidget->rowCount();

    // Count occurrences of each team
    for (int row = 0; row < rowCount; ++row) {
        QString team1 = (ui->tableWidget->item(row, 1) != nullptr) ? ui->tableWidget->item(row, 1)->text() : "";
        QString team2 = (ui->tableWidget->item(row, 2) != nullptr) ? ui->tableWidget->item(row, 2)->text() : "";

        if (!team1.isEmpty()) teamCount[team1]++;
        if (!team2.isEmpty()) teamCount[team2]++;
    }

    // Create Bar Series
    QBarSeries *series = new QBarSeries();
    QBarSet *set = new QBarSet("Match Count");

    QStringList categories;
    for (auto it = teamCount.begin(); it != teamCount.end(); ++it) {
        *set << it.value();
        categories << it.key();
    }
    series->append(set);

    // Create Chart
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Teams with the Most Matches");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // X-Axis
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Y-Axis
    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%d");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // Create ChartView
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Remove old widgets safely
    if (ui->stat->layout() != nullptr) {
        QLayoutItem *child;
        while ((child = ui->stat->layout()->takeAt(0)) != nullptr) {
            if (child->widget()) delete child->widget();
            delete child;
        }
    }

    // Add new ChartView
    ui->stat->layout()->addWidget(chartView);
    qDebug() << "Team count data:" << teamCount;
    qDebug() << "Row count in tableWidget:" << ui->tableWidget->rowCount();
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int col = 0; col < 6; ++col) {
            if (ui->tableWidget->item(row, col) != nullptr)
                qDebug() << "Row" << row << "Column" << col << ":" << ui->tableWidget->item(row, col)->text();
            else
                qDebug() << "Row" << row << "Column" << col << ": NULL";
        }
    }


}



void MainWindow::onCalendarDateSelected(const QDate &date) {
    QString selectedDate = date.toString("yyyy-MM-dd");
    QVector<QVector<QString>> data = m.getMatchesByDate(selectedDate);

    ui->tableWidget->setRowCount(data.size());
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels({"ID", "Equipe 1", "Equipe 2", "Date", "Lieu", "État"});

    for (int row = 0; row < data.size(); ++row) {
        for (int col = 0; col < 6; ++col) {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(data[row][col]));
        }
    }
}

