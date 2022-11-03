#ifndef VOL_H
#define VOL_H

#include<QSqlQueryModel>
#include<QString>
class vol
{
    public:
       vol();
       vol(int,int,QString,QString,QString,QString);

       // get
       int getnumero_vol();
       int getcapacite();
       QString getnom_pilote();
       QString getville_depart();
       QString getville_arrivee();
       QString gettype();

       //set
       void setnumero_vol(int);
       void setcapacite(int);
       void setnom_pilote(QString);
       void setville_depart(QString);
       void setville_arrivee(QString);
       void settype(QString);
     ///
       bool ajouter();
      QSqlQueryModel* afficher();
      bool supprimer(int);
      bool modifier(int );

private:
  int numero_de_vol,capacite;
  QString nom_pilote,ville_depart,ville_arrivee,type;


};

#endif // VOL_H
