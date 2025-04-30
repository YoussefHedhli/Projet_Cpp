/********************************************************************************
** Form generated from reading UI file 'fennetre2.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENNETRE2_H
#define UI_FENNETRE2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_fennetre2
{
public:
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_sauvgrd;
    QFrame *frame;
    QLabel *label_login_img;
    QLineEdit *lineEdit_2;
    QLabel *label_picc;

    void setupUi(QDialog *fennetre2)
    {
        if (fennetre2->objectName().isEmpty())
            fennetre2->setObjectName("fennetre2");
        fennetre2->resize(888, 565);
        lineEdit_3 = new QLineEdit(fennetre2);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(250, 190, 381, 41));
        lineEdit_3->setStyleSheet(QString::fromUtf8("    QLineEdit {\n"
"        background-color: #2D2D2D;\n"
"        border-radius: 20px;\n"
"        padding: 5px;\n"
"        color: white;\n"
"        border: 1px solid #555;\n"
"    }\n"
""));
        pushButton_sauvgrd = new QPushButton(fennetre2);
        pushButton_sauvgrd->setObjectName("pushButton_sauvgrd");
        pushButton_sauvgrd->setGeometry(QRect(250, 370, 381, 41));
        pushButton_sauvgrd->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        frame = new QFrame(fennetre2);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(220, 80, 441, 371));
        frame->setStyleSheet(QString::fromUtf8("    QFrame {\n"
"        background-color: rgba(255, 255, 255, 0.8); /* Semi-transparent background */\n"
"        border-radius: 40px; /* Adjust for more or less roundness */\n"
"        padding: 10px;\n"
"    }"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label_login_img = new QLabel(frame);
        label_login_img->setObjectName("label_login_img");
        label_login_img->setGeometry(QRect(160, -30, 121, 111));
        lineEdit_2 = new QLineEdit(fennetre2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(250, 260, 381, 41));
        lineEdit_2->setStyleSheet(QString::fromUtf8("    QLineEdit {\n"
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
        label_picc = new QLabel(fennetre2);
        label_picc->setObjectName("label_picc");
        label_picc->setGeometry(QRect(-10, 20, 931, 541));
        label_picc->raise();
        frame->raise();
        lineEdit_3->raise();
        pushButton_sauvgrd->raise();
        lineEdit_2->raise();

        retranslateUi(fennetre2);

        QMetaObject::connectSlotsByName(fennetre2);
    } // setupUi

    void retranslateUi(QDialog *fennetre2)
    {
        fennetre2->setWindowTitle(QCoreApplication::translate("fennetre2", "Dialog", nullptr));
        lineEdit_3->setText(QString());
        pushButton_sauvgrd->setText(QCoreApplication::translate("fennetre2", "Sauvegarder", nullptr));
        label_login_img->setText(QString());
#if QT_CONFIG(whatsthis)
        lineEdit_2->setWhatsThis(QCoreApplication::translate("fennetre2", "<html><head/><body><p>222</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        lineEdit_2->setText(QString());
        label_picc->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class fennetre2: public Ui_fennetre2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENNETRE2_H
