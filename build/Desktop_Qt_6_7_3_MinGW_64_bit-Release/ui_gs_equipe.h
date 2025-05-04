/********************************************************************************
** Form generated from reading UI file 'gs_equipe.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GS_EQUIPE_H
#define UI_GS_EQUIPE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_gs_equipe
{
public:
    QWidget *centralwidget;
    QLabel *label_14;
    QPushButton *bmodif;
    QPushButton *employerpass;
    QLabel *ball;
    QLabel *label_8;
    QTabWidget *tabWidget;
    QWidget *tab_4;
    QTableWidget *table;
    QPushButton *up;
    QLabel *lforme;
    QWidget *tab_3;
    QLabel *labelTactique;
    QLabel *label_4;
    QLabel *l6;
    QLabel *l7;
    QLabel *l8;
    QLabel *l9;
    QLabel *l10;
    QLabel *l1;
    QLabel *l2;
    QLabel *l3;
    QLabel *l4;
    QLabel *l5;
    QLabel *l11;
    QLabel *label_tactiqueAI;
    QLabel *tacticsDisplay;
    QLabel *label_5;
    QPushButton *bsupp;
    QPushButton *matchpass;
    QPushButton *billetpass;
    QPushButton *bpdf;
    QPushButton *Rech;
    QPushButton *pushButton_8;
    QFrame *formulere;
    QLabel *label_3;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *idline;
    QLineEdit *nomline;
    QLineEdit *payline;
    QPushButton *labelajout;
    QLabel *label_12;
    QLabel *label_13;
    QFrame *frame_2;
    QLabel *label_7;
    QLabel *label_11;
    QComboBox *comboTactique;
    QLineEdit *linerech;
    QPushButton *sponsorpass;
    QLabel *label_pic;
    QFrame *stat;
    QLabel *label_2;
    QTableView *AFF;
    QComboBox *combotri;
    QLabel *labeltactique;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *gs_equipe)
    {
        if (gs_equipe->objectName().isEmpty())
            gs_equipe->setObjectName("gs_equipe");
        gs_equipe->resize(1301, 651);
        centralwidget = new QWidget(gs_equipe);
        centralwidget->setObjectName("centralwidget");
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(830, 580, 141, 16));
        bmodif = new QPushButton(centralwidget);
        bmodif->setObjectName("bmodif");
        bmodif->setGeometry(QRect(430, 120, 101, 29));
        bmodif->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border:2px solid gray;\n"
"border-radius: 10px;\n"
"padding:0 8px;\n"
"background:gray;\n"
"}"));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::MailMessageNew));
        bmodif->setIcon(icon);
        employerpass = new QPushButton(centralwidget);
        employerpass->setObjectName("employerpass");
        employerpass->setGeometry(QRect(480, 50, 101, 29));
        employerpass->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #003153;   /* Prussian Blue border */\n"
"    border-radius: 10px;         /* Round the corners */\n"
"    padding: 0 8px;              /* Padding inside the button */\n"
"    background: #003153;         /* Prussian Blue background */\n"
"    color: white;                /* White text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #001f33; /* Darker Prussian blue on hover */\n"
"}"));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::SystemSearch));
        employerpass->setIcon(icon1);
        ball = new QLabel(centralwidget);
        ball->setObjectName("ball");
        ball->setGeometry(QRect(60, 10, 131, 91));
        ball->setPixmap(QPixmap(QString::fromUtf8("../../Pictures/A1.png")));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(300, 310, 211, 241));
        label_8->setStyleSheet(QString::fromUtf8(""));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(580, 230, 411, 341));
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        table = new QTableWidget(tab_4);
        if (table->columnCount() < 5)
            table->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        table->setObjectName("table");
        table->setGeometry(QRect(0, 0, 401, 241));
        up = new QPushButton(tab_4);
        up->setObjectName("up");
        up->setGeometry(QRect(270, 270, 111, 29));
        up->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border:2px solid gray;\n"
