/********************************************************************************
** Form generated from reading UI file 'fennetre1.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENNETRE1_H
#define UI_FENNETRE1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fennetre1
{
public:
    QPushButton *pushButton_showEmployes;
    QPushButton *pushButton_recherche;
    QFrame *frame;
    QPushButton *pushButton_8;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QLabel *label_pic2_3;
    QPushButton *pushButton_PDF;
    QLabel *label_pic;
    QFrame *formulere;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLineEdit *lineEdit_nom_3;
    QLineEdit *lineEdit_prenom_3;
    QLineEdit *lineEdit_role_3;
    QPushButton *pushButton_AJemp_3;
    QLabel *label_27;
    QLabel *label_28;
    QLineEdit *lineEdit_email_3;
    QLineEdit *lineEdit_motpasse_3;
    QLabel *label_29;
    QDateEdit *dateEdit_3;
    QLineEdit *lineEdit_matricule_3;
    QLabel *label_30;
    QPushButton *pushButton_suprimer;
    QTableWidget *tableWidget;
    QLineEdit *lineEdit_matricule_id;
    QPushButton *pushButton_modifier;
    QFrame *Mailing;
    QPushButton *pushButton_mailing;
    QTextEdit *textEdit_5;
    QLabel *label_31;
    QLineEdit *lineEdit_gmail;
    QPushButton *pushButton_selectFile;
    QLabel *label_selectedFile;
    QLabel *label_33;
    QComboBox *comboBox;
    QFrame *Mailing_4;
    QLabel *label_32;
    QPushButton *btnShowChart_3;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *chartContainer_3;

    void setupUi(QDialog *fennetre1)
    {
        if (fennetre1->objectName().isEmpty())
            fennetre1->setObjectName("fennetre1");
        fennetre1->resize(897, 557);
        pushButton_showEmployes = new QPushButton(fennetre1);
        pushButton_showEmployes->setObjectName("pushButton_showEmployes");
        pushButton_showEmployes->setGeometry(QRect(580, 100, 61, 29));
        pushButton_showEmployes->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_recherche = new QPushButton(fennetre1);
        pushButton_recherche->setObjectName("pushButton_recherche");
        pushButton_recherche->setGeometry(QRect(230, 100, 91, 29));
        pushButton_recherche->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        frame = new QFrame(fennetre1);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(70, 30, 761, 61));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_8 = new QPushButton(frame);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(610, 10, 111, 41));
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
"}\n"
"\n"
""));
        pushButton_19 = new QPushButton(frame);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setGeometry(QRect(490, 10, 111, 41));
        pushButton_19->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_20 = new QPushButton(frame);
        pushButton_20->setObjectName("pushButton_20");
        pushButton_20->setGeometry(QRect(370, 10, 111, 41));
        pushButton_20->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_21 = new QPushButton(frame);
        pushButton_21->setObjectName("pushButton_21");
        pushButton_21->setGeometry(QRect(250, 10, 111, 41));
        pushButton_21->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        pushButton_22 = new QPushButton(frame);
        pushButton_22->setObjectName("pushButton_22");
        pushButton_22->setGeometry(QRect(130, 10, 111, 41));
        pushButton_22->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_pic2_3 = new QLabel(frame);
        label_pic2_3->setObjectName("label_pic2_3");
        label_pic2_3->setGeometry(QRect(0, -10, 91, 81));
        pushButton_PDF = new QPushButton(fennetre1);
        pushButton_PDF->setObjectName("pushButton_PDF");
        pushButton_PDF->setGeometry(QRect(510, 100, 61, 29));
        pushButton_PDF->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_pic = new QLabel(fennetre1);
        label_pic->setObjectName("label_pic");
        label_pic->setGeometry(QRect(0, 0, 951, 631));
        formulere = new QFrame(fennetre1);
        formulere->setObjectName("formulere");
        formulere->setGeometry(QRect(70, 250, 261, 291));
        formulere->setFrameShape(QFrame::Shape::StyledPanel);
        formulere->setFrameShadow(QFrame::Shadow::Raised);
        label_23 = new QLabel(formulere);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(20, 60, 41, 21));
        label_24 = new QLabel(formulere);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(20, 125, 61, 21));
        label_25 = new QLabel(formulere);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(20, 185, 41, 21));
        label_26 = new QLabel(formulere);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(20, 91, 51, 21));
        lineEdit_nom_3 = new QLineEdit(formulere);
        lineEdit_nom_3->setObjectName("lineEdit_nom_3");
        lineEdit_nom_3->setGeometry(QRect(100, 60, 141, 21));
        lineEdit_prenom_3 = new QLineEdit(formulere);
        lineEdit_prenom_3->setObjectName("lineEdit_prenom_3");
        lineEdit_prenom_3->setGeometry(QRect(100, 91, 141, 21));
        lineEdit_role_3 = new QLineEdit(formulere);
        lineEdit_role_3->setObjectName("lineEdit_role_3");
        lineEdit_role_3->setGeometry(QRect(100, 185, 141, 21));
        pushButton_AJemp_3 = new QPushButton(formulere);
        pushButton_AJemp_3->setObjectName("pushButton_AJemp_3");
        pushButton_AJemp_3->setGeometry(QRect(60, 250, 151, 31));
        pushButton_AJemp_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        label_27 = new QLabel(formulere);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(100, 0, 81, 20));
        label_28 = new QLabel(formulere);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(20, 155, 61, 21));
        lineEdit_email_3 = new QLineEdit(formulere);
        lineEdit_email_3->setObjectName("lineEdit_email_3");
        lineEdit_email_3->setGeometry(QRect(100, 155, 141, 21));
        lineEdit_motpasse_3 = new QLineEdit(formulere);
        lineEdit_motpasse_3->setObjectName("lineEdit_motpasse_3");
        lineEdit_motpasse_3->setGeometry(QRect(100, 215, 141, 21));
        label_29 = new QLabel(formulere);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(20, 215, 71, 21));
        dateEdit_3 = new QDateEdit(formulere);
        dateEdit_3->setObjectName("dateEdit_3");
        dateEdit_3->setGeometry(QRect(99, 119, 141, 31));
        lineEdit_matricule_3 = new QLineEdit(formulere);
        lineEdit_matricule_3->setObjectName("lineEdit_matricule_3");
        lineEdit_matricule_3->setGeometry(QRect(100, 30, 141, 21));
        label_30 = new QLabel(formulere);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(20, 30, 71, 21));
        pushButton_suprimer = new QPushButton(fennetre1);
        pushButton_suprimer->setObjectName("pushButton_suprimer");
        pushButton_suprimer->setGeometry(QRect(740, 100, 91, 29));
        pushButton_suprimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        tableWidget = new QTableWidget(fennetre1);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
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
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(70, 140, 760, 101));
        tableWidget->setMaximumSize(QSize(763, 16777215));
        lineEdit_matricule_id = new QLineEdit(fennetre1);
        lineEdit_matricule_id->setObjectName("lineEdit_matricule_id");
        lineEdit_matricule_id->setGeometry(QRect(70, 100, 151, 28));
        pushButton_modifier = new QPushButton(fennetre1);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(650, 100, 83, 29));
        pushButton_modifier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Mailing = new QFrame(fennetre1);
        Mailing->setObjectName("Mailing");
        Mailing->setGeometry(QRect(350, 250, 181, 291));
        Mailing->setFrameShape(QFrame::Shape::StyledPanel);
        Mailing->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_mailing = new QPushButton(Mailing);
        pushButton_mailing->setObjectName("pushButton_mailing");
        pushButton_mailing->setGeometry(QRect(20, 250, 141, 31));
        pushButton_mailing->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        textEdit_5 = new QTextEdit(Mailing);
        textEdit_5->setObjectName("textEdit_5");
        textEdit_5->setGeometry(QRect(20, 150, 141, 81));
        label_31 = new QLabel(Mailing);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(60, 0, 81, 20));
        lineEdit_gmail = new QLineEdit(Mailing);
        lineEdit_gmail->setObjectName("lineEdit_gmail");
        lineEdit_gmail->setGeometry(QRect(20, 40, 141, 31));
        pushButton_selectFile = new QPushButton(Mailing);
        pushButton_selectFile->setObjectName("pushButton_selectFile");
        pushButton_selectFile->setGeometry(QRect(20, 80, 141, 29));
        pushButton_selectFile->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #808080;   /* Grey border */\n"
