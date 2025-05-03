#include "gs_match.h"
#include "gs_equipe.h"
#include "gs_billet.h"
#include "./ui_gs_match.h"
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

gs_match::gs_match(Arduino* a, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::gs_match),
    arduino(a)  // Save the pointer
{
    qDebug() << "gs_match: Constructor called.";
    ui->setupUi(this);
    displayStatistics();  
    QTextCharFormat testFormat;
    testFormat.setBackground(Qt::yellow);
    ui->calendar->setDateTextFormat(QDate::currentDate(), testFormat); // test highlight today

   /* arduino = new Arduino();
    int status = arduino->connect_arduino();
    if (status == 0) {
        qDebug() << "Arduino connected successfully.";
    } else {
        qDebug() << "Arduino connection failed.";
        // Optional: show warning message, but DON'T exit or stop the app
        QMessageBox::warning(this, "Arduino", "Connexion Arduino échouée.\nL'application va continuer sans Arduino.");
    }
*/
    Connection c;
    bool connectionSuccess = c.createconnect();
    if (connectionSuccess) {
        QMessageBox::information(this, "Database", "Connexion réussie !");
    } else {
        QMessageBox::critical(this, "Database", "Échec de connexion !");
    }
    ui->tri->addItem("ID Ascending");
    ui->tri->addItem("ID Descending");
    ui->tri->addItem("A-Z");
    ui->tri->addItem("Z-A");
    ui->tri->addItem("Date Ascending");
    ui->tri->addItem("Date Descending");
    connect(ui->tri, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &::gs_match::onSortOptionChanged);
    connect(ui->btnAjouter, &QPushButton::clicked, this, &gs_match::addMatchToDatabase);
    connect(ui->btnSupprimer, &QPushButton::clicked, this, &gs_match::deleteMatch);
    connect(ui->btnModifier, &QPushButton::clicked, this, &gs_match::modifyMatch);
    connect(ui->tableWidget, &QTableWidget::itemSelectionChanged, this, &gs_match::on_tableWidget_itemSelectionChanged);
    connect(ui->recherche, &QPushButton::clicked, this, &gs_match::searchMatch);
    connect(ui->pdfButton, &QPushButton::clicked, this, &gs_match::generatePDF);
    connect(ui->sim, &QPushButton::clicked, this, &gs_match::on_sim_clicked);
    connect(ui->calendar, &QCalendarWidget::clicked, this, &gs_match::onCalendarDateSelected);
    connect(ui->calendar, &QCalendarWidget::clicked, this, &gs_match::onCalendarDateHovered);
    connect(ui->equipepass, &QPushButton::clicked, this, &gs_match::on_equiepass_clicked);
    updateMatchDisplay();
    displayStatistics();
    highlightMatchDates();
    ui->calendar->setSelectedDate(QDate::currentDate().addDays(1));
    ui->calendar->setSelectedDate(QDate::currentDate());




}

gs_match::~gs_match() {
    delete ui;
}

void gs_match::on_sim_clicked() {
    Simulation *simulationWindow = new Simulation(arduino, this);  // Pass the Arduino pointer
    simulationWindow->exec();  // Open as a modal dialog
}

void gs_match::on_equiepass_clicked() {
    // Create a new instance of gs_equipe window
    gs_equipe *equipeWindow = new gs_equipe(this);  // Pass the parent window (gs_match)

    // Show the new window
    equipeWindow->show();  // Open it as a new window
}

void gs_match::on_billetpass_clicked() {
    // Create a new instance of gs_billet window
    gs_billet *billetWindow = new gs_billet(this);  // Pass the parent window (gs_match)

    // Show the new window
    billetWindow->show();  // Open it as a new window
}


    void gs_match::paintEvent(QPaintEvent *event)
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

void gs_match::updateMatchDisplay() {
    QVector<QVector<QString>> data = m.afficher(); // Fetch data from the database

    ui->tableWidget->setRowCount(data.size());
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels({"ID", "Equipe 1", "Equipe 2", "Date", "Lieu", "État"});

    for (int row = 0; row < data.size(); ++row) {
        for (int col = 0; col < 6; ++col) {
            qDebug() << "Row" << row << "Col" << col << "Value:" << data[row][col]; // Debugging output
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(data[row][col]));
        }
    }
}


