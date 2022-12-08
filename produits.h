#ifndef PRODUITS_H
#define PRODUITS_H
#include <QSqlQueryModel>
#include <QString>
class Produits
{
public:
    Produits();
    Produits(int,QString,QString,float);
    int get_id();
    QString get_nom();
    QString get_etat();
    float get_prix();
    void set_id(int);
    void set_nom(QString);
    void set_etat(QString);
    void set_prix(float);
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    bool genererPDFproduit();
    QSqlQueryModel* trier();
    QSqlQueryModel* trierParId();
    QSqlQueryModel* trierParPrix();
    QSqlQueryModel* afficher();
    QSqlQueryModel* recherche(QString nom,QString prix,QString id);
private:
    int id;
    QString nom,etat;
    float prix;
};

#endif // PRODUITS_H