"border-radius: 10px;\n"
"padding:0 8px;\n"
"background:gray;\n"
"}"));
        lforme = new QLabel(tab_4);
        lforme->setObjectName("lforme");
        lforme->setGeometry(QRect(0, 250, 281, 21));
        tabWidget->addTab(tab_4, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        labelTactique = new QLabel(tab_3);
        labelTactique->setObjectName("labelTactique");
        labelTactique->setGeometry(QRect(10, 290, 221, 21));
        label_4 = new QLabel(tab_3);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(-40, 0, 461, 321));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../Pictures/dimensions-arcs-cercle-terrain-foot.png")));
        l6 = new QLabel(tab_3);
        l6->setObjectName("l6");
        l6->setGeometry(QRect(240, 60, 21, 20));
        l6->setStyleSheet(QString::fromUtf8("background-color: Red;\n"
"border-radius: 10px;\n"
"width: 20px;\n"
"height: 20px;"));
        l7 = new QLabel(tab_3);
        l7->setObjectName("l7");
        l7->setGeometry(QRect(240, 110, 21, 20));
        l7->setStyleSheet(QString::fromUtf8("background-color: Red;\n"
"border-radius: 10px;\n"
"width: 20px;\n"
"height: 20px;"));
        l8 = new QLabel(tab_3);
        l8->setObjectName("l8");
        l8->setGeometry(QRect(240, 160, 21, 20));
        l8->setStyleSheet(QString::fromUtf8("background-color: Red;\n"
"border-radius: 10px;\n"
"width: 20px;\n"
"height: 20px;"));
        l9 = new QLabel(tab_3);
        l9->setObjectName("l9");
        l9->setGeometry(QRect(240, 210, 21, 20));
        l9->setStyleSheet(QString::fromUtf8("background-color: Red;\n"
"border-radius: 10px;\n"
"width: 20px;\n"
"height: 20px;"));
        l10 = new QLabel(tab_3);
        l10->setObjectName("l10");
        l10->setGeometry(QRect(240, 20, 21, 20));
        l10->setStyleSheet(QString::fromUtf8("background-color: Red;\n"
"border-radius: 10px;\n"
"width: 20px;\n"
"height: 20px;"));
        l1 = new QLabel(tab_3);
        l1->setObjectName("l1");
        l1->setGeometry(QRect(320, 10, 21, 20));
        l1->setStyleSheet(QString::fromUtf8("background-color: Red;\n"
"border-radius: 10px;\n"
"width: 20px;\n"
"height: 20px;"));
        l2 = new QLabel(tab_3);
        l2->setObjectName("l2");
        l2->setGeometry(QRect(300, 50, 21, 20));
        l2->setStyleSheet(QString::fromUtf8("background-color: Red;\n"
"border-radius: 10px;\n"
"width: 20px;\n"
"height: 20px;"));
        l3 = new QLabel(tab_3);
        l3->setObjectName("l3");
        l3->setGeometry(QRect(300, 110, 21, 20));
        l3->setStyleSheet(QString::fromUtf8("background-color: Red;\n"
"border-radius: 10px;\n"
"width: 20px;\n"
"height: 20px;"));
        l4 = new QLabel(tab_3);
        l4->setObjectName("l4");
        l4->setGeometry(QRect(300, 160, 21, 20));
        l4->setStyleSheet(QString::fromUtf8("background-color: Red;\n"
"border-radius: 10px;\n"
"width: 20px;\n"
"height: 20px;"));
        l5 = new QLabel(tab_3);
        l5->setObjectName("l5");
        l5->setGeometry(QRect(320, 210, 21, 20));
        l5->setStyleSheet(QString::fromUtf8("background-color: Red;\n"
"border-radius: 10px;\n"
"width: 20px;\n"
"height: 20px;"));
        l11 = new QLabel(tab_3);
        l11->setObjectName("l11");
        l11->setGeometry(QRect(370, 120, 16, 21));
        l11->setStyleSheet(QString::fromUtf8("background-color: Red;\n"
"border-radius: 10px;\n"
"width: 20px;\n"
"height: 20px;"));
        label_tactiqueAI = new QLabel(tab_3);
        label_tactiqueAI->setObjectName("label_tactiqueAI");
        label_tactiqueAI->setGeometry(QRect(20, 270, 351, 51));
        tacticsDisplay = new QLabel(tab_3);
        tacticsDisplay->setObjectName("tacticsDisplay");
        tacticsDisplay->setGeometry(QRect(60, 259, 281, 31));
        tabWidget->addTab(tab_3, QString());
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(70, 30, 871, 71));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #000000;  /* Fond noir */\n"
"    color: #FFFFFF;             /* Texte blanc */\n"
"    border: 1px solid #444444;  /* Bordure gris fonc\303\251 */\n"
"    border-radius: 5px;         /* Coins arrondis */\n"
"    padding: 5px;               /* Espacement interne */\n"
"    font-size: 14px;            /* Taille de la police */\n"
"    text-align: center;         /* Texte centr\303\251 */\n"
"}\n"
""));
        bsupp = new QPushButton(centralwidget);
        bsupp->setObjectName("bsupp");
        bsupp->setGeometry(QRect(580, 120, 101, 29));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(9);
        bsupp->setFont(font);
        bsupp->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        bsupp->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border:2px solid gray;\n"
