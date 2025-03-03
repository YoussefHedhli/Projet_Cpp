#include "connetion.h"

Connetion::Connetion()
{

}

bool Connetion::createconnect()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Remontada");//inserer le nom de la source de données
    db.setUserName("projet");//inserer nom de l'utilisateur
    db.setPassword("remontada");//inserer mot de passe de cet utilisateur

    if (db.open())
        test=true;





    return  test;
}
