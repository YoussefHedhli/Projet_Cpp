#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTableView>

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

    //void on_tableView_clicked(const QModelIndex &index);

private slots:
    void ajouterEquipe();
    void afficherEquipes();
    void supprimerEquipe();
     void modifierEquipe();
     void on_AFF_clicked(const QModelIndex &index);
     void rechercherEquipe();
     void exporterPDF();
     void triParId();            // Sort by ID (ascending/descending)
     void triParAlphabet();      // Sort alphabetically (ascending/descending)
    void on_updateButton_clicked();
     // Button click handlers
     void on_btri_clicked();     //  triParId() when clicking "btri"
     void on_btri2_clicked();
    void afficherStatistiquesPaysGraph();
     void on_btnRecommander_clicked(); // Bouton recommander

void on_btnRecommander_clicked1();



private:
    Ui::MainWindow *ui;
    QString nom;
    QString getLieuMatchDeEquipe(const QString &equipeNom);
    QString calculerEtatForme(const QString &equipeNom); // ton métier
    QString recommanderTactique(const QString &paysEquipe, const QString &lieuMatch);
    // Affichage graphique
    void afficherTactiqueGraphique(const QString &tactique);

    void placerJoueur(QWidget *joueur, int x, int y);

};

#endif // MAINWINDOW_H
