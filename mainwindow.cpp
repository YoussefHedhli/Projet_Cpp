#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sponsor.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_sponsor_clicked()
{
    sponsor *spon = new sponsor(this); // Création d'une instance de la fenêtre sponsor
    spon->setModal(true);  // Empêche l'utilisateur d'interagir avec la fenêtre principale tant que sponsor est ouvert
    spon->exec();  // Affichage en mode boîte de dialogue
}



