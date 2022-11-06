#ifndef VOYAGEUR_H
#define VOYAGEUR_H

#include<QString>
#include<QSqlQueryModel>

class Voyageur
{
public:
    Voyageur();
    Voyageur(int Cin,QString Nom, QString Prenom,int NumPass ,int Numero);
    int getCin();
    QString getNom();
    QString getPrenom();
    int getNumPass();
    int getNumero();
    void setCin(int);
    void setNom(QString);
    void setPrenom(QString);
    void setNumPass(int);
    void setNumero(int);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();

   private:
    int Cin,NumPass,Numero;//Cin clé primaire unique et non null
    QString Nom, Prenom;
};
#endif // VOYAGEUR_H
