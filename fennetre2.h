#ifndef FENNETRE2_H
#define FENNETRE2_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include "mainwindow.h"
#include "arduino.h"

namespace Ui {
class fennetre2;
}

class fennetre2 : public QDialog
{
    Q_OBJECT

public:
    explicit fennetre2(Arduino* a, QString email,QWidget *parent = nullptr);
    ~fennetre2();

private slots:
    void on_pushButton_sauvgrd_clicked();
    void paintEvent(QPaintEvent *event);

private:
    Ui::fennetre2 *ui;
    QString email;
    Arduino* Arduino;
};

#endif // FENNETRE2_H
