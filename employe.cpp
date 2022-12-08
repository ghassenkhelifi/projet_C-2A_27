#include "employe.h"
#include "modify.h"

bool Employe::Ajouter(){ //YWRkIGVtcGxveWU=//
    QSqlQuery query;

    query.prepare("INSERT INTO EMPLOYES(ID, NOM, PRENOM, STATUS,  MAIL,"
                  "AGE, SALAIRE) "
                  "VALUES (:id, :nom, :prenom, :status, :mail, :age, :salaire)");
    query.bindValue(":id", this->getID());
    query.bindValue(":nom", this->getNom());
    query.bindValue(":prenom", this->getPrenom());
    query.bindValue(":status", this->getStatus());
    query.bindValue(":mail", this->getMail());
    query.bindValue(":age", this->getAge());
    query.bindValue(":salaire", this->getSal());

    return query.exec();
}

bool Employe::Modifier(QString id,QString nom ,QString prenom,QString status,QString mail,int age,int salaire) //update //
{
    QSqlQuery query ;
    query.prepare("UPDATE EMPLOYES SET ID= :id,NOM= :nom,PRENOM= :prenom,STATUS= :status,"
                  "MAIL= :mail,AGE= :age,SALAIRE= :salaire ");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":status",status);
    query.bindValue(":mail",mail);
    query.bindValue(":age",age);
    query.bindValue(":salaire",salaire);
    return query.exec();
}

QSqlQueryModel * Employe::Afficher(){ //afffichage1//
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT ID, NOM, PRENOM, STATUS, MAIL FROM EMPLOYES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("STATUS"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("MAIL"));

    return model;
}

QSqlQueryModel * Employe::Afficher_2(){ //afffichage2//
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT ID, NOM, PRENOM, STATUS, MAIL FROM EMPLOYES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("STATUS"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("MAIL"));

    return model;
}

bool Employe::Supprimer(QString id) //supprimer//
{
  QSqlQuery query2;
  query2.prepare("SELECT COUNT (*) FROM as count EMPLOYES  WHERE ID= :id");
  query2.bindValue(":id",id);
  if (query2.exec())
  {
  int a=query2.value(0).toInt();
  qDebug() <<a;
  }
  QSqlQuery query ;
  query.prepare("Delete from EMPLOYES where ID= :id");
  query.bindValue(":id",id);
  return query.exec();
}

QSqlQueryModel * Employe::researchid(QString i)
{
    QSqlQueryModel * model= new QSqlQueryModel();

         model->setQuery("select * from EMPLOYES where upper(ID) like upper ('%"+i+"%') ");
         model->setHeaderData(0, Qt::Vertical, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Vertical, QObject::tr("NOM"));
         model->setHeaderData(2, Qt::Vertical, QObject::tr("PRENOM"));
         model->setHeaderData(3, Qt::Vertical, QObject::tr("STATUS"));
         model->setHeaderData(4, Qt::Vertical, QObject::tr("MAIL"));
             return model;
}