"border-radius: 10px;\n"
"padding:0 8px;\n"
"background:gray;\n"
"}"));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::EditDelete));
        bsupp->setIcon(icon2);
        bsupp->setAutoRepeat(false);
        matchpass = new QPushButton(centralwidget);
        matchpass->setObjectName("matchpass");
        matchpass->setGeometry(QRect(200, 50, 101, 29));
        matchpass->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #003153;   /* Prussian Blue border */\n"
"    border-radius: 10px;         /* Round the corners */\n"
"    padding: 0 8px;              /* Padding inside the button */\n"
"    background: #003153;         /* Prussian Blue background */\n"
"    color: white;                /* White text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #001f33; /* Darker Prussian blue on hover */\n"
"}"));
        matchpass->setIcon(icon1);
        billetpass = new QPushButton(centralwidget);
        billetpass->setObjectName("billetpass");
        billetpass->setGeometry(QRect(640, 50, 101, 29));
        billetpass->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #003153;   /* Prussian Blue border */\n"
"    border-radius: 10px;         /* Round the corners */\n"
"    padding: 0 8px;              /* Padding inside the button */\n"
"    background: #003153;         /* Prussian Blue background */\n"
"    color: white;                /* White text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #001f33; /* Darker Prussian blue on hover */\n"
"}"));
        billetpass->setIcon(icon1);
        bpdf = new QPushButton(centralwidget);
        bpdf->setObjectName("bpdf");
        bpdf->setGeometry(QRect(720, 120, 141, 29));
        bpdf->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border:2px solid gray;\n"
"border-radius: 10px;\n"
"padding:0 8px;\n"
"background:gray;\n"
"}"));
        QIcon icon3(QIcon::fromTheme(QIcon::ThemeIcon::DocumentPrintPreview));
        bpdf->setIcon(icon3);
        Rech = new QPushButton(centralwidget);
        Rech->setObjectName("Rech");
        Rech->setGeometry(QRect(290, 120, 101, 29));
        Rech->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border:2px solid gray;\n"
"border-radius: 10px;\n"
"padding:0 8px;\n"
"background:gray;\n"
"}"));
        Rech->setIcon(icon1);
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(340, 50, 101, 29));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #003153;   /* Prussian Blue border */\n"
"    border-radius: 10px;         /* Round the corners */\n"
"    padding: 0 8px;              /* Padding inside the button */\n"
"    background: #003153;         /* Prussian Blue background */\n"
"    color: white;                /* White text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #001f33; /* Darker Prussian blue on hover */\n"
"}"));
        pushButton_8->setIcon(icon1);
        formulere = new QFrame(centralwidget);
        formulere->setObjectName("formulere");
        formulere->setGeometry(QRect(70, 350, 181, 251));
        formulere->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    background-color: #1E1E1E;  /* Fond noir */\n"