"    border-radius: 10px;         /* Round the corners */\n"
"    padding: 0 8px;              /* Padding inside the button */\n"
"    background: #808080;         /* Grey background */\n"
"    color: white;                /* White text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #505050;   /* Darker grey on hover */\n"
"}"));
        label_selectedFile = new QLabel(Mailing);
        label_selectedFile->setObjectName("label_selectedFile");
        label_selectedFile->setGeometry(QRect(110, 120, 63, 20));
        label_selectedFile->setStyleSheet(QString::fromUtf8(""));
        label_33 = new QLabel(Mailing);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(20, 120, 91, 20));
        comboBox = new QComboBox(fennetre1);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(330, 100, 171, 28));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #808080;   /* Grey border */\n"
"    border-radius: 10px;         /* Round the corners */\n"
"    padding: 0 8px;              /* Padding inside the combo box */\n"
"    background: #808080;         /* Grey background */\n"
"    color: white;                /* White text color */\n"
"}\n"
"\n"
"/* Dropdown arrow */\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    background: transparent;\n"
"}\n"
"\n"
"/* The dropdown list */\n"
"QComboBox QAbstractItemView {\n"
"    border: 2px solid #808080;\n"
"    background: white;\n"
"    selection-background-color: #505050;  /* Darker grey on selection */\n"
"    color: black;\n"
"}\n"
"\n"
"/* Hover effect */\n"
"QComboBox:hover {\n"
"    background-color: #505050;   /* Darker grey on hover */\n"
"}\n"
""));
        Mailing_4 = new QFrame(fennetre1);
        Mailing_4->setObjectName("Mailing_4");
        Mailing_4->setGeometry(QRect(550, 250, 281, 291));
        Mailing_4->setFrameShape(QFrame::Shape::StyledPanel);
        Mailing_4->setFrameShadow(QFrame::Shadow::Raised);
        label_32 = new QLabel(Mailing_4);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(100, 0, 81, 20));
        btnShowChart_3 = new QPushButton(Mailing_4);
        btnShowChart_3->setObjectName("btnShowChart_3");
        btnShowChart_3->setGeometry(QRect(10, 250, 261, 29));
        btnShowChart_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #808080;   /* Grey border */\n"
