#include "connection.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-bd");
db.setUserName("iyed");//inserer nom de l'utilisateur
db.setPassword("iyediyed");//inserer mot de passe de cet utilisateur

if (db.open())
    test=true;




    return  test;
}
