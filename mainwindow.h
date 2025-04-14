#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTableView>
#include "Equipe.h"
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QBarCategoryAxis>
#include <QComboBox>
#include <QPixmap>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    // mainwindow.h
public slots:
    void exporterPDF();

    //void on_tableView_clicked(const QModelIndex &index);

private slots:
    void ajouterEquipe();
    void afficherEquipes();
    void supprimerEquipe();
     void modifierEquipe();
     void on_AFF_clicked(const QModelIndex &index);
     void rechercherEquipe();
     //void exporterPDF();

    void on_updateButton_clicked();
     // Button click handlers

     void afficherStatistiques();
     //void on_btnRecommander_clicked(); // Bouton recommander

    //void on_btnRecommander_clicked1();
      void onComboTriChanged(int index);


     // void getTacticFromPython(const QString& teamName);
      //void getTacticFromWeb(const QString& teamName);
      //void scrapeTransfermarkt(const QString& teamName);




private:
    Ui::MainWindow *ui;
    QString nom;
    Equipe equipe;
void on_combotri_currentIndexChanged(int index);

void trierEquipes(const QString &critere);
    void on_btnTactique_clicked();
    void on_comboTrii_currentIndexChanged(const QString &tri);


};

#endif // MAINWINDOW_H