"    color: white;              /* Texte blanc */\n"
"    border: 2px solid #333333; /* Bordure gris fonc\303\251 */\n"
"    border-radius: 10px;       /* Coins arrondis */\n"
"    font-size: 14px;           /* Taille de la police */\n"
"    font-weight: bold;         /* Texte en gras */\n"
"    padding: 10px;             /* Espacement interne */\n"
"}\n"
""));
        formulere->setFrameShape(QFrame::Shape::NoFrame);
        label_3 = new QLabel(formulere);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 50, 41, 21));
        label_3->setStyleSheet(QString::fromUtf8(""));
        label_9 = new QLabel(formulere);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 130, 61, 21));
        label_9->setStyleSheet(QString::fromUtf8(""));
        label_10 = new QLabel(formulere);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 90, 51, 21));
        label_10->setStyleSheet(QString::fromUtf8(""));
        idline = new QLineEdit(formulere);
        idline->setObjectName("idline");
        idline->setGeometry(QRect(90, 50, 81, 28));
        idline->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #000000;  /* Fond noir */\n"
"    color: #FFFFFF;             /* Texte blanc */\n"
"    border: 1px solid #444444;  /* Bordure gris fonc\303\251 */\n"
"    border-radius: 5px;         /* Coins arrondis */\n"
"    padding: 5px;               /* Espacement interne */\n"
"    font-size: 14px;            /* Taille de la police */\n"
"}"));
        nomline = new QLineEdit(formulere);
        nomline->setObjectName("nomline");
        nomline->setGeometry(QRect(90, 90, 81, 28));
        nomline->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #000000;  /* Fond noir */\n"
"    color: #FFFFFF;             /* Texte blanc */\n"
"    border: 1px solid #444444;  /* Bordure gris fonc\303\251 */\n"
"    border-radius: 5px;         /* Coins arrondis */\n"
"    padding: 5px;               /* Espacement interne */\n"
"    font-size: 14px;            /* Taille de la police */\n"
"}"));
        payline = new QLineEdit(formulere);
        payline->setObjectName("payline");
        payline->setGeometry(QRect(90, 130, 81, 28));
        payline->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #000000;  /* Fond noir */\n"
"    color: #FFFFFF;             /* Texte blanc */\n"
"    border: 1px solid #444444;  /* Bordure gris fonc\303\251 */\n"
"    border-radius: 5px;         /* Coins arrondis */\n"
"    padding: 5px;               /* Espacement interne */\n"
"    font-size: 14px;            /* Taille de la police */\n"
"}"));
        labelajout = new QPushButton(formulere);
        labelajout->setObjectName("labelajout");
        labelajout->setGeometry(QRect(20, 210, 151, 31));
        labelajout->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border:2px solid gray;\n"
"border-radius: 10px;\n"
"padding:0 8px;\n"
"background:gray;\n"
"}"));
        QIcon icon4(QIcon::fromTheme(QIcon::ThemeIcon::ContactNew));
        labelajout->setIcon(icon4);
        label_12 = new QLabel(formulere);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(50, 10, 81, 20));
        label_12->setStyleSheet(QString::fromUtf8(""));
        label_13 = new QLabel(formulere);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(0, 50, 191, 241));
        label_13->setStyleSheet(QString::fromUtf8(""));
        frame_2 = new QFrame(formulere);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(0, 10, 181, 231));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        label_7 = new QLabel(frame_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(30, 0, 91, 16));
        label_11 = new QLabel(formulere);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(20, 170, 61, 21));
        label_11->setStyleSheet(QString::fromUtf8(""));
        comboTactique = new QComboBox(formulere);
        comboTactique->addItem(QString());
        comboTactique->addItem(QString());
        comboTactique->addItem(QString());
        comboTactique->setObjectName("comboTactique");
        comboTactique->setGeometry(QRect(90, 170, 76, 26));
        frame_2->raise();
        label_13->raise();
        label_3->raise();
        label_9->raise();
        label_10->raise();
        idline->raise();
        nomline->raise();
        payline->raise();
        labelajout->raise();
        label_12->raise();
        label_11->raise();
        comboTactique->raise();
        linerech = new QLineEdit(centralwidget);
        linerech->setObjectName("linerech");
        linerech->setGeometry(QRect(10, 120, 271, 28));
        linerech->setStyleSheet(QString::fromUtf8(""));
        sponsorpass = new QPushButton(centralwidget);
        sponsorpass->setObjectName("sponsorpass");
        sponsorpass->setGeometry(QRect(790, 50, 101, 29));
        sponsorpass->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #003153;   /* Prussian Blue border */\n"
