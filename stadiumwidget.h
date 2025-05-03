#ifndef STADIUMWIDGET_H
#define STADIUMWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QMap>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlError>

class StadiumWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StadiumWidget(QWidget *parent = nullptr);
    ~StadiumWidget();

private slots:
    void showSeatOverlay();      // Slot to show seat overlay
    void reserveSeat(QString seatId, QString id, QString date);  // Slot to reserve a seat

private:
    void fetchReservedSeatsFromDatabase();  // Declare the function to fetch reserved seats from the database

    QGridLayout *seatLayout;  // Layout for the seats (grid layout)
    QMap<QString, QString> reservedSeats;  // Map to track reserved seats
};

#endif // STADIUMWIDGET_H
