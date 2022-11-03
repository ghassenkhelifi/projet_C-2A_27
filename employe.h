#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>
#include <QTime>
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Employe
{
   protected: // attributs //
        QString id;
        QString nom;
        QString prenom;
        QString status;
        QString mail;
        int age;
        int salaire;
    public: // methode //
        Employe(){};
        Employe(QString i, QString n, QString p, QString s, QString m, int a, int sal)
        {
            this->id = i;
            this->nom = n;
            this->prenom = p;
            this->status = s;
            this->mail = m;
            this->age = a;
            this->salaire = sal;
        };
        QString getID(){return this->id;};
        QString getNom(){return this->nom;};
        QString getPrenom(){return this->prenom;};
        QString getStatus(){return this->status;};
        QString getMail(){return this->mail;};
        int getAge(){return this->age;};
        int getSal(){return this->salaire;};
        // set functions //
        void setID(QString);
        bool Ajouter();
        bool Supprimer(QString);
        bool Modifier(QString,QString,QString,QString,QString,int,int);
        QSqlQueryModel * Afficher();
        QSqlQueryModel * Afficher_2();
};

#endif // EMPLOYE_H
