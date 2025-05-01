/********************************************************************************
** Form generated from reading UI file 'gs_match.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GS_MATCH_H
#define UI_GS_MATCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gs_match
{
public:
    QWidget *centralwidget;
    QLabel *label_pic;
    QFrame *Mailing;
    QPushButton *sim;
    QLabel *label_10;
    QPushButton *pdfButton;
    QFrame *formulere;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEditTeam1;
    QLineEdit *lineEditTeam2;
    QLineEdit *lineEditDate;
    QLineEdit *lineEditLieu;
    QPushButton *btnAjouter;
    QLabel *label_11;
    QLabel *label_6;
    QComboBox *etats;
    QFrame *frame;
    QPushButton *pushButton_4;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *equipepass;
    QLabel *label_pic2;
    QLabel *ball;
    QPushButton *btnSupprimer;
    QPushButton *recherche;
    QPushButton *btnModifier;
    QTableWidget *tableWidget;
    QLabel *label_8;
    QLineEdit *rechtxt;
    QCalendarWidget *calendar;
    QWidget *stat;
    QComboBox *tri;

    void setupUi(QMainWindow *gs_match)
    {
        if (gs_match->objectName().isEmpty())
            gs_match->setObjectName("gs_match");
        gs_match->resize(1313, 600);
        centralwidget = new QWidget(gs_match);
        centralwidget->setObjectName("centralwidget");
        label_pic = new QLabel(centralwidget);
        label_pic->setObjectName("label_pic");
        label_pic->setGeometry(QRect(-30, -30, 1341, 631));
        label_pic->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #000000;\n"
"    color: #FFFFFF;\n"
"}\n"
""));
        label_pic->setScaledContents(true);
        Mailing = new QFrame(centralwidget);
        Mailing->setObjectName("Mailing");
        Mailing->setGeometry(QRect(410, 300, 181, 161));
        Mailing->setAutoFillBackground(true);
        Mailing->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #000000;\n"
"    color: #FFFFFF;\n"
"}\n"
""));
        Mailing->setFrameShape(QFrame::Shape::StyledPanel);
        Mailing->setFrameShadow(QFrame::Shadow::Raised);
        sim = new QPushButton(Mailing);
        sim->setObjectName("sim");
        sim->setGeometry(QRect(20, 80, 141, 31));
        sim->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pdfButton = new QPushButton(centralwidget);
        pdfButton->setObjectName("pdfButton");
        pdfButton->setGeometry(QRect(660, 90, 61, 29));
        pdfButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lineEditTeam1 = new QLineEdit(formulere);
        lineEditTeam1->setObjectName("lineEditTeam1");
        lineEditTeam1->setGeometry(QRect(90, 50, 81, 28));
        lineEditTeam2 = new QLineEdit(formulere);
        lineEditTeam2->setObjectName("lineEditTeam2");
        lineEditTeam2->setGeometry(QRect(90, 90, 81, 28));
        lineEditDate = new QLineEdit(formulere);
        lineEditDate->setObjectName("lineEditDate");
        lineEditDate->setGeometry(QRect(90, 130, 81, 28));
        lineEditLieu = new QLineEdit(formulere);
        lineEditLieu->setObjectName("lineEditLieu");
        lineEditLieu->setGeometry(QRect(90, 170, 81, 28));
        btnAjouter = new QPushButton(formulere);
        btnAjouter->setObjectName("btnAjouter");
        btnAjouter->setGeometry(QRect(20, 260, 151, 31));
        btnAjouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        etats = new QComboBox(formulere);
        etats->addItem(QString());
        etats->addItem(QString());
        etats->addItem(QString());
        etats->addItem(QString());
        etats->setObjectName("etats");
        etats->setGeometry(QRect(90, 210, 82, 28));
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
        equipepass = new QPushButton(frame);
        equipepass->setObjectName("equipepass");
        equipepass->setGeometry(QRect(130, 10, 111, 41));
        equipepass->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        ball = new QLabel(frame);
        ball->setObjectName("ball");
        ball->setGeometry(QRect(-20, -30, 121, 111));
        ball->setScaledContents(true);
        label_pic2->raise();
        pushButton_4->raise();
        pushButton_9->raise();
        pushButton_10->raise();
        pushButton_11->raise();
        equipepass->raise();
        ball->raise();
        btnSupprimer = new QPushButton(centralwidget);
        btnSupprimer->setObjectName("btnSupprimer");
        btnSupprimer->setGeometry(QRect(840, 90, 91, 29));
        btnSupprimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        recherche = new QPushButton(centralwidget);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(440, 90, 91, 29));
        recherche->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        btnModifier = new QPushButton(centralwidget);
        btnModifier->setObjectName("btnModifier");
        btnModifier->setGeometry(QRect(740, 90, 83, 29));
        btnModifier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        tableWidget->setGeometry(QRect(270, 130, 621, 121));
        tableWidget->setMaximumSize(QSize(763, 16777215));
        tableWidget->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #000000;\n"
"    color: #FFFFFF;\n"
"}\n"
""));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 0, 1351, 611));
        rechtxt = new QLineEdit(centralwidget);
        rechtxt->setObjectName("rechtxt");
        rechtxt->setGeometry(QRect(130, 90, 271, 28));
        rechtxt->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #000000;\n"
"    color: #FFFFFF;\n"
"}\n"
""));
        calendar = new QCalendarWidget(centralwidget);
        calendar->setObjectName("calendar");
        calendar->setGeometry(QRect(620, 290, 291, 251));
        calendar->setGridVisible(true);
        stat = new QWidget(centralwidget);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(940, 80, 341, 351));
        tri = new QComboBox(centralwidget);
        tri->setObjectName("tri");
        tri->setGeometry(QRect(550, 90, 82, 28));
        gs_match->setCentralWidget(centralwidget);
        label_8->raise();
        label_pic->raise();
        Mailing->raise();
        pdfButton->raise();
        frame->raise();
        btnSupprimer->raise();
        recherche->raise();
        btnModifier->raise();
        tableWidget->raise();
        formulere->raise();
        rechtxt->raise();
        calendar->raise();
        stat->raise();
        tri->raise();

        retranslateUi(gs_match);

        QMetaObject::connectSlotsByName(gs_match);
    } // setupUi

    void retranslateUi(QMainWindow *gs_match)
    {
        gs_match->setWindowTitle(QCoreApplication::translate("gs_match", "MainWindow", nullptr));
        label_pic->setText(QString());
        sim->setText(QCoreApplication::translate("gs_match", "Start Simulation", nullptr));
        label_10->setText(QCoreApplication::translate("gs_match", "Match Simulation", nullptr));
        pdfButton->setText(QCoreApplication::translate("gs_match", "PDF", nullptr));
        label_2->setText(QCoreApplication::translate("gs_match", "Equipe 1", nullptr));
        label_3->setText(QCoreApplication::translate("gs_match", "Date", nullptr));
        label_4->setText(QCoreApplication::translate("gs_match", "Lieu", nullptr));
        label_5->setText(QCoreApplication::translate("gs_match", "Equipe 2", nullptr));
        btnAjouter->setText(QCoreApplication::translate("gs_match", "Ajouter", nullptr));
        label_11->setText(QCoreApplication::translate("gs_match", "Employer", nullptr));
        label_6->setText(QCoreApplication::translate("gs_match", "Etat", nullptr));
        etats->setItemText(0, QCoreApplication::translate("gs_match", "Started", nullptr));
        etats->setItemText(1, QCoreApplication::translate("gs_match", "Ended", nullptr));
        etats->setItemText(2, QCoreApplication::translate("gs_match", "Didn't Start", nullptr));
        etats->setItemText(3, QCoreApplication::translate("gs_match", "Postponed", nullptr));

        pushButton_4->setText(QCoreApplication::translate("gs_match", "Sponsor", nullptr));
        pushButton_9->setText(QCoreApplication::translate("gs_match", "Billet", nullptr));
        pushButton_10->setText(QCoreApplication::translate("gs_match", "Employer", nullptr));
        pushButton_11->setText(QCoreApplication::translate("gs_match", "Match", nullptr));
        equipepass->setText(QCoreApplication::translate("gs_match", "Equipe", nullptr));
        label_pic2->setText(QString());
        ball->setText(QString());
        btnSupprimer->setText(QCoreApplication::translate("gs_match", "Supprimer", nullptr));
        recherche->setText(QCoreApplication::translate("gs_match", "Recherche", nullptr));
        btnModifier->setText(QCoreApplication::translate("gs_match", "Modifier", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("gs_match", "Match", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("gs_match", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("gs_match", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("gs_match", "Lieu", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("gs_match", "Etat", nullptr));
        label_8->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class gs_match: public Ui_gs_match {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GS_MATCH_H
