#include "gs_billet.h"
#include "fennetre1.h"
#include "ui_gs_billet.h"
#include "stadiumwidget.h"
#include <QMessageBox>
#include <QRandomGenerator>
#include <QSqlQuery>
#include <QSqlError>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QImage>
#include <QPixmap>
#include "billet.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QPieSeries>
#include <QUrlQuery>
#include <QSqlRecord>
#include "gs_billet.h"
#include "ui_gs_billet.h"
#include <QLabel>
#include <QPixmap>
#include <QDebug>

gs_billet::gs_billet(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gs_billet)
{
    ui->setupUi(this);

    connect(ui->matchpass, &QPushButton::clicked, this, &gs_billet::on_matchpass_clicked);
    connect(ui->equipepass, &QPushButton::clicked, this, &gs_billet::on_equipepass_clicked);
    connect(ui->sponsorpass, &QPushButton::clicked, this, &gs_billet::on_sponsorpass_clicked);
    connect(ui->employerpass, &QPushButton::clicked, this, &gs_billet::on_employerpass_clicked);
}

gs_billet::~gs_billet()
{
    delete ui;

}

void gs_billet::paintEvent(QPaintEvent *event) {
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

void gs_billet::on_matchpass_clicked() {
    QMessageBox::warning(this, "Accès refusé", "Vous n'avez pas l'accès requis pour la gestion des équipes.");
}

void gs_billet::on_equipepass_clicked() {
    QMessageBox::warning(this, "Accès refusé", "Vous n'avez pas l'accès requis pour la gestion des billets.");
}

void gs_billet::on_sponsorpass_clicked() {
    QMessageBox::warning(this, "Accès refusé", "Vous n'avez pas l'accès requis pour la gestion des sponsors.");
}

void gs_billet::on_employerpass_clicked() {
    // Open the gs_match window
    fennetre1 *window = new fennetre1(this);  // Passing 'this' as the parent window
    window->show();  // Show the fennetre1 window

    // Close the gs_match window
    this->close();  // Close the current window (gs_match)
}

void gs_billet::on_stat_clicked() {
    QSqlQuery query;
    QMap<QString, int> typeCount;
    typeCount["Enceinte"] = 0;
    typeCount["Pelouse"] = 0;
    typeCount["Virage"] = 0;

    // Query to count types
    if (query.exec("SELECT TYPE FROM GS_BILLET")) {
        while (query.next()) {
            QString type = query.value(0).toString();
            if (typeCount.contains(type)) {
                typeCount[type]++;
            }
        }
    } else {
        QMessageBox::warning(this, "Erreur", "Erreur lors de la récupération des données.");
        return;
    }

    // Create the pie chart
    QPieSeries *series = new QPieSeries();
    for (auto it = typeCount.begin(); it != typeCount.end(); ++it) {
        series->append(it.key(), it.value());
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition des types de billets");
    chart->legend()->setAlignment(Qt::AlignRight);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Display in a new window
    QMainWindow *chartWindow = new QMainWindow(this);
    chartWindow->setCentralWidget(chartView);
    chartWindow->resize(600, 400);
    chartWindow->setWindowTitle("Statistiques des billets");
    chartWindow->show();
}
// Display table contents when "aff" button is pressed
void gs_billet::on_aff_clicked() {
    refreshTableWidget();
}

// Check if the ticket exists when ID_B is entered in "bi"
void gs_billet::on_modif_clicked() {
    QString num = ui->bi->text().trimmed();  // Read ID_B from input

    bool isNumber;
    int id_b = num.toInt(&isNumber);
    if (!isNumber) {
        QMessageBox::warning(this, "Erreur", "L'ID_B doit être un nombre!");
        return;
    }

    // Fetch QRID and DATEB from the database using Billet class
    Billet billet;
    if (billet.fetchBilletById(id_b)) {
        // Setting the values correctly
        ui->p2->setText(billet.getQrId());  // Show QRID in p2

        // Ensure the DATEB format is correct (dd/MM/yyyy)
        ui->d2->setText(billet.getDateB().toString("dd/MM/yyyy")); // Show DATEB in d2

        QMessageBox::information(this, "Modification", "Vous pouvez modifier le QRID et la date.");
    } else {
        QMessageBox::warning(this, "Erreur", "Ce billet n'existe pas.");
    }
}

// Slot for deleting the ticket when "sup" button is pressed
void gs_billet::on_sup_clicked() {
    QString num = ui->bi->text().trimmed();  // Read ID_B from "bi" input

    bool isNumber;
    int id_b = num.toInt(&isNumber);
    if (!isNumber) {
        QMessageBox::warning(this, "Erreur", "L'ID_B doit être un nombre!");
        return;
    }

    // Check if the ticket exists
    Billet billet;
    if (billet.fetchBilletById(id_b)) {
        // Ticket exists, delete it
        if (billet.deleteBillet(id_b)) {
            refreshTableWidget();  // Refresh the table to reflect the deletion
            QMessageBox::information(this, "Succès", "Billet supprimé avec succès !");
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression du billet.");
        }
    } else {
        // Ticket doesn't exist
        QMessageBox::warning(this, "Erreur", "Ce billet n'existe pas.");
    }
}

// Add a new ticket when "Res" is pressed
void gs_billet::on_res_clicked() {
    QString p1 = ui->p1->text().trimmed();  // ID_B
    QString d1 = ui->d1->text().trimmed();  // Date

    bool isNumber;
    int id_b = p1.toInt(&isNumber);
    if (!isNumber) {
        QMessageBox::warning(this, "Erreur", "L'ID_B doit être un nombre!");
        return;
    }

    Billet billet;
    if (billet.fetchBilletById(id_b)) {
        QMessageBox::warning(this, "Erreur", "Ce billet est déjà enregistré. Utilisez le bouton de modification.");
        return;
    }

    billet.setQrId(QString::number(id_b));
    billet.setPrix(0);

    if (p1.startsWith("1")) {
        billet.setType("Virage");
        billet.setPrix(20);
    } else if (p1.startsWith("2")) {
        billet.setType("Pelouse");
        billet.setPrix(40);
    } else if (p1.startsWith("3")) {
        billet.setType("Enceinte");
        billet.setPrix(80);
    } else {
        QMessageBox::warning(this, "Erreur", "Type de billet invalide.");
        return;
    }

    QDate date = QDate::fromString(d1, "dd/MM/yyyy");
    if (!date.isValid()) {
        QMessageBox::warning(this, "Erreur", "Le format de la date doit être JJ/MM/AAAA.");
        return;
    }
    billet.setDateB(date);

    // Get random ID_M from GS_MATCH
    QSqlQuery query("SELECT ID_M FROM GS_MATCH");
    QVector<int> matchIds;
    while (query.next()) {
        matchIds.append(query.value(0).toInt());
    }

    if (matchIds.isEmpty()) {
        QMessageBox::critical(this, "Erreur", "Aucun match disponible dans GS_MATCH.");
        return;
    }

    int randomIndex = QRandomGenerator::global()->bounded(matchIds.size());
    int selectedMatchId = matchIds[randomIndex];

    // Insert into GS_BILLET with IDMATCH_B
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO GS_BILLET (ID_B, PRIX, TYPE, DATEB, QRID, IDMATCH_B) "
                        "VALUES (:idb, :prix, :type, :dateb, :qrid, :idmatch)");
    insertQuery.bindValue(":idb", id_b);
    insertQuery.bindValue(":prix", billet.getPrix());
    insertQuery.bindValue(":type", billet.getType());
    insertQuery.bindValue(":dateb", billet.getDateB());
    insertQuery.bindValue(":qrid", billet.getQrId());
    insertQuery.bindValue(":idmatch", selectedMatchId);

    if (insertQuery.exec()) {
        refreshTableWidget();
        QMessageBox::information(this, "Succès", "Billet ajouté avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout du billet.");
    }
}

void gs_billet::on_cherch_clicked() {
    QString searchTerm = ui->bi->text().trimmed(); // Read input from the search line edit
    if (searchTerm.isEmpty()) {
        return; // If no input, do nothing
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM GS_BILLET WHERE PRIX LIKE :searchTerm OR TYPE LIKE :searchTerm OR QRID LIKE :searchTerm");
    query.bindValue(":searchTerm", "%" + searchTerm + "%");

    if (query.exec()) {
        ui->tableWidget->setRowCount(0); // Clear the table before inserting new data

        // Insert the rows for the search results
        while (query.next()) {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row); // Add a new row

            // Set data in table for each column
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("ID_B").toString()));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("PRIX").toString()));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("TYPE").toString()));
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("DATEB").toString()));
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("QRID").toString()));
            ui->tableWidget->setItem(row, 5, new QTableWidgetItem(query.value("IDMATCH_B").toString()));

        }
    } else {
        QMessageBox::warning(this, "Search Error", "Failed to execute search query.");
    }
}
void gs_billet::on_confirm_clicked() {
    QSqlQuery query;

    // Check combo box selection
    int index = ui->tri->currentIndex();

    // Depending on the selected option, sort in ascending or descending order
    if (index == 0) {  // Tri Croissant (ascending order)
        query.prepare("SELECT * FROM GS_BILLET ORDER BY ID_B ASC");
    } else if (index == 1) {  // Tri Décroissant (descending order)
        query.prepare("SELECT * FROM GS_BILLET ORDER BY ID_B DESC");
    }

    // Execute the query
    if (query.exec()) {
        ui->tableWidget->setRowCount(0);  // Clear the table before inserting new data

        // Insert data into the table widget
        while (query.next()) {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);

            // Set data for each column
            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("ID_B").toString()));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("PRIX").toString()));
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("TYPE").toString()));
            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("DATEB").toString()));
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("QRID").toString()));
        }
    } else {
        QMessageBox::warning(this, "Error", "Failed to execute query for sorting.");
    }
}



