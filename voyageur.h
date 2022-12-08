#ifndef VOYAGEUR_H
#define VOYAGEUR_H

#include<QString>
#include<QSqlQueryModel>

class Voyageur
{
public:
    Voyageur();
    Voyageur(int Cin,QString Nom, QString Prenom,int NumPass ,int Age);
    int getCin();
    QString getNom();
    QString getPrenom();
    int getNumPass();
    int getAge();
    void setCin(int);
    void setNom(QString);
    void setPrenom(QString);
    void setNumPass(int);
    void setAge(int);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * tri_Cin();
    QSqlQueryModel * tri_Age();
    QSqlQueryModel * rechercher(QString rech);
    bool verification(int);
    bool chercher_voy (QString Cin);


   private:
    int Cin,NumPass,Age;//Cin clé primaire unique et non null
    QString Nom, Prenom;
};
#endif // VOYAGEUR_H
