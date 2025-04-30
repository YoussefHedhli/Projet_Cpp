#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fennetre1.h"
#include "fennetre2.h"
#include "arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void readCardData();

private slots:
    void on_pushButton_login_clicked();
    void on_pushButton_mdp_oublie_clicked();
    void pushButton_readCardData_clicked();
    //void on_btn_voice_login_clicked();
private:
    Ui::MainWindow *ui;
    fennetre1 *fenetre1Window;
    QSerialPort *serial;
    arduino ard;
};
#endif // MAINWINDOW_H
