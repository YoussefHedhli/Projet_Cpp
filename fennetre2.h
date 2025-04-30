#ifndef FENNETRE2_H
#define FENNETRE2_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include "mainwindow.h"

namespace Ui {
class fennetre2;
}

class fennetre2 : public QDialog
{
    Q_OBJECT

public:
    explicit fennetre2(QString email,QWidget *parent = nullptr);
    ~fennetre2();

private slots:
    void on_pushButton_sauvgrd_clicked();

private:
    Ui::fennetre2 *ui;
    QString email;
};

#endif // FENNETRE2_H
