#include "vol.h"
#include <QSqlQuery>
#include <QDebug>
#include<QSqlQueryModel>
#include<QObject>
vol::vol()
{
numero_de_vol=0;
capacite=0;
nom_pilote=" ";
ville_depart=" ";
ville_arrivee=" ";
type=" ";
}


//////
vol ::vol(int numero_de_vol,int capacite,QString nom_pilote,QString ville_depart ,QString ville_arrivee,QString type)
{
  this->numero_de_vol=numero_de_vol;
  this->capacite=capacite;
  this->nom_pilote=nom_pilote;
  this->ville_depart=ville_depart;
  this->ville_arrivee=ville_arrivee;
  this->type=type;

}

// get
int vol::getnumero_vol()
{return numero_de_vol;}

int vol::getcapacite()
{return  capacite;}

QString vol:: getnom_pilote()
{return nom_pilote;}

QString vol::getville_depart()
{return  ville_depart;}

QString vol::getville_arrivee()
{return ville_arrivee;}

QString vol::gettype()
{return type;}

//set
void vol::setnumero_vol(int numero_de_vol)
{this->numero_de_vol=numero_de_vol; }

void vol::setcapacite(int capacite)
{this->capacite=capacite;}

void vol::setnom_pilote(QString nom_pilote)
{this->nom_pilote=nom_pilote;}

void vol::setville_depart(QString ville_depart)
{this->ville_depart=ville_depart;}

void vol::setville_arrivee(QString ville_arrivee)
{this->ville_arrivee=ville_arrivee;}

void vol::settype(QString type)
{this->type=type;}
bool vol :: ajouter()
{



    QSqlQuery query;
        QString id_string=QString::number(numero_de_vol);
        QString  capacite_string=QString::number(capacite);
              query.prepare(" insert into gs_vol (NUM_DE_VOL, CAPACITE, TYPE,VILLE_DE_DEPART,VILLE_D_ARRIVEE,NOM_PILOTE) "
                            "values (:num_de_vol,:capacite,:type,:ville_de_depart,:ville_d_arrivee,: nom_pilote)");
              query.bindValue(":num_de_vol", id_string);
               query.bindValue(":capacite", capacite_string);

               query.bindValue(":type", type);
               query.bindValue(":ville_de_depart", ville_depart);
               query.bindValue(":ville_d_arrivee", ville_arrivee);

                query.bindValue(":nom_pilote", nom_pilote);

                return      query.exec();


}

QSqlQueryModel* vol:: afficher()
{

  QSqlQueryModel* model=new QSqlQueryModel();


  model->setQuery("SELECT *FROM  vol");
  model->setHeaderData(0, Qt::Horizontal,QObject ::tr("numero"));
  model->setHeaderData(1, Qt::Horizontal,QObject :: tr("capacite"));
  model->setHeaderData(3, Qt::Horizontal,QObject ::tr("type"));
  model->setHeaderData(4, Qt::Horizontal,QObject :: tr("ville de depart"));
  model->setHeaderData(5, Qt::Horizontal,QObject ::tr("ville d arrivee"));
  model->setHeaderData(6, Qt::Horizontal,QObject :: tr("nom de pilote"));




  return model;

}
////

bool vol::supprimer(int numero_de_vol)
{
QSqlQuery query;
QString res= QString::number(numero_de_vol);
query.prepare("Delete from GS_VOL where numero_de_vol = :numero_de_vol ");
query.bindValue(":numero_de_vol", res);
return    query.exec();
}


bool vol::modifier(int numero_de_vol)
{
    QSqlQuery query;
    QString res= QString::number(numero_de_vol);
    query.prepare("UPDATE AV_FOURNITURE SET NUMERO_DE_VOL=:numero_de_vol,capacite=:capacite,ville_de_depart=:ville_de_depart,ville_d_arrivee=:ville_d_arrivee,nom_de_pilote=:nom_de_pilote, numero_de_vol=:numero_de_vol WHERE numero_de_vol=:numero_de_vol");
    query.bindValue(":numero_de_vol", numero_de_vol);
    query.bindValue(":capcite", capacite);
    query.bindValue(":type", type);
    query.bindValue(":ville_depart", ville_depart );
    query.bindValue(":ville_d_arrivee", ville_arrivee);
    query.bindValue(":nom_pilote", nom_pilote);
    return    query.exec();

}

