/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QFrame *Mailing;
    QPushButton *pushButton_5;
    QLabel *label_10;
    QFrame *Mailing_4;
    QPushButton *pushButton_14;
    QLabel *label_13;
    QFrame *Mailing_5;
    QPushButton *pushButton_15;
    QTextEdit *textEdit_3;
    QLabel *label_14;
    QLineEdit *lineEdit_12;
    QFrame *Mailing_3;
    QLabel *label_15;
    QPushButton *pushButton_7;
    QFrame *formulere;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton_3;
    QLabel *label_11;
    QLabel *label_6;
    QListWidget *listWidget;
    QFrame *frame;
    QPushButton *pushButton_4;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QLabel *label_pic2;
    QLabel *label_7;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit_11;
    QPushButton *pushButton_8;
    QPushButton *pushButton;
    QTableWidget *tableWidget;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1313, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(-30, -30, 1341, 631));
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #000000;\n"
"    color: #FFFFFF;\n"
"}\n"
""));
        label->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/476346398_1815866255484140_2102298479494468270_n.jpg")));
        label->setScaledContents(true);
        Mailing = new QFrame(centralwidget);
        Mailing->setObjectName("Mailing");
        Mailing->setGeometry(QRect(450, 320, 361, 161));
        Mailing->setAutoFillBackground(true);
        Mailing->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #000000;\n"
"    color: #FFFFFF;\n"
"}\n"
""));
        Mailing->setFrameShape(QFrame::Shape::StyledPanel);
        Mailing->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_5 = new QPushButton(Mailing);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(20, 80, 141, 31));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #808080;   /* Grey border */\n"
"    border-radius: 10px;         /* Round the corners */\n"
"    padding: 0 8px;              /* Padding inside the button */\n"
"    background: #808080;         /* Grey background */\n"
"    color: white;                /* White text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #505050;   /* Darker grey on hover */\n"
"}\n"
""));
        label_10 = new QLabel(Mailing);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 10, 131, 20));
        Mailing_4 = new QFrame(Mailing);
        Mailing_4->setObjectName("Mailing_4");
        Mailing_4->setGeometry(QRect(210, 0, 221, 161));
        Mailing_4->setAutoFillBackground(false);
        Mailing_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #000000;\n"
"    color: #FFFFFF;\n"
"}\n"
""));
        Mailing_4->setFrameShape(QFrame::Shape::StyledPanel);
        Mailing_4->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_14 = new QPushButton(Mailing_4);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(10, 80, 131, 31));
        pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #808080;   /* Grey border */\n"
"    border-radius: 10px;         /* Round the corners */\n"
"    padding: 0 8px;              /* Padding inside the button */\n"
"    background: #808080;         /* Grey background */\n"
"    color: white;                /* White text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #505050;   /* Darker grey on hover */\n"
"}\n"
""));
        label_13 = new QLabel(Mailing_4);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(40, 10, 71, 20));
        Mailing_5 = new QFrame(Mailing_4);
        Mailing_5->setObjectName("Mailing_5");
        Mailing_5->setGeometry(QRect(180, 10, 181, 251));
        Mailing_5->setFrameShape(QFrame::Shape::StyledPanel);
        Mailing_5->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_15 = new QPushButton(Mailing_5);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(20, 210, 141, 31));
        pushButton_15->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border:2px solid gray;\n"
"border-radius: 10px;\n"
"padding:0 8px;\n"
"background:gray;\n"
"}"));
        textEdit_3 = new QTextEdit(Mailing_5);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(20, 100, 141, 101));
        label_14 = new QLabel(Mailing_5);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(60, 10, 81, 20));
        lineEdit_12 = new QLineEdit(Mailing_5);
        lineEdit_12->setObjectName("lineEdit_12");
        lineEdit_12->setGeometry(QRect(20, 50, 141, 28));
        Mailing_3 = new QFrame(centralwidget);
        Mailing_3->setObjectName("Mailing_3");
        Mailing_3->setGeometry(QRect(930, 290, 181, 251));
        Mailing_3->setAutoFillBackground(true);
        Mailing_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #000000;\n"
"    color: #FFFFFF;\n"
"}\n"
""));
        Mailing_3->setFrameShape(QFrame::Shape::StyledPanel);
        Mailing_3->setFrameShadow(QFrame::Shadow::Raised);
        label_15 = new QLabel(Mailing_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(50, 10, 81, 20));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(720, 90, 61, 29));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #808080;   /* Grey border */\n"
"    border-radius: 10px;         /* Round the corners */\n"
"    padding: 0 8px;              /* Padding inside the button */\n"
"    background: #808080;         /* Grey background */\n"
"    color: white;                /* White text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #505050;   /* Darker grey on hover */\n"
"}\n"
""));
        formulere = new QFrame(centralwidget);
        formulere->setObjectName("formulere");
        formulere->setGeometry(QRect(170, 270, 181, 301));
        formulere->setAutoFillBackground(true);
        formulere->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #000000;\n"