"    border-radius: 10px;         /* Round the corners */\n"
"    padding: 0 8px;              /* Padding inside the button */\n"
"    background: #808080;         /* Grey background */\n"
"    color: white;                /* White text color */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #505050;   /* Darker grey on hover */\n"
"}"));
        verticalLayoutWidget_3 = new QWidget(Mailing_4);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(10, 60, 261, 171));
        chartContainer_3 = new QVBoxLayout(verticalLayoutWidget_3);
        chartContainer_3->setObjectName("chartContainer_3");
        chartContainer_3->setContentsMargins(0, 0, 0, 0);
        label_pic->raise();
        pushButton_showEmployes->raise();
        pushButton_recherche->raise();
        frame->raise();
        pushButton_PDF->raise();
        formulere->raise();
        pushButton_suprimer->raise();
        tableWidget->raise();
        lineEdit_matricule_id->raise();
        pushButton_modifier->raise();
        Mailing->raise();
        comboBox->raise();
        Mailing_4->raise();

        retranslateUi(fennetre1);

        QMetaObject::connectSlotsByName(fennetre1);
    } // setupUi

    void retranslateUi(QDialog *fennetre1)
    {
        fennetre1->setWindowTitle(QCoreApplication::translate("fennetre1", "Dialog", nullptr));
        pushButton_showEmployes->setText(QCoreApplication::translate("fennetre1", "show", nullptr));
        pushButton_recherche->setText(QCoreApplication::translate("fennetre1", "Recherche", nullptr));
        pushButton_8->setText(QCoreApplication::translate("fennetre1", "Sponsor", nullptr));
        pushButton_19->setText(QCoreApplication::translate("fennetre1", "Billet", nullptr));
        pushButton_20->setText(QCoreApplication::translate("fennetre1", "Employer", nullptr));
        pushButton_21->setText(QCoreApplication::translate("fennetre1", "Match", nullptr));
        pushButton_22->setText(QCoreApplication::translate("fennetre1", "Equipe", nullptr));
        label_pic2_3->setText(QString());
        pushButton_PDF->setText(QCoreApplication::translate("fennetre1", "PDF", nullptr));
        label_pic->setText(QString());
        label_23->setText(QCoreApplication::translate("fennetre1", "Nom", nullptr));
        label_24->setText(QCoreApplication::translate("fennetre1", "Date ", nullptr));
        label_25->setText(QCoreApplication::translate("fennetre1", "Role", nullptr));
        label_26->setText(QCoreApplication::translate("fennetre1", "Prenom", nullptr));
        pushButton_AJemp_3->setText(QCoreApplication::translate("fennetre1", "Ajouter", nullptr));
        label_27->setText(QCoreApplication::translate("fennetre1", "Employer", nullptr));
        label_28->setText(QCoreApplication::translate("fennetre1", "Email", nullptr));
        label_29->setText(QCoreApplication::translate("fennetre1", "Mot passe", nullptr));
        label_30->setText(QCoreApplication::translate("fennetre1", "Matricule", nullptr));
        pushButton_suprimer->setText(QCoreApplication::translate("fennetre1", "Supprimer", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("fennetre1", "Matricule", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("fennetre1", "nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("fennetre1", "Prenom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("fennetre1", "date naissance", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("fennetre1", "Adresse mail", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("fennetre1", "Role", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("fennetre1", "mot de passe", nullptr));
        pushButton_modifier->setText(QCoreApplication::translate("fennetre1", "Modifier", nullptr));
        pushButton_mailing->setText(QCoreApplication::translate("fennetre1", "Envoyer", nullptr));
        label_31->setText(QCoreApplication::translate("fennetre1", "Mailing", nullptr));
        pushButton_selectFile->setText(QCoreApplication::translate("fennetre1", "Piece Joint", nullptr));
        label_selectedFile->setText(QString());
        label_33->setText(QCoreApplication::translate("fennetre1", "Nom Fichier :", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("fennetre1", "Nom (A \342\206\222 Z)", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("fennetre1", "Nom (Z \342\206\222 A)", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("fennetre1", "Pr\303\251nom (A \342\206\222 Z)", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("fennetre1", "Pr\303\251nom (Z \342\206\222 A)", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("fennetre1", "Date (Ancien \342\206\222 R\303\251cent)", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("fennetre1", "Date (R\303\251cent \342\206\222 Ancien)", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("fennetre1", "Matricule (Petit \342\206\222 Grand)", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("fennetre1", "Matricule (Grand \342\206\222 Petit)", nullptr));

        label_32->setText(QCoreApplication::translate("fennetre1", "Statistique", nullptr));
        btnShowChart_3->setText(QCoreApplication::translate("fennetre1", "chart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fennetre1: public Ui_fennetre1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENNETRE1_H
