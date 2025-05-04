#ifndef FENNETRE1_H
#define FENNETRE1_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSortFilterProxyModel>
#include <QDialog>
#include "arduino.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class fennetre1;
}
QT_END_NAMESPACE

class fennetre1 : public QDialog
{
    Q_OBJECT

public:
    void afficherStatistiquesEmployes();
    fennetre1(QWidget *parent = nullptr);
    ~fennetre1();
private slots:
    //void ajouterEmploye();

    void on_pushButton_AJemp_3_clicked();
    void on_pushButton_suprimer_clicked();
    void showEmployes();
    void on_pushButton_modifier_clicked();
    void on_pushButton_recherche_clicked();
    void on_pushButton_PDF_clicked();
    void on_comboBox_currentIndexChanged(int index);
    void on_btnShowChart_3_clicked();
    void on_pushButton_mailing_clicked();
    bool verifyEmailExistsInDB(const QString& email);
    void on_pushButton_selectFile_clicked();
    void on_match_clicked();
    void on_equipe_clicked();
    void on_billet_clicked();
    void on_sponsor_clicked();
    void paintEvent(QPaintEvent *event);

private:
    Ui::fennetre1 *ui;
    bool isModifying;  // Declare the flag here
    QString attachedFilePath;
    Arduino *arduino;
    QString currentUserRole;
};

#endif // FENNETRE1_H