"    color: #FFFFFF;\n"
"}\n"
""));
        formulere->setFrameShape(QFrame::Shape::StyledPanel);
        formulere->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(formulere);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 50, 61, 21));
        label_3 = new QLabel(formulere);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 130, 61, 21));
        label_4 = new QLabel(formulere);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 170, 41, 21));
        label_5 = new QLabel(formulere);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 90, 61, 21));
        lineEdit = new QLineEdit(formulere);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(90, 50, 81, 28));
        lineEdit_2 = new QLineEdit(formulere);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(90, 90, 81, 28));
        lineEdit_3 = new QLineEdit(formulere);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(90, 130, 81, 28));
        lineEdit_4 = new QLineEdit(formulere);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(90, 170, 81, 28));
        pushButton_3 = new QPushButton(formulere);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(20, 260, 151, 31));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #808080;   /* Grey border */\n"
"    border-radius: 10px;         /* Round the corners */\n"
"    padding: 0 8px;              /* Padding inside the button */\n"
"    background: #808080;         /* Grey background */\n"
"    color: white;                /* White text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #505050;   /* Darker grey on hover */\n"
"}\n"
""));
        label_11 = new QLabel(formulere);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(50, 10, 81, 20));
        label_6 = new QLabel(formulere);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 210, 41, 21));
        listWidget = new QListWidget(formulere);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(100, 210, 61, 21));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(230, 20, 761, 61));
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
        label_pic2->setGeometry(QRect(-140, -10, 901, 81));
        label_pic2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #000000;\n"
"    color: #FFFFFF;\n"
"}\n"
""));
        label_7 = new QLabel(frame);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(-20, -30, 121, 111));
        label_7->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/ac26d84d-c0ab-4a53-b362-c5e005f6e792-removebg-preview.png")));
        label_7->setScaledContents(true);
        label_pic2->raise();
        pushButton_4->raise();
        pushButton_9->raise();
        pushButton_10->raise();
        pushButton_11->raise();
        pushButton_12->raise();
        label_7->raise();
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(880, 90, 91, 29));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #808080;   /* Grey border */\n"
"    border-radius: 10px;         /* Round the corners */\n"
"    padding: 0 8px;              /* Padding inside the button */\n"
"    background: #808080;         /* Grey background */\n"
"    color: white;                /* White text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #505050;   /* Darker grey on hover */\n"
"}\n"
"\n"
""));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(512, 90, 91, 29));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #808080;   /* Grey border */\n"
"    border-radius: 10px;         /* Round the corners */\n"
"    padding: 0 8px;              /* Padding inside the button */\n"
"    background: #808080;         /* Grey background */\n"
"    color: white;                /* White text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #505050;   /* Darker grey on hover */\n"
"}\n"
""));
        lineEdit_11 = new QLineEdit(centralwidget);
        lineEdit_11->setObjectName("lineEdit_11");
        lineEdit_11->setGeometry(QRect(230, 90, 271, 28));
        lineEdit_11->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #000000;\n"
"    color: #FFFFFF;\n"
"}\n"
""));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(620, 90, 83, 29));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #808080;   /* Grey border */\n"
"    border-radius: 10px;         /* Round the corners */\n"
"    padding: 0 8px;              /* Padding inside the button */\n"
"    background: #808080;         /* Grey background */\n"
"    color: white;                /* White text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #505050;   /* Darker grey on hover */\n"
"}\n"
""));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(790, 90, 83, 29));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #808080;   /* Grey border */\n"
"    border-radius: 10px;         /* Round the corners */\n"
"    padding: 0 8px;              /* Padding inside the button */\n"
"    background: #808080;         /* Grey background */\n"
"    color: white;                /* White text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #505050;   /* Darker grey on hover */\n"
"}\n"
""));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(290, 130, 621, 121));
        tableWidget->setMaximumSize(QSize(763, 16777215));
        tableWidget->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #000000;\n"
"    color: #FFFFFF;\n"
"}\n"
""));
        MainWindow->setCentralWidget(centralwidget);
        label->raise();
        Mailing->raise();
        Mailing_3->raise();
        pushButton_7->raise();
        frame->raise();
        pushButton_2->raise();
        pushButton_6->raise();
        lineEdit_11->raise();
        pushButton_8->raise();
        pushButton->raise();
        tableWidget->raise();
        formulere->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Start Simulation", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Match Simulation", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Visit Calendar", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Calendar", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Envoyer", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Mailing", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Equipe 1", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Lieu", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Equipe 2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Employer", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Etat", nullptr));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "Started", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "Pending", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "Ended", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled);

        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Sponsor", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Billet", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Employer", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Match", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Equipe", nullptr));
        label_pic2->setText(QString());
        label_7->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Tri par ID", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Match", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Lieu", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Etat", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
