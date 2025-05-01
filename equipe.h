#ifndef EQUIPE_H
#define EQUIPE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QPdfWriter>
#include <QPainter>
#include <QTableWidget>
#include <QTableView>
#include <QChartView>
#include <QPieSeries>
#include <QPieSlice>
#include <QLabel>
#include <QFrame>
#include <QObject>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
class Equipe {
private:
    int idEquipe;
    QString nom;
    QString pays;
    QString tactique;
     static QMap<QString, QString> tactiquesCache;
public:
    // Constructeurs
    Equipe();
    Equipe(int idEquipe, const QString& nom, const QString& pays, const QString& tactique);

    // Getters
    int getIdEquipe() const;
    QString getNom() const;
    QString getPays() const;
    QString gettactique() const;
    // Setters
    void setIdEquipe(int idEquipe);
    void setNom(const QString& nom);
    void setPays(const QString& pays);
    void settactique(const QString& tactique);
    // Méthodess
    bool ajouter();                // Ajouter une équipe
    QSqlQueryModel* afficher();    // Afficher toutes les équipes
    bool modifier(int id);         // Modifier une équipe
    bool supprimer(int id);        // Supprimer une équipe
    QSqlQueryModel* rechercher(const QString& keyword);  // Rechercher une équipe
    QSqlQueryModel* trierParId(bool asc);  // Trier par ID
    QSqlQueryModel* triParAlphabet(bool asc); // Trier par nom
    QString getTactique() const;
    static void exporterPDF(QTableView *tableView);
    static QSqlQueryModel* rechercherEquipe(const QString& recherche);
     static void afficherStatistiquesPaysGraph(QFrame* stat);
     void placerJoueur(QWidget *joueur, int x, int y);
     void afficherTactiqueGraphique(const QString &tactique, QWidget *label, QList<QLabel*> joueurs);
     QList<QList<QVariant>> calculerEtatDeForme();
     double calculerFormeMoyenne(const QList<QList<QVariant>>& resultats);
};
//end
#endif // EQUIPE_H
