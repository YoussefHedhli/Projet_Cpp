#ifndef FENNETRE1_H
#define FENNETRE1_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class fennetre1;
}
QT_END_NAMESPACE

class fennetre1 : public QMainWindow
{
    Q_OBJECT

public:
    fennetre1(QWidget *parent = nullptr);
    ~fennetre1();
private slots:
    //void ajouterEmploye();

    void on_pushButton_AJemp_clicked();
    void on_pushButton_suprimer_clicked();
    void showEmployes();
    void on_pushButton_modifier_clicked();

private:
    Ui::fennetre1 *ui;
    bool isModifying;  // Declare the flag here
};
#endif // FENNETRE1_H


