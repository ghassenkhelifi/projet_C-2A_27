#include <QtDebug>
#include <QObject>
#include <QString>
#include "voyageur.h"
#include <QSqlQuery>

Voyageur::Voyageur()
{
 Cin=0; Nom=" "; Prenom=" ";NumPass=0; Age=0 ;
}
 Voyageur::Voyageur(int Cin, QString Nom, QString Prenom,int NumPass,int Age)
 { this->Cin=Cin; this->Nom=Nom; this->Prenom=Prenom,this->NumPass=NumPass,this->Age=Age;
 }
     int Voyageur::getCin() {return Cin;}
     QString Voyageur::getNom() {return Nom;}
     QString Voyageur::getPrenom() {return Prenom;}
     int Voyageur::getNumPass(){return NumPass;}
     int Voyageur::getAge(){return Age;}
     void Voyageur::setCin(int Cin){this->Cin=Cin;}
     void Voyageur::setNom(QString Nom){this->Nom=Nom;}
     void Voyageur::setPrenom(QString Prenom){this->Prenom=Prenom;}
     void Voyageur::setNumPass(int NumPass){this->NumPass=NumPass;}
     void Voyageur::setAge(int Age){this->Age=Age;}
     bool Voyageur :: ajouter()

     { //bool test=false;

         QSqlQuery query;
         QString Cin_string=QString::number(Cin);
         QString NumPass_string=QString::number(NumPass);
         QString Age_string=QString::number(Age);
         query.prepare("INSERT INTO VOYAGEUR (CIN, NOM, PRENOM,NUMPASS,AGE) "
                       "VALUES (:CIN, :NOM, :PRENOM,:NUMPASS,:AGE)");
         query.bindValue(":CIN", Cin_string);
         query.bindValue(":NOM", Nom);
         query.bindValue(":PRENOM", Prenom);
         query.bindValue(":NUMPASS", NumPass_string);
         query.bindValue(":AGE", Age_string);

      return query.exec();//execution
     // return test;
     }

bool Voyageur::supprimer(int Cin)
{
  QSqlQuery query;
  query.prepare("Delete from VOYAGEUR where Cin=:Cin");
  query.bindValue(0, Cin);


return query.exec();

}

QSqlQueryModel *Voyageur::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("SELECT* FROM VOYAGEUR");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("Cin"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("NumPass"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("Age"));

   return model;
}



bool Voyageur::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE VOYAGEUR SET Cin=:Cin,Nom =:Nom,Prenom =:Prenom,NumPass =:NumPass,Age =:Age WHERE Cin=:Cin ");
    query.bindValue(":Cin", Cin);
    query.bindValue(":Nom", Nom);
    query.bindValue(":Prenom", Prenom);
    query.bindValue(":NumPass", NumPass);
    query.bindValue(":Age", Age);

    return query.exec();
}


QSqlQueryModel *Voyageur::tri_Cin()
  {
    QSqlQueryModel *model= new QSqlQueryModel;
        QSqlQuery *q=new QSqlQuery();
        q->prepare("select * from VOYAGEUR order by Cin asc");
        q->exec();
        model->setQuery(*q);
        return  model;

  }

QSqlQueryModel *Voyageur::tri_Age()
  {
    QSqlQueryModel *model= new QSqlQueryModel;
        QSqlQuery *q=new QSqlQuery();
        q->prepare("select * from VOYAGEUR order by Age asc");
        q->exec();
        model->setQuery(*q);
        return  model;

  }
QSqlQueryModel * Voyageur::rechercher(QString rech)
 {

    QSqlQueryModel * model= new QSqlQueryModel();
         QString recher="select * from VOYAGEUR where Cin like '%"+rech+"%'";
         model->setQuery(recher);
         return model;
 }





bool Voyageur::verification(int Cin)
{

    QSqlQuery query;
    QString n;
    QString  num = QString::number(Cin);
            query.exec("SELECT Cin from VOYAGEUR");
            while (query.next())
            {
                n=query.value("Cin").toString();
                if (n==num)
                {
                    return true;
                }
            }
    return false;

      }



bool Voyageur::chercher_voy(QString Cin)
{


    QSqlQuery test ;
      test.prepare("SELECT COUNT(*)  FROM VOYAGEUR WHERE Cin= :Cin");
      test.bindValue(":Cin",Cin);
      test.exec();
      if (test.next())
      {
    if (test.value(0).toInt() == 1)
    {
        return true;
    }
       else
        return false;
      }

}
