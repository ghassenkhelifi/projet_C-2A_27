#include<QtDebug>
#include<QObject>
#include"voyageur.h"
#include <QSqlQuery>

Voyageur::Voyageur()
{
 Cin=0; Nom=" "; Prenom=" ";NumPass=0; Numero=0 ;
}
 Voyageur::Voyageur(int Cin, QString Nom, QString Prenom,int NumPass,int Numero)
 { this->Cin=Cin; this->Nom=Nom; this->Prenom=Prenom,this->NumPass=NumPass,this->Numero=Numero;
 }
     int Voyageur::getCin() {return Cin;}
     QString Voyageur::getNom() {return Nom;}
     QString Voyageur::getPrenom() {return Prenom;}
     int Voyageur::getNumPass(){return NumPass;}
     int Voyageur::getNumero(){return Numero;}
     void Voyageur::setCin(int Cin){this->Cin=Cin;}
     void Voyageur::setNom(QString Nom){this->Nom=Nom;}
     void Voyageur::setPrenom(QString Prenom){this->Prenom=Prenom;}
     void Voyageur::setNumPass(int NumPass){this->NumPass=NumPass;}
     void Voyageur::setNumero(int Numero){this->Numero=Numero;}
     bool Voyageur :: ajouter()

     { //bool test=false;

         QSqlQuery query;
         QString Cin_string=QString::number(Cin);
         QString NumPass_string=QString::number(NumPass);
         QString Numero_string=QString::number(Numero);
         query.prepare("INSERT INTO voyageur (CIN, NOM, PRENOM,NUMPASS,NUMERO) "
                       "VALUES (:CIN, :NOM, :PRENOM,:NUMPASS,:NUMERO)");
         query.bindValue(":CIN", Cin_string);
         query.bindValue(":NOM", Nom);
         query.bindValue(":PRENOM", Prenom);
         query.bindValue(":NUMPASS", NumPass_string);
         query.bindValue(":NUMERO", Numero_string);

      return query.exec();//execution
     // return test;
     }

bool Voyageur::supprimer(int Cin)
{
  QSqlQuery query;
  query.prepare("Delete from voyageur where Cin=:Cin");
  query.bindValue(0, Cin);


return query.exec();

}
QSqlQueryModel *Voyageur::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT* FROM voyageur");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("NumPass"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("Numero"));

   return model;
}



bool Voyageur::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE voyageur SET Cin=:Cin,Nom =:Nom,Prenom =:Prenom,NumPass =:NumPass,Numero =:Numero WHERE Cin=:Cin ");
    query.bindValue(":Cin", Cin);
    query.bindValue(":Nom", Nom);
    query.bindValue(":Prenom", Prenom);
    query.bindValue(":NumPass", NumPass);
    query.bindValue(":Numero", Numero);

    return query.exec();
}

