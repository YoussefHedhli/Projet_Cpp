#ifndef CONNETION_H
#define CONNETION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connetion
{
public:
    Connetion();
    bool createconnect();
};

#endif // CONNECTION_H