// Modify an existing ticket when "Res2" is pressed
void gs_billet::on_res2_clicked() {
    QString id_b_text = ui->bi->text().trimmed();  // The ID_B from bi (not changing)
    QString new_qrid = ui->p2->text().trimmed();   // New QRID from p2
    QString new_date_text = ui->d2->text().trimmed();  // New DATEB from d2

    bool isNumber;
    int id_b = id_b_text.toInt(&isNumber);
    if (!isNumber || id_b == 0) {
        QMessageBox::warning(this, "Erreur", "L'ID_B doit être un nombre valide!");
        return;
    }

    // Validate new date format
    QDate newDateB = QDate::fromString(new_date_text, "dd/MM/yyyy");
    if (!newDateB.isValid()) {
        QMessageBox::warning(this, "Erreur", "Le format de la date doit être JJ/MM/AAAA.");
        return;
    }

    // Update QRID, TYPE, PRIX, and DATEB for the given ID_B
    Billet billet;
    if (billet.modifierBillet(id_b, newDateB, new_qrid)) {
        refreshTableWidget();
        QMessageBox::information(this, "Succès", "Billet modifié avec succès !");
    }
}

void gs_billet::on_pdf_clicked() {
    // Open a file dialog to choose where to save the PDF
    QString filePath = QFileDialog::getSaveFileName(this, "Save PDF", "", "PDF Files (*.pdf)");

    if (filePath.isEmpty()) {
        return; // If the user cancels the file dialog, do nothing
    }

    // Create a QPdfWriter object to generate the PDF
    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize::A4);
    writer.setResolution(300);
    QPainter painter(&writer);

    if (!painter.isActive()) {
        QMessageBox::warning(this, "Error", "Failed to open PDF for writing.");
        return;
    }

    // Set font for the PDF with larger size
    QFont font("Arial", 12);  // Increased font size to 12
    painter.setFont(font);

    // Define the margins for the PDF
    int margin = 30;  // Increased margins for better spacing
    int yOffset = margin;  // Start drawing at this vertical position
    int cellHeight = 30;    // Increased height of each cell
    int cellWidth = 150;    // Increased width of each cell

    // Draw table headers
    painter.setPen(Qt::black);
    painter.setBrush(Qt::NoBrush);

    // Draw header row (th)
    for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
        QRect headerRect(margin + (col * cellWidth), yOffset, cellWidth, cellHeight);
        painter.drawRect(headerRect);
        painter.drawText(headerRect, Qt::AlignCenter, ui->tableWidget->horizontalHeaderItem(col)->text());
    }

    yOffset += cellHeight;  // Add space after header

    // Draw table data (td)
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QRect cellRect(margin + (col * cellWidth), yOffset, cellWidth, cellHeight);
            painter.drawRect(cellRect);

            QString text = ui->tableWidget->item(row, col) ? ui->tableWidget->item(row, col)->text() : "";
            painter.drawText(cellRect, Qt::AlignCenter, text);
        }
        yOffset += cellHeight;  // Add space after each row
    }

    // Finish the PDF writing process
    painter.end();

    // Notify the user
    QMessageBox::information(this, "Success", "PDF has been generated and saved.");
}

