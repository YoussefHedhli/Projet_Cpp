#include <QApplication>
#include <QMessageBox>
#include "sponsor.h"
#include "mainwindow.h"
#include "connection.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Connection c;
    if (!c.createconnect()) {
        QMessageBox::critical(nullptr, QObject::tr("Database connection error"),
                              QObject::tr("Connection failed.\nClick Cancel to exit."),
                              QMessageBox::Cancel);
        return 0;
    }

    // Affichage de la fenêtre sponsor
    //sponsor *spon = new sponsor();
    //spon->show(); // show() au lieu de exec() pour éviter de bloquer l'application

    // Affichage de la fenêtre principale en parallèle
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();

    return a.exec();
}
