#ifndef GS_EQUIPE_H
#define GS_EQUIPE_H
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
class gs_equipe;
}

class gs_equipe  : public QMainWindow
{
    Q_OBJECT

public:
    explicit gs_equipe (QWidget *parent = nullptr);
    ~gs_equipe ();
    // mainwindow.h
public slots:

private slots:
    void ajouterEquipe();
    void afficherEquipes();
    void supprimerEquipe();
     void modifierEquipe();
     void on_AFF_clicked(const QModelIndex &index);
     void rechercherEquipe();
    void on_updateButton_clicked();
     void exporterPDF();
     void afficherStatistiques();
      void onComboTriChanged(int index);


private:
    Ui::gs_equipe  *ui;
    QString nom;
    Equipe equipe;
void on_combotri_currentIndexChanged(int index);

void trierEquipes(const QString &critere);
    void on_btnTactique_clicked();
    void on_comboTrii_currentIndexChanged(const QString &tri);


};

#endif // GS_EQUIPE_H
