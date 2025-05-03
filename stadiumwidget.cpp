#include "stadiumwidget.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QLabel>
#include <QDate>

StadiumWidget::StadiumWidget(QWidget *parent)
    : QWidget(parent)
{
    showSeatOverlay();  // Automatically show the seat overlay when the widget is created
}

StadiumWidget::~StadiumWidget() {}

void StadiumWidget::showSeatOverlay() {
    fetchReservedSeatsFromDatabase();  // Fetch the reserved seats from the database

    // Debugging step: check if reservedSeats is populated
    qDebug() << "Reserved seats (QRID): " << reservedSeats.keys();

    QDialog *overlay = new QDialog(this);
    overlay->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    overlay->setAttribute(Qt::WA_DeleteOnClose);
    overlay->setFixedSize(800, 300);  // Adjust size to fit the 3 rows with 20 seats each
    overlay->setStyleSheet("background-color: white;");

    QVBoxLayout *overlayLayout = new QVBoxLayout(overlay);

    // Add close button (styled red)
    QPushButton *closeButton = new QPushButton("X", overlay);
    closeButton->setFixedSize(30, 30);
    closeButton->setStyleSheet("background-color: red; color: white; border: none; font-weight: bold; border-radius: 5px;");
    overlayLayout->addWidget(closeButton, 0, Qt::AlignRight);
    connect(closeButton, &QPushButton::clicked, overlay, &QDialog::accept);

    // Create the seat grid layout
    seatLayout = new QGridLayout();
    seatLayout->setSpacing(5);  // Adjust spacing for a compact layout

    // Define row and column limits for the grid
    const int rows = 3;  // 3 rows of seats (101-120, 201-220, 301-320)
    const int cols = 20;  // 20 columns per row

    // Loop through all rows and columns to create seat labels
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            // Create seat ID for each block (starting from 101, 102, ..., 120, 201, ..., 220, etc.)
            int seatId = (row + 1) * 100 + (col + 1);  // For row 1: 101-120, for row 2: 201-220, etc.

            QString seatIdStr = QString::number(seatId);  // Convert seat ID to string for display

            QLabel *seatLabel = new QLabel(seatIdStr, overlay);  // Use QLabel to display seat ID
            seatLabel->setAlignment(Qt::AlignCenter);
            seatLabel->setFixedSize(35, 35);  // Adjust size to fit the seats properly

            // Check if the seat is reserved (i.e., QRID is in the reservedSeats list)
            if (reservedSeats.contains(seatIdStr)) {
                qDebug() << "Seat " << seatIdStr << " is reserved.";  // Debugging step
                seatLabel->setStyleSheet("background-color: red; color: white;");  // Red for reserved
            } else {
                qDebug() << "Seat " << seatIdStr << " is available.";  // Debugging step
                seatLabel->setStyleSheet("background-color: green; color: white;");  // Green for available
            }

            seatLayout->addWidget(seatLabel, row, col);  // Add the seat label to the grid layout
        }
    }

    overlayLayout->addLayout(seatLayout);
    overlay->exec();
}

void StadiumWidget::reserveSeat(QString seatId, QString id, QString date) {
    reservedSeats.insert(seatId, "Reserved");  // Insert the seat into the reservedSeats map
    qDebug() << "Seat " << seatId << " reserved by " << id << " on " << date;
    showSeatOverlay(); // Refresh the seat overlay to reflect the new reserved seat
}

void StadiumWidget::fetchReservedSeatsFromDatabase() {
    reservedSeats.clear();  // Clear the current list of reserved seats

    // Query to fetch all reserved seats based on QRID (adjusted according to your database schema)
    QSqlQuery query("SELECT QRID FROM PROJET.GS_BILLET");  // Fetch QRID for all reserved seats
    while (query.next()) {
        QString seatId = query.value(0).toString();  // Retrieve each seat QRID
        reservedSeats.insert(seatId, "Reserved");  // Insert the QRID into the reservedSeats map
        qDebug() << "Fetched reserved seat (QRID): " << seatId;  // Debugging step
    }
}