void gs_billet::on_siege_clicked() {
    // Create and show the StadiumWidget (seating layout)
    StadiumWidget *stadiumWidget = new StadiumWidget(this);
    stadiumWidget->show();
}
// Refresh table widget
void gs_billet::refreshTableWidget() {
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);

    Billet billet;
    QSqlQuery query = billet.fetchAllBillets();
    while (query.next()) {
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);

        for (int col = 0; col < 5; col++) {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(query.value(col).toString()));
        }
    }
}

void gs_billet::generateQRCodeViaAPI(const QString &tableData)
{
    qDebug() << "Generating QR code with data: " << tableData;

    // URL-encode the data for the QR code
    QString encodedData = QUrl::toPercentEncoding(tableData);
    QUrl fullUrl("https://api.qrserver.com/v1/create-qr-code/?size=200x200&data=" + encodedData);
    QNetworkRequest request(fullUrl);
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &gs_billet::onQRCodeDownloaded);
    networkManager->get(request);  // Send GET request
}

void gs_billet::onQRCodeDownloaded(QNetworkReply* reply)
{
    qDebug() << "QR code downloaded.";

    if (reply->error() == QNetworkReply::NoError) {
        QByteArray data = reply->readAll();
        QPixmap pixmap;
        if (pixmap.loadFromData(data)) {
            // Create QR code label
            QLabel *qrCodeLabel = new QLabel(this);
            qrCodeLabel->setFixedSize(300, 300);  // Set the label size to be smaller
            qrCodeLabel->setPixmap(pixmap.scaled(200, 200, Qt::KeepAspectRatio));  // Scale the pixmap to fit

            // Create the close button
            QPushButton *closeButton = new QPushButton("Close QR", this);
            closeButton->setGeometry(350, 250, 100, 40);  // Set position and size of the button
            closeButton->setObjectName("closeQRButton");  // Set an object name for easy reference

            // Connect the button's clicked signal to the slot
            connect(closeButton, &QPushButton::clicked, this, &gs_billet::onCloseQRCode);

            // Show the QR code label and button
            qrCodeLabel->show();
            closeButton->show();
        } else {
            qDebug() << "Failed to load pixmap from data.";
        }
    } else {
        qDebug() << "Error downloading QR code:" << reply->errorString();
    }

    reply->deleteLater();  // Clean up
}


