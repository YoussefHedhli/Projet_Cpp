/********************************************************************************
** Form generated from reading UI file 'calendar.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALENDAR_H
#define UI_CALENDAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Calendar
{
public:
    QLabel *label;
    QCalendarWidget *calendarWidget;
    QTableWidget *tableWidget;
    QFrame *frame;
    QPushButton *pushButton_4;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QLabel *label_pic2;
    QLabel *label_7;

    void setupUi(QDialog *Calendar)
    {
        if (Calendar->objectName().isEmpty())
            Calendar->setObjectName("Calendar");
        Calendar->resize(1305, 560);
        Calendar->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    border: 2px solid #4CAF50;\n"
"    font-size: 14px;\n"
"    background-color: #F9F9F9;\n"
"}\n"
"QTableWidget::item {\n"
"    padding: 5px;\n"
"}\n"
"QCalendarWidget {\n"
"    background-color: white;\n"
"    border-radius: 10px;\n"
"}\n"
"QLabel {\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"}\n"
""));
        label = new QLabel(Calendar);
        label->setObjectName("label");
        label->setGeometry(QRect(-50, -40, 1361, 591));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/476346398_1815866255484140_2102298479494468270_n.jpg")));
        label->setScaledContents(true);
        calendarWidget = new QCalendarWidget(Calendar);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(230, 240, 421, 281));
        calendarWidget->setGridVisible(true);
        tableWidget = new QTableWidget(Calendar);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(700, 300, 371, 192));
        tableWidget->setAutoFillBackground(false);
        frame = new QFrame(Calendar);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(260, 30, 761, 61));
        frame->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #000000;\n"
"    color: #FFFFFF;\n"
"}\n"
""));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_4 = new QPushButton(frame);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(610, 10, 111, 41));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #003153;   /* Prussian Blue border */\n"
"    border-radius: 10px;         /* Round the corners */\n"
"    padding: 0 8px;              /* Padding inside the button */\n"
"    background: #003153;         /* Prussian Blue background */\n"
"    color: white;                /* White text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #001f33; /* Darker Prussian blue on hover */\n"
"}\n"
"\n"
""));
        pushButton_9 = new QPushButton(frame);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(490, 10, 111, 41));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #003153;   /* Prussian Blue border */\n"
"    border-radius: 10px;         /* Round the corners */\n"
"    padding: 0 8px;              /* Padding inside the button */\n"
"    background: #003153;         /* Prussian Blue background */\n"
"    color: white;                /* White text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #001f33; /* Darker Prussian blue on hover */\n"
"}\n"
""));
        pushButton_10 = new QPushButton(frame);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(370, 10, 111, 41));
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #003153;   /* Prussian Blue border */\n"
"    border-radius: 10px;         /* Round the corners */\n"
"    padding: 0 8px;              /* Padding inside the button */\n"
"    background: #003153;         /* Prussian Blue background */\n"
"    color: white;                /* White text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #001f33; /* Darker Prussian blue on hover */\n"
"}\n"
""));
        pushButton_11 = new QPushButton(frame);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(250, 10, 111, 41));
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #003153;   /* Prussian Blue border */\n"
"    border-radius: 10px;         /* Round the corners */\n"
"    padding: 0 8px;              /* Padding inside the button */\n"
"    background: #003153;         /* Prussian Blue background */\n"
"    color: white;                /* White text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #001f33; /* Darker Prussian blue on hover */\n"
"}\n"
""));
        pushButton_12 = new QPushButton(frame);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(130, 10, 111, 41));
        pushButton_12->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #003153;   /* Prussian Blue border */\n"
"    border-radius: 10px;         /* Round the corners */\n"
"    padding: 0 8px;              /* Padding inside the button */\n"
"    background: #003153;         /* Prussian Blue background */\n"
"    color: white;                /* White text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #001f33; /* Darker Prussian blue on hover */\n"
"}\n"
""));
        label_pic2 = new QLabel(frame);
        label_pic2->setObjectName("label_pic2");
        label_pic2->setGeometry(QRect(-20, -10, 791, 81));
        label_7 = new QLabel(frame);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, -20, 111, 111));
        label_7->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/ac26d84d-c0ab-4a53-b362-c5e005f6e792-removebg-preview.png")));
        label_7->setScaledContents(true);
        label_pic2->raise();
        pushButton_4->raise();
        pushButton_9->raise();
        pushButton_10->raise();
        pushButton_11->raise();
        pushButton_12->raise();
        label_7->raise();

        retranslateUi(Calendar);

        QMetaObject::connectSlotsByName(Calendar);
    } // setupUi

    void retranslateUi(QDialog *Calendar)
    {
        Calendar->setWindowTitle(QCoreApplication::translate("Calendar", "Dialog", nullptr));
        label->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Calendar", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Calendar", "Teams", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Calendar", "Score", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Calendar", "Sponsor", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Calendar", "Billet", nullptr));
        pushButton_10->setText(QCoreApplication::translate("Calendar", "Employer", nullptr));
        pushButton_11->setText(QCoreApplication::translate("Calendar", "Match", nullptr));
        pushButton_12->setText(QCoreApplication::translate("Calendar", "Equipe", nullptr));
        label_pic2->setText(QString());
        label_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Calendar: public Ui_Calendar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALENDAR_H
