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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_login;
    QLineEdit *lineEdit_email;
    QLineEdit *lineEdit_mdp;
    QLabel *label_pic;
    QFrame *frame;
    QPushButton *pushButton_mdp_oublie;
    QLabel *ball;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(888, 567);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton_login = new QPushButton(centralwidget);
        pushButton_login->setObjectName("pushButton_login");
        pushButton_login->setGeometry(QRect(250, 350, 381, 41));
        pushButton_login->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #C0C0C0;\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"    font-weight: bold;\n"
"    color: black;\n"
"    font-size: 18px;  /* Change the font size here */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A9A9A9;\n"
"}\n"
"\n"
"QPushButton#registerButton {\n"
"    background-color: rgba(192, 192, 192, 0.5);\n"
"    color: black;\n"
"    font-size: 18px;  /* You can set a different font size for this specific button */\n"
"}\n"
""));
        lineEdit_email = new QLineEdit(centralwidget);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setGeometry(QRect(250, 170, 381, 41));
        lineEdit_email->setStyleSheet(QString::fromUtf8("    QLineEdit {\n"
"        background-color: #2D2D2D;\n"
"        border-radius: 20px;\n"
"        padding: 5px;\n"
"        color: white;\n"
"        border: 1px solid #555;\n"
"    }\n"
""));
        lineEdit_mdp = new QLineEdit(centralwidget);
        lineEdit_mdp->setObjectName("lineEdit_mdp");
        lineEdit_mdp->setGeometry(QRect(250, 240, 381, 41));
        lineEdit_mdp->setStyleSheet(QString::fromUtf8("    QLineEdit {\n"
"        background-color: #2D2D2D;\n"
"        border-radius: 20px;\n"
"        padding: 5px;\n"
"        color: white;\n"
"        border: 1px solid #555;\n"
"    }\n"
"QLineEdit::placeholder {\n"
"    color: #aaa;\n"
"    font-style: italic;\n"
"    font-size: 14px;\n"
"}\n"
""));
        label_pic = new QLabel(centralwidget);
        label_pic->setObjectName("label_pic");
        label_pic->setGeometry(QRect(-8, 0, 931, 541));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(220, 60, 441, 371));
        frame->setStyleSheet(QString::fromUtf8("    QFrame {\n"
"        background-color: rgba(255, 255, 255, 0.8); /* Semi-transparent background */\n"
"        border-radius: 40px; /* Adjust for more or less roundness */\n"
"        padding: 10px;\n"
"    }"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_mdp_oublie = new QPushButton(frame);
        pushButton_mdp_oublie->setObjectName("pushButton_mdp_oublie");
        pushButton_mdp_oublie->setGeometry(QRect(130, 240, 191, 31));
        pushButton_mdp_oublie->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: none;\n"
"    background: transparent;\n"
"    color: #004b6b;  /* Brighter Prussian Blue */\n"
"    font-size: 12pt;\n"
"    font-weight: 300;  /* Thinner font */\n"
"    font-family: \"Arial\", sans-serif;\n"
"    transition: color 0.3s ease-in-out;  /* Smooth transition effect */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    color: #001524;  /* Much darker Prussian Blue */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    color: #000c17;  /* Almost black when clicked */\n"
"}\n"
"\n"
""));
        ball = new QLabel(centralwidget);
        ball->setObjectName("ball");
        ball->setGeometry(QRect(390, 30, 121, 111));
        MainWindow->setCentralWidget(centralwidget);
        label_pic->raise();
        frame->raise();
        pushButton_login->raise();
        lineEdit_email->raise();
        lineEdit_mdp->raise();
        ball->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 888, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_login->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        lineEdit_email->setText(QString());
#if QT_CONFIG(whatsthis)
        lineEdit_mdp->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>222</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        lineEdit_mdp->setText(QString());
        label_pic->setText(QString());
        pushButton_mdp_oublie->setText(QCoreApplication::translate("MainWindow", "Mot de passe oublie", nullptr));
        ball->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