void gs_billet::onQRCodeScanned(const QString &qrData)
{
    // Decode the QR data (semicolon separated values)
    QStringList rows = qrData.split("\n");
    rows.removeAll(""); // Remove empty parts manually

    for (const QString &row : rows) {
        QStringList cells = row.split(";");
        // Now you have the actual table data in 'cells'
        for (const QString &cell : cells) {
            qDebug() << "Cell Data: " << cell;
        }
    }
}

void gs_billet::displayTableDataInTextEdit(const QString &qrData)
{
    // Clear the existing text

    // Prepare text to be displayed in the QR code (based on the scanned data)
    QString tableData = "Table Data:\n";

    QSqlQuery query;
    query.prepare("SELECT * FROM billets WHERE someColumn = :qrData");
    query.bindValue(":qrData", qrData);

    if (query.exec()) {
        while (query.next()) {
            // Loop through the data and format it for plain text output
            QString rowData;
            for (int col = 0; col < query.record().count(); col++) {
                rowData += query.value(col).toString() + " ";
            }
            tableData += rowData + "\n";  // Append each row with line breaks
        }
    } else {
        tableData = "No data found for this QR code.";
    }

    // Now generate a QR code from this plain text data
    generateQRCodeViaAPI(tableData);  // Pass the formatted table data to be encoded in the QR code
}
void gs_billet::on_generate_clicked()
{
    qDebug() << "Generate button clicked.";

    // Create input field
    matchLineEdit = new QLineEdit(this);
    matchLineEdit->setPlaceholderText("Enter Match ID");
    matchLineEdit->setGeometry(50, 100, 200, 30);
    matchLineEdit->show();

    // Create Submit button
    submitBtn = new QPushButton("Submit", this);
    submitBtn->setGeometry(270, 100, 100, 30);
    connect(submitBtn, &QPushButton::clicked, this, &gs_billet::onSubmitClicked);
    submitBtn->show();

}
void gs_billet::onSubmitClicked()
{
    // Get the ID_B input from the matchLineEdit
    int id_b = matchLineEdit->text().toInt();

    // Query to fetch the corresponding data from GS_BILLET and GS_MATCH
    QSqlQuery query;
    query.prepare("SELECT b.DATEB, m.ETAT, m.LIEU "
                  "FROM GS_BILLET b "
                  "JOIN GS_MATCH m ON b.IDMATCH_B = m.ID_M "
                  "WHERE b.IDMATCH_B = :id_b");
    query.bindValue(":id_b", id_b);


    if (query.exec() && query.next()) {
        // Fetch the values from the query
        QString datebValue = query.value("DATEB").toString();
        QString etatValue = query.value("ETAT").toString();
        QString lieuValue = query.value("LIEU").toString();

        // Format the data for the QR code
        QString qrData = datebValue + " : " + etatValue + " vs " + lieuValue;

        // Call the QR code generation function with the formatted data
        generateQRCodeViaAPI(qrData);
    } else {
        // If the query fails or no data found, show an error message
        QMessageBox::warning(this, "No Data Found", "No data found for the provided ID_B.");
    }
}

QLineEdit *matchLineEdit = nullptr;
QPushButton *submitBtn = nullptr;
QPushButton *goBtn = nullptr;
void gs_billet::onGoClicked()
{
    QString qrData = "DATEB: " + datebValue + "\nETAT: " + etatValue + "\nLIEU: " + lieuValue;
    generateQRCodeViaAPI(qrData);
}

void gs_billet::onCloseQRCode()
{
    // Find and hide the QR code label
    QLabel *qrCodeLabel = findChild<QLabel*>();
    if (qrCodeLabel) {
        qrCodeLabel->hide();
    }

    // Find and hide the close button
    QPushButton *closeButton = findChild<QPushButton*>("closeQRButton");
    if (closeButton) {
        closeButton->hide();
    }
}