void gs_match::addMatchToDatabase() {
    QString dateInput = ui->lineEditDate->text().trimmed();
    QString lieu = ui->lineEditLieu->text().trimmed();
    QString etat = ui->etats->currentText();
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

void gs_match::deleteMatch() {
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

void gs_match::on_tableWidget_itemSelectionChanged() {
    int row = ui->tableWidget->currentRow();
    if (row == -1) return;

    ui->lineEditTeam1->setText(ui->tableWidget->item(row, 1)->text());
    ui->lineEditTeam2->setText(ui->tableWidget->item(row, 2)->text());
    ui->lineEditDate->setText(ui->tableWidget->item(row, 3)->text());
    ui->lineEditLieu->setText(ui->tableWidget->item(row, 4)->text());
    ui->etats->setCurrentText(ui->tableWidget->item(row, 5)->text());
}
void gs_match::on_btnModifier_clicked() {
    modifyMatch();
}


void gs_match::modifyMatch() {
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
    QString newEtat = ui->etats->currentText();

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

void gs_match::searchMatch() {
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

void gs_match::sortMatches(const QString& sortOption) {
    // Call the trierPar function with the selected sorting option to get the sorted data
    QVector<QVector<QString>> data = m.trierPar(sortOption);

    // Update the UI with the sorted data
    ui->tableWidget->setRowCount(data.size());
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels({"ID", "Equipe 1", "Equipe 2", "Date", "Lieu", "État"});

    for (int row = 0; row < data.size(); ++row) {
        for (int col = 0; col < 6; ++col) {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(data[row][col]));
        }
    }
}
    void gs_match::onSortOptionChanged(int index) {
        // Get the current sorting option from the ComboBox
        QString sortOption = ui->tri->currentText();

        // Call the trierPar function with the selected sorting option
        QVector<QVector<QString>> data = m.trierPar(sortOption);

        // Update the table with sorted data
        ui->tableWidget->setRowCount(data.size());
        ui->tableWidget->setColumnCount(6);  // Ensure the table has 6 columns
        ui->tableWidget->setHorizontalHeaderLabels({"ID", "Equipe 1", "Equipe 2", "Date", "Lieu", "État"});

        // Fill the table with sorted data
        for (int row = 0; row < data.size(); ++row) {
            for (int col = 0; col < 6; ++col) {
                ui->tableWidget->setItem(row, col, new QTableWidgetItem(data[row][col]));
            }
        }
    }

void gs_match::generatePDF() {
    QString filePath = QDir::currentPath() + "/matches_list.pdf";
    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize::A4);
    writer.setResolution(300);

    QPainter painter(&writer);
    if (!painter.isActive()) {
        QMessageBox::warning(this, "Error", "Failed to generate PDF");
        return;
    }

    int pageWidth = writer.width();
    int pageHeight = writer.height();

    int marginLeft = 50, marginTop = 600, rowHeight = 100;
    QVector<int> colWidths = {150, 350, 350, 250, 250, 250};
    int tableWidth = std::accumulate(colWidths.begin(), colWidths.end(), 0);

    if (marginLeft + tableWidth > pageWidth) {
        marginLeft = (pageWidth - tableWidth) / 2;
    }

    // Function to draw table headers
    auto drawHeader = [&](int y) -> int {
        QFont headerFont("Arial", 14, QFont::Bold);
        painter.setFont(headerFont);
        painter.setBrush(Qt::NoBrush);
        painter.setPen(Qt::black);
        QStringList headers = {"ID", "Equipe 1", "Equipe 2", "Date", "Lieu", "Etat"};

        int x = marginLeft;
        for (int i = 0; i < headers.size(); ++i) {
            QRect rect(x, y, colWidths[i], rowHeight);
            painter.drawRect(rect);
            painter.drawText(rect, Qt::AlignCenter, headers[i]);
            x += colWidths[i];
        }
        return y + rowHeight;
    };

    // Draw logo only on the first page
    QPixmap logo("C:/Users/AMEN WORKSTATION/Desktop/projet/untitled/ball.png");
    if (!logo.isNull()) {
        QRect logoRect((pageWidth - 600) / 2, 50, 600, 300);
        painter.drawPixmap(logoRect, logo);
    }

    // Draw title only on the first page
    QFont titleFont("Arial", 24, QFont::Bold);
    painter.setFont(titleFont);
    painter.drawText(QRect(0, 400, pageWidth, 100), Qt::AlignCenter, "Matches List Report");

    // Draw table header
    int y = drawHeader(marginTop);
    painter.setFont(QFont("Arial", 12));

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        int x = marginLeft;

        // ✅ FIX: Use fillRect separately before drawing cell borders
        QRect rowRect(marginLeft, y, tableWidth, rowHeight);
        if (row % 2 == 0) {
            painter.fillRect(rowRect, QColor(240, 240, 240));  // Light gray background
        }

        for (int col = 0; col < colWidths.size(); ++col) {
            QRect rect(x, y, colWidths[col], rowHeight);
            painter.setPen(Qt::black);  // Ensure text is always visible
            painter.drawRect(rect);

            if (ui->tableWidget->item(row, col)) {
                painter.drawText(rect, Qt::AlignCenter, ui->tableWidget->item(row, col)->text());
            }

            x += colWidths[col];
        }

        y += rowHeight;

        // If next row won't fit, start a new page
        if (y + rowHeight > pageHeight - 100) {
            painter.end();
            writer.newPage();
            painter.begin(&writer);
            y = drawHeader(marginTop);
        }
    }

    painter.end();

    QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
    QMessageBox::information(this, "PDF Generated", "The PDF of the matches list has been successfully created.");
}




void gs_match::displayStatistics() {
    if (ui->stat->layout() == nullptr) {
        ui->stat->setLayout(new QVBoxLayout());
    }

    QMap<QString, int> teamCount;
    int rowCount = ui->tableWidget->rowCount();

    // Clear previous data to avoid duplicates
    teamCount.clear();

    // Count occurrences of each team
    for (int row = 0; row < rowCount; ++row) {
        QString team1 = (ui->tableWidget->item(row, 1) != nullptr) ? ui->tableWidget->item(row, 1)->text() : "";
        QString team2 = (ui->tableWidget->item(row, 2) != nullptr) ? ui->tableWidget->item(row, 2)->text() : "";

        if (!team1.isEmpty()) teamCount[team1]++;
        if (!team2.isEmpty()) teamCount[team2]++;
    }

    // **Clear previous layout safely to avoid duplicates**
    if (ui->stat->layout() != nullptr) {
        QLayoutItem *child;
        while ((child = ui->stat->layout()->takeAt(0)) != nullptr) {
            if (child->widget()) delete child->widget();
            delete child;
        }
    }

    // **Fix 1: Ensure no duplicate values are added**
    QBarSeries *series = new QBarSeries();
    QBarSet *set = new QBarSet("Match Count");

    QStringList categories;
    QMap<int, QString> indexToFullName;  // Map to store full names for tooltip display

    int index = 0;
    for (auto it = teamCount.begin(); it != teamCount.end(); ++it) {
        *set << it.value();  // Add match count

        QString shortName = it.key().left(5) + "...";  // Shorten team name for X-axis
        categories << shortName;
        indexToFullName[index++] = it.key();  // Store full team name
    }

    series->append(set);  // **Ensure this is only called once**

    // **Fix 2: Ensure only one chart is created**
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Teams with the Most Matches");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // **Fix 3: Ensure axis is set only once**
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    axisX->setLabelsAngle(-45);  // Rotate labels
    axisX->setLabelsFont(QFont("Arial", 8));  // Adjust font
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // Y-Axis
    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%d");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // **Fix 4: Use tooltips to show full names**
    QObject::connect(series, &QBarSeries::hovered, [=](bool status, int index) {
        if (status && indexToFullName.contains(index)) {
            QToolTip::showText(QCursor::pos(), indexToFullName[index]);
        }
    });

    // **Fix 5: Ensure only one ChartView is created**
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    ui->stat->layout()->addWidget(chartView);  // **No duplicates!**

    // **Debugging: Print to console**
    qDebug() << "Team count data:" << teamCount;
}




void gs_match::onCalendarDateSelected(const QDate &date) {
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
      highlightMatchDates();
}

void gs_match::highlightMatchDates() {
    qDebug() << "Highlighting match dates...";

    // Iterate through each date with matches
    for (int i = 0; i < ui->calendar->selectedDate().daysInMonth(); ++i) {
        QDate currentDate = ui->calendar->selectedDate().addDays(i);

        // Highlighting the dates based on the match state
        QMap<QDate, QList<QString>> etatsPerDate = m.getMatchStatesPerDate();

        // Normalize etats and assign color
        for (auto it = etatsPerDate.begin(); it != etatsPerDate.end(); ++it) {
            const QDate& date = it.key();
            const QList<QString>& etats = it.value();
            QList<QString> normalizedEtats;
            for (const QString &etat : etats) {
                normalizedEtats.append(etat.trimmed().toLower());
            }

            QColor color;
            if (normalizedEtats.contains("postponed")) {
                color = Qt::gray;
            } else if (normalizedEtats.contains("didn't start")) {
                color = Qt::red;
            } else if (normalizedEtats.contains("started")) {
                color = Qt::blue;
            } else if (normalizedEtats.contains("ended")) {
                color = Qt::green;
            } else {
                continue;
            }

            QTextCharFormat format;
            format.setBackground(color);
            ui->calendar->setDateTextFormat(date, format);

            qDebug() << "Date:" << date.toString("yyyy-MM-dd") << "Etats:" << normalizedEtats;
        }
    }
}

void gs_match::onCalendarDateHovered(const QDate &date) {
    // Query the database for the match info for the hovered date
    QVector<QVector<QString>> data = m.getMatchesByDate(date.toString("yyyy-MM-dd"));

    if (!data.isEmpty()) {
        QString matchInfo;
        for (const QVector<QString>& match : data) {
            QString equipe1 = match[1];  // Team 1
            QString equipe2 = match[2];  // Team 2
            QString time = match[3];     // Time
            matchInfo += QString("Match: %1 vs %2 – %3\n").arg(equipe1).arg(equipe2).arg(time);
        }
        // Show the match info as a tooltip on hover
        ui->calendar->setToolTip(matchInfo);
    } else {
        ui->calendar->setToolTip("No matches on this date.");
    }
}






