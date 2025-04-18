#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "match.h"
#include <QtCharts>
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
    explicit MainWindow(Arduino* a , QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void paintEvent(QPaintEvent *event);
    void addMatchToDatabase();
    void deleteMatch();
    void updateMatchDisplay();
    void on_btnModifier_clicked(); // Slot declaration for the button click
    void modifyMatch();
    void on_tableWidget_itemSelectionChanged(); // Slot declaration for item selection change
    void searchMatch();
    void sortMatches(const QString& sortOption);
    void generatePDF();
    void displayStatistics();
    void on_sim_clicked();
    void onCalendarDateSelected(const QDate &date);
    void highlightMatchDates();
    void onSortOptionChanged(int index);
    void onCalendarDateHovered(const QDate &date);


private:
    Ui::MainWindow *ui;
    Match m;
    Arduino* arduino;
};

#endif // MAINWINDOW_H