"    border-radius: 10px;         /* Round the corners */\n"
"    padding: 0 8px;              /* Padding inside the button */\n"
"    background: #003153;         /* Prussian Blue background */\n"
"    color: white;                /* White text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #001f33; /* Darker Prussian blue on hover */\n"
"}"));
        sponsorpass->setIcon(icon1);
        label_pic = new QLabel(centralwidget);
        label_pic->setObjectName("label_pic");
        label_pic->setGeometry(QRect(-70, -80, 1411, 791));
        label_pic->setPixmap(QPixmap(QString::fromUtf8("../../Pictures/ft2.png")));
        stat = new QFrame(centralwidget);
        stat->setObjectName("stat");
        stat->setGeometry(QRect(260, 320, 311, 271));
        stat->setFrameShape(QFrame::Shape::StyledPanel);
        stat->setFrameShadow(QFrame::Shadow::Raised);
        label_2 = new QLabel(stat);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 0, 91, 16));
        AFF = new QTableView(centralwidget);
        AFF->setObjectName("AFF");
        AFF->setGeometry(QRect(10, 150, 521, 171));
        combotri = new QComboBox(centralwidget);
        combotri->addItem(QString());
        combotri->addItem(QString());
        combotri->addItem(QString());
        combotri->addItem(QString());
        combotri->setObjectName("combotri");
        combotri->setGeometry(QRect(840, 170, 76, 26));
        labeltactique = new QLabel(centralwidget);
        labeltactique->setObjectName("labeltactique");
        labeltactique->setGeometry(QRect(712, 199, 91, 21));
        gs_equipe->setCentralWidget(centralwidget);
        label_pic->raise();
        label_8->raise();
        label_5->raise();
        ball->raise();
        label_14->raise();
        bmodif->raise();
        employerpass->raise();
        tabWidget->raise();
        bsupp->raise();
        matchpass->raise();
        billetpass->raise();
        bpdf->raise();
        Rech->raise();
        pushButton_8->raise();
        formulere->raise();
        linerech->raise();
        sponsorpass->raise();
        stat->raise();
        AFF->raise();
        combotri->raise();
        labeltactique->raise();
        menubar = new QMenuBar(gs_equipe);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1301, 25));
        gs_equipe->setMenuBar(menubar);
        statusbar = new QStatusBar(gs_equipe);
        statusbar->setObjectName("statusbar");
        gs_equipe->setStatusBar(statusbar);

        retranslateUi(gs_equipe);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(gs_equipe);
    } // setupUi

    void retranslateUi(QMainWindow *gs_equipe)
    {
        gs_equipe->setWindowTitle(QCoreApplication::translate("gs_equipe", "gs_equipe", nullptr));
        label_14->setText(QCoreApplication::translate("gs_equipe", "WELCOME!", nullptr));
        bmodif->setText(QCoreApplication::translate("gs_equipe", "Modifier", nullptr));
        employerpass->setText(QCoreApplication::translate("gs_equipe", "Employer", nullptr));
        ball->setText(QString());
        label_8->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = table->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("gs_equipe", "id_equipe", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("gs_equipe", "victoire", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("gs_equipe", "nul", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("gs_equipe", "defaite", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("gs_equipe", "forme", nullptr));
        up->setText(QCoreApplication::translate("gs_equipe", "mettre a jour", nullptr));
        lforme->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("gs_equipe", "etat", nullptr));
        labelTactique->setText(QString());
        label_4->setText(QString());
        l6->setText(QString());
        l7->setText(QString());
        l8->setText(QString());
        l9->setText(QString());
        l10->setText(QString());
        l1->setText(QString());
        l2->setText(QString());
        l3->setText(QString());
        l4->setText(QString());
        l5->setText(QString());
        l11->setText(QString());
        label_tactiqueAI->setText(QString());
        tacticsDisplay->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("gs_equipe", "tactique", nullptr));
        label_5->setText(QString());
        bsupp->setText(QCoreApplication::translate("gs_equipe", "Supprimer", nullptr));
        matchpass->setText(QCoreApplication::translate("gs_equipe", "Match", nullptr));
        billetpass->setText(QCoreApplication::translate("gs_equipe", "Billet", nullptr));
        bpdf->setText(QCoreApplication::translate("gs_equipe", "Exporter en PDF", nullptr));
        Rech->setText(QCoreApplication::translate("gs_equipe", "Recherche", nullptr));
        pushButton_8->setText(QCoreApplication::translate("gs_equipe", "Equipe", nullptr));
#if QT_CONFIG(tooltip)
        formulere->setToolTip(QCoreApplication::translate("gs_equipe", "<html><head/><body><p>QLabel {</p><p>    background-color: #000000;  /* Fond noir */</p><p>    color: white;              /* Texte blanc */</p><p>    border: 1px solid #333333; /* Bordure gris fonc\303\251 */</p><p>    padding: 5px;              /* Espacement interne */</p><p>    font-size: 14px;           /* Taille du texte */</p><p>    font-weight: bold;         /* Texte en gras */</p><p>    text-align: center;        /* Texte centr\303\251 */</p><p>}</p><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_3->setText(QCoreApplication::translate("gs_equipe", "ID", nullptr));
        label_9->setText(QCoreApplication::translate("gs_equipe", "Pays", nullptr));
        label_10->setText(QCoreApplication::translate("gs_equipe", "Nom", nullptr));
        idline->setText(QString());
        nomline->setText(QString());
        payline->setText(QString());
        labelajout->setText(QCoreApplication::translate("gs_equipe", "Ajouter", nullptr));
        label_12->setText(QCoreApplication::translate("gs_equipe", "equipe", nullptr));
        label_13->setText(QString());
        label_7->setText(QString());
        label_11->setText(QCoreApplication::translate("gs_equipe", "tactique", nullptr));
        comboTactique->setItemText(0, QCoreApplication::translate("gs_equipe", "4-4-2", nullptr));
        comboTactique->setItemText(1, QCoreApplication::translate("gs_equipe", "5-4-1", nullptr));
        comboTactique->setItemText(2, QCoreApplication::translate("gs_equipe", "4-3-3", nullptr));

        linerech->setText(QString());
        sponsorpass->setText(QCoreApplication::translate("gs_equipe", "Sponsor", nullptr));
        label_pic->setText(QString());
        label_2->setText(QString());
        combotri->setItemText(0, QCoreApplication::translate("gs_equipe", "Tri par ID (croissant)", nullptr));
        combotri->setItemText(1, QCoreApplication::translate("gs_equipe", "Tri par ID (d\303\251croissant)", nullptr));
        combotri->setItemText(2, QCoreApplication::translate("gs_equipe", "Tri alphab\303\251tique (A-Z)", nullptr));
        combotri->setItemText(3, QCoreApplication::translate("gs_equipe", "Tri alphab\303\251tique (Z-A)", nullptr));

        labeltactique->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class gs_equipe: public Ui_gs_equipe {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GS_EQUIPE_H
