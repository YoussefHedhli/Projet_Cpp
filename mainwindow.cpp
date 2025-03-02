#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "connection.h"
#include "match.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    Connection c;
    bool connectionSuccess = c.createconnect();
    if (connectionSuccess) {
        QMessageBox::information(this, "Database", "Connexion réussie !");
    } else {
        QMessageBox::critical(this, "Database", "Échec de connexion !");
    }

    connect(ui->btnAjouter, &QPushButton::clicked, this, &MainWindow::addMatchToDatabase);
    connect(ui->btnSupprimer, &QPushButton::clicked, this, &MainWindow::deleteMatch);

    updateMatchDisplay();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::updateMatchDisplay() {
    QVector<QVector<QString>> data = m.afficher();

    ui->tableWidget->setRowCount(data.size());
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"ID", "Date", "Lieu", "État"});

    for (int row = 0; row < data.size(); ++row) {
        for (int col = 0; col < data[row].size(); ++col) {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(data[row][col]));
        }
    }
}

void MainWindow::addMatchToDatabase() {
    QString date = ui->lineEditDate->text().trimmed();
    QString lieu = ui->lineEditLieu->text().trimmed();
    QString etat = ui->comboEtat->currentText();

    if (date.isEmpty() || lieu.isEmpty() || etat.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    Match m(0, date, lieu, etat);
    if (m.ajouter()) {
        QMessageBox::information(this, "Succès", "Match ajouté !");
        updateMatchDisplay();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout du match.");
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
