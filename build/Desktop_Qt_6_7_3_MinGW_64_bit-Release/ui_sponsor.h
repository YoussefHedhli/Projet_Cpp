/********************************************************************************
** Form generated from reading UI file 'sponsor.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPONSOR_H
#define UI_SPONSOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_sponsor
{
public:
    QLabel *label_pic;
    QFrame *formulere;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_nom_org;
    QLineEdit *lineEdit_produit;
    QLineEdit *lineEdit_contribution;
    QPushButton *ajouter;
    QLabel *label_11;
    QPushButton *modifier;
    QPushButton *supprimer;
    QFrame *Mailing;
    QLabel *label_10;
    QPushButton *btnClassement;
    QTableWidget *tableClassement;
    QPushButton *annuler;
    QFrame *frame;
    QPushButton *pushButton_4;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QLabel *ball;
    QPushButton *recherche;
    QPushButton *tri;
    QLineEdit *lineEditrecherche;
    QTableWidget *tableWidget;
    QPushButton *pdf;
    QPushButton *statistique;
    QLabel *labelImageSponsor;
    QPushButton *btnLoadImage;
    QPushButton *btnRemoveImage;
    QPushButton *tri_des;

    void setupUi(QDialog *sponsor)
    {
        if (sponsor->objectName().isEmpty())
            sponsor->setObjectName("sponsor");
        sponsor->resize(1038, 720);
        label_pic = new QLabel(sponsor);
        label_pic->setObjectName("label_pic");
        label_pic->setEnabled(true);
        label_pic->setGeometry(QRect(-30, 0, 1071, 721));
        label_pic->setPixmap(QPixmap(QString::fromUtf8("../../../../Downloads/bg0777.jpg")));
        formulere = new QFrame(sponsor);
        formulere->setObjectName("formulere");
        formulere->setGeometry(QRect(20, 340, 271, 341));
        formulere->setStyleSheet(QString::fromUtf8("background-color: rgb(65, 65, 65);"));
        formulere->setFrameShape(QFrame::Shape::NoFrame);
        label = new QLabel(formulere);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 50, 41, 21));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(formulere);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 130, 141, 21));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(formulere);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 170, 161, 21));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(formulere);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 90, 171, 31));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lineEdit_id = new QLineEdit(formulere);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(180, 50, 81, 28));
        lineEdit_nom_org = new QLineEdit(formulere);
        lineEdit_nom_org->setObjectName("lineEdit_nom_org");
        lineEdit_nom_org->setGeometry(QRect(180, 90, 81, 28));
        lineEdit_produit = new QLineEdit(formulere);
        lineEdit_produit->setObjectName("lineEdit_produit");
        lineEdit_produit->setGeometry(QRect(180, 130, 81, 28));
        lineEdit_contribution = new QLineEdit(formulere);
        lineEdit_contribution->setObjectName("lineEdit_contribution");
        lineEdit_contribution->setGeometry(QRect(180, 170, 81, 28));
        ajouter = new QPushButton(formulere);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(30, 220, 151, 31));
        ajouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_11->setGeometry(QRect(50, 0, 181, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Nirmala UI")});
        font1.setPointSize(20);
        font1.setBold(true);
        label_11->setFont(font1);
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        modifier = new QPushButton(formulere);
        modifier->setObjectName("modifier");
        modifier->setGeometry(QRect(30, 260, 151, 31));
        modifier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        supprimer = new QPushButton(formulere);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(30, 300, 151, 29));
        supprimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Mailing = new QFrame(sponsor);
        Mailing->setObjectName("Mailing");
        Mailing->setEnabled(true);
        Mailing->setGeometry(QRect(320, 340, 421, 341));
        Mailing->setStyleSheet(QString::fromUtf8("background-color: rgb(65, 65, 65);\n"
""));
        Mailing->setFrameShape(QFrame::Shape::NoFrame);
        label_10 = new QLabel(Mailing);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 10, 201, 31));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        btnClassement = new QPushButton(Mailing);
        btnClassement->setObjectName("btnClassement");
        btnClassement->setGeometry(QRect(120, 80, 131, 41));
        tableClassement = new QTableWidget(Mailing);
        if (tableClassement->columnCount() < 5)
            tableClassement->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableClassement->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableClassement->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableClassement->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableClassement->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableClassement->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableClassement->setObjectName("tableClassement");
        tableClassement->setGeometry(QRect(40, 140, 361, 192));
        annuler = new QPushButton(sponsor);
        annuler->setObjectName("annuler");
        annuler->setGeometry(QRect(660, 130, 71, 29));
        annuler->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        frame = new QFrame(sponsor);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(80, 60, 761, 61));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(65, 65, 65);"));
        frame->setFrameShape(QFrame::Shape::NoFrame);
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
        ball = new QLabel(frame);
        ball->setObjectName("ball");
        ball->setGeometry(QRect(0, -10, 91, 81));
        recherche = new QPushButton(sponsor);
        recherche->setObjectName("recherche");
        recherche->setGeometry(QRect(362, 130, 91, 29));
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
        tri = new QPushButton(sponsor);
        tri->setObjectName("tri");
        tri->setGeometry(QRect(470, 130, 83, 29));
        tri->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lineEditrecherche = new QLineEdit(sponsor);
        lineEditrecherche->setObjectName("lineEditrecherche");
        lineEditrecherche->setGeometry(QRect(80, 130, 271, 28));
        lineEditrecherche->setStyleSheet(QString::fromUtf8("background-color: rgb(65, 65, 65);\n"
""));
        tableWidget = new QTableWidget(sponsor);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(false);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font2);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QFont font3;
        font3.setPointSize(9);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font3);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(70, 180, 521, 141));
        tableWidget->setMaximumSize(QSize(763, 16777215));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(65, 65, 65);"));
        pdf = new QPushButton(sponsor);
        pdf->setObjectName("pdf");
        pdf->setGeometry(QRect(750, 130, 71, 29));
        pdf->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        statistique = new QPushButton(sponsor);
        statistique->setObjectName("statistique");
        statistique->setGeometry(QRect(850, 130, 91, 29));
        statistique->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        labelImageSponsor = new QLabel(sponsor);
        labelImageSponsor->setObjectName("labelImageSponsor");
        labelImageSponsor->setGeometry(QRect(760, 340, 241, 161));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("MS Sans Serif")});
        font4.setPointSize(15);
        font4.setBold(true);
        font4.setItalic(true);
        labelImageSponsor->setFont(font4);
        labelImageSponsor->setAcceptDrops(true);
        labelImageSponsor->setAlignment(Qt::AlignmentFlag::AlignCenter);
        btnLoadImage = new QPushButton(sponsor);
        btnLoadImage->setObjectName("btnLoadImage");
        btnLoadImage->setGeometry(QRect(780, 530, 101, 23));
        btnRemoveImage = new QPushButton(sponsor);
        btnRemoveImage->setObjectName("btnRemoveImage");
        btnRemoveImage->setGeometry(QRect(764, 582, 121, 31));
        tri_des = new QPushButton(sponsor);
        tri_des->setObjectName("tri_des");
        tri_des->setGeometry(QRect(560, 130, 83, 29));
        tri_des->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        retranslateUi(sponsor);

        QMetaObject::connectSlotsByName(sponsor);
    } // setupUi

    void retranslateUi(QDialog *sponsor)
    {
        sponsor->setWindowTitle(QCoreApplication::translate("sponsor", "Dialog", nullptr));
        label_pic->setText(QString());
        label->setText(QCoreApplication::translate("sponsor", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("sponsor", "Produit", nullptr));
        label_3->setText(QCoreApplication::translate("sponsor", "Contribution", nullptr));
        label_4->setText(QCoreApplication::translate("sponsor", "Nom Sponsor", nullptr));
        ajouter->setText(QCoreApplication::translate("sponsor", "Ajouter", nullptr));
        label_11->setText(QCoreApplication::translate("sponsor", "Sponsor", nullptr));
        modifier->setText(QCoreApplication::translate("sponsor", "Modifier", nullptr));
        supprimer->setText(QCoreApplication::translate("sponsor", "Supprimer", nullptr));
        label_10->setText(QCoreApplication::translate("sponsor", "Meilleur sponsor ", nullptr));
        btnClassement->setText(QCoreApplication::translate("sponsor", "Afficher Classement", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableClassement->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("sponsor", "Sponsor", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableClassement->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("sponsor", "equipe with the most sponsor", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableClassement->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("sponsor", "rang", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableClassement->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("sponsor", "Contribution", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableClassement->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("sponsor", "Cat\303\251gorie", nullptr));
        annuler->setText(QCoreApplication::translate("sponsor", "annuler", nullptr));
        pushButton_4->setText(QCoreApplication::translate("sponsor", "Sponsor", nullptr));
        pushButton_9->setText(QCoreApplication::translate("sponsor", "Billet", nullptr));
        pushButton_10->setText(QCoreApplication::translate("sponsor", "Employer", nullptr));
        pushButton_11->setText(QCoreApplication::translate("sponsor", "Match", nullptr));
        pushButton_12->setText(QCoreApplication::translate("sponsor", "Equipe", nullptr));
        ball->setText(QString());
        recherche->setText(QCoreApplication::translate("sponsor", "Recherche", nullptr));
        tri->setText(QCoreApplication::translate("sponsor", "Tri par ID", nullptr));
        lineEditrecherche->setText(QString());
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("sponsor", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("sponsor", "Nom Sponsor", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("sponsor", "Produit ", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("sponsor", "Contribution", nullptr));
        pdf->setText(QCoreApplication::translate("sponsor", "pdf", nullptr));
        statistique->setText(QCoreApplication::translate("sponsor", "statistique", nullptr));
        labelImageSponsor->setText(QCoreApplication::translate("sponsor", "<html><head/><body><p><br/></p><p><br/></p></body></html>", nullptr));
        btnLoadImage->setText(QCoreApplication::translate("sponsor", "Charger image", nullptr));
        btnRemoveImage->setText(QCoreApplication::translate("sponsor", "Supprimer image", nullptr));
        tri_des->setText(QCoreApplication::translate("sponsor", "tri des", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sponsor: public Ui_sponsor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPONSOR_H
