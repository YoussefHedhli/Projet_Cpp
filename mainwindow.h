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




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

     // Button click handlers
     void on_btri_clicked();     //  triParId() when clicking "btri"
     void on_btri2_clicked();
void afficherStatistiquesPaysGraph();
private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
