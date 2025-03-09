#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "match.h"
#include <QtCharts>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addMatchToDatabase();
    void deleteMatch();
    void updateMatchDisplay();
    void on_btnModifier_clicked(); // Slot declaration for the button click
    void modifyMatch();
    void on_tableWidget_itemSelectionChanged(); // Slot declaration for item selection change
    void searchMatch();
    void sortMatchesByID();
    void generatePDF();
    void displayStatistics();

private:
    Ui::MainWindow *ui;
    Match m;
};

#endif // MAINWINDOW_H
