#ifndef BILLET_H
#define BILLET_H

#include <QString>
#include <QDate>
#include <QSqlQuery>

class Billet
{
public:
    Billet();

    void setPrix(int prix);
    int getPrix() const;

    void setType(const QString &type);
    QString getType() const;

    void setDateB(const QDate &date);
    QDate getDateB() const;

    void setQrId(const QString &qrId);
    QString getQrId() const;
    void setIdMatch(int id);

    bool fetchBilletById(int id_b);
    bool ajouterBillet(int id_b);
    bool modifierBillet(int id_b, const QDate &newDateB, const QString &new_qrid);
    bool deleteBillet(int id_b);
    QSqlQuery fetchAllBillets();
    QSqlQuery searchBillets(const QString &searchTerm);


private:
    int prix;
    int idMatch_b; // add this inside the private section
    QString type;
    QDate dateB;
    QString qrId;
};

#endif // BILLET_H
