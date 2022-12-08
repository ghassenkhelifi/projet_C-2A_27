#include "produits.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QObject>
#include<QPdfWriter>
#include<QPainter>
Produits::Produits()
{
id=0;
nom="";
etat="";
prix=0;

}
Produits::Produits(int id,QString nom,QString etat,float prix)
{
    this->id=id;
    this->nom=nom;
    this->etat=etat;
    this->prix=prix;
}
int Produits::get_id(){return id;}
QString Produits::get_nom(){return nom;}
QString Produits::get_etat(){return etat;}
float Produits::get_prix(){return prix;}
void Produits::set_id(int id){this->id=id;}
void Produits::set_nom(QString nom){this->nom=nom;}
void Produits::set_etat(QString etat){this->etat=etat;}
void Produits::set_prix(float prix){this->prix=prix;}
bool Produits::ajouter()
{


    QSqlQuery query;
    QString id_string= QString::number(id);
    QString prix_string=QString::number(prix);
          query.prepare("INSERT INTO GESTIONPRODUITS (id, nom, etat, prix) "
                        "VALUES (?, ?, ?, ?)");
          query.addBindValue( id_string);
          query.addBindValue( nom);
          query.addBindValue( etat);
          query.addBindValue(prix_string);

    return query.exec();
}
QSqlQueryModel* Produits::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM GESTIONPRODUITS");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Etat"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix"));
    return model;
}
bool Produits::supprimer(int id)
{


    QSqlQuery query;
    QString id_string= QString::number(id);

          query.prepare("DELETE FROM GESTIONPRODUITS    WHERE id=:id");
          query.addBindValue( id_string);


    return query.exec();
}
bool Produits::modifier(int id)
{
    QSqlQuery query;
    QString id_string= QString::number(id);
    QString prix_string=QString::number(prix);

    query.prepare("UPDATE GESTIONPRODUITS SET id=:id,nom=:nom,etat=:etat ,prix=:prix WHERE id=:id");
    query.addBindValue( id_string);
    query.bindValue(":id", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":etat", etat);
    query.bindValue(":prix", prix_string);
    return    query.exec();
}
QSqlQueryModel* Produits::trier()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM GESTIONPRODUITS ORDER BY NOM ASC");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Prix"));


    return model;
}
QSqlQueryModel* Produits::trierParPrix()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM GESTIONPRODUITS ORDER BY PRIX ASC");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Prix"));


    return model;
}
QSqlQueryModel* Produits::trierParId()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM GESTIONPRODUITS ORDER BY ID ASC");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Prix"));


    return model;
}

QSqlQueryModel* Produits::recherche(QString nom, QString prix,QString id)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    QString query = "SELECT * FROM GESTIONPRODUITS ";
    if((nom != "") && (prix != "")&&(id!= "")){
        query = query + "WHERE NOM LIKE '%" + nom +"%' AND PRIX =  " + prix+"AND ID =" + id;
    } else if((nom != "") && (prix == "")&&(id == "")) {
        query = query + "WHERE NOM LIKE '%" + nom +"%'";
    } else if((nom == "") && (prix != "")&& (id == "")) {
        query = query + "WHERE PRIX = " + prix;
    } else if((nom != "") && (prix == "")&& (id != "")) {
        query = query + "WHERE NOM LIKE '%" + nom +"%' AND ID =  "+id;
    } else if((nom == "") && (prix != "")&& (id != "")) {
                query = query + "WHERE PRIX = " + prix+"AND ID +   "+id;
    } else if((nom != "") && (prix != "")&& (id == "")) {
        query = query + "WHERE NOM LIKE '%" + nom +"%' AND PRIX =  "+prix;
    } else if((nom == "") && (prix == "")&& (id != "")) {
        query = query + "WHERE ID = " + id;

    }

    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Identifiant"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Etat"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Prix"));


    return model;
}
bool Produits::genererPDFproduit()
{
    QPdfWriter pdf("C:\\Users\\USER\\OneDrive\\Documents\\Produit\\pdf.pdf");
    QPainter painter(&pdf);
                        int i = 4000;
                             painter.setPen(Qt::green);
                             painter.setFont(QFont("Arial", 50));
                             painter.drawText(1100,1200,"Liste des Produits");
                             painter.setPen(Qt::red);
                             painter.setFont(QFont("Arial", 15));
                             painter.drawRect(500,100,7700,2600);

                        painter.drawRect(2200,3000,4000,500);
                             painter.setFont(QFont("Arial", 9));
                             painter.drawText(2400,3300,"id");
                             painter.drawText(3500,3300,"nom");
                             painter.drawText(4600,3300,"etat");
                                painter.drawText(5700,3300,"prix");

                                QSqlQuery query;

                                                         query.prepare("select * from GESTIONPRODUITS");
                                                         query.exec();
                                                         while (query.next())
                                                         {
                                                             painter.drawText(2400,i,query.value(0).toString());
                                                             painter.drawText(3500,i,query.value(1).toString());
                                                             painter.drawText(4600,i,query.value(2).toString());
                                                             painter.drawText(5700,i,query.value(3).toString());
                                                             //painter.drawText(4600,i,query.value(4).toString());


                                                            i = i + 500;

                                                         }
 return query.exec();}
