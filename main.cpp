#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connetion.h"  // Vérifie le bon nom de ton fichier et classe
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connetion c;  // Vérifie que la classe est bien "Connection" et non "Connetion"

    bool test = c.createconnect();
    MainWindow w;
    if (test) {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("Database Connection"),
                                 QObject::tr("Connection successful.\nClick OK to continue."),
                                 QMessageBox::Ok);
    } else {
        QMessageBox::critical(nullptr, QObject::tr("Database Connection Failed"),
                              QObject::tr("Connection failed.\nClick OK to exit."),
                              QMessageBox::Ok);
        return -1;  // Quitter l'application si la connexion échoue
    }

    // Messages de test (facultatifs, mais maintenant exécutables)
    qDebug() << "Ceci est un message de débogage affiché dans la console.";
    qWarning() << "Ceci est un message d'avertissement.";
    qCritical() << "Ceci est un message d'erreur.";

    return a.exec();  // Exécuter l'application Qt
}
