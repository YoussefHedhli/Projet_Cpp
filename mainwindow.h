#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTableView>  // Ajoute cette ligne si ce n'est pas déjà fait

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

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
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
