#ifndef GS_MATCH_H
#define GS_MATCH_H

#include <QMainWindow>
#include "match.h"
#include <QtCharts>
#include "arduino.h"



QT_BEGIN_NAMESPACE
namespace Ui {
class gs_match;
}
QT_END_NAMESPACE

class gs_match : public QMainWindow
{
    Q_OBJECT

public:
    explicit gs_match(Arduino* a , QWidget *parent = nullptr);
    ~gs_match();

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
    void on_equiepass_clicked();
    void on_billetpass_clicked();
    void on_sponsorpass_clicked();
    void on_employerpass_clicked();


private:
    Ui::gs_match *ui;
    Match m;
    Arduino* arduino;
};

#endif // GS_MATCH_H
