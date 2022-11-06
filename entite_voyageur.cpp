#include "entite_voyageur.h"
#include "voyageur.h"
#include "ui_entite_voyageur.h"
#include <QMessageBox>
#include <QIntValidator>


entite_voyageur::entite_voyageur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::entite_voyageur)
{
    ui->setupUi(this);
    ui->le_Cin->setValidator( new QIntValidator(100, 99999999, this));//controle de saisie
    ui->le_NumPass->setValidator( new QIntValidator(100, 99999999, this));
    ui->le_Numero->setValidator( new QIntValidator(100, 99999999, this));
    ui->le_Nom->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));

    ui->le_Prenom->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));

    ui->tab_voyageur->setModel(v.afficher());
}

entite_voyageur::~entite_voyageur()
{
    delete ui;//destructeur
}

void entite_voyageur::on_pb_ajouter_clicked()
{

    int Cin=ui->le_Cin->text().toInt();
    QString Nom=ui->le_Nom->text();
    QString Prenom=ui->le_Prenom->text();
    int NumPass=ui->le_NumPass->text().toInt();
    int Numero=ui->le_Numero->text().toInt();

   Voyageur v (Cin,Nom,Prenom,NumPass,Numero );
   bool test=v.ajouter();
       if(test)
       {
           ui->tab_voyageur->setModel(v.afficher());
           QMessageBox::information(nullptr, QObject::tr("database is open"),
                       QObject::tr("ajout effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
      else
           QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                       QObject::tr("ajout non effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}



void entite_voyageur::on_pb_supprimer_clicked()
{
    Voyageur v1; v1.setCin(ui->le_Cin_supp->text().toInt());
    bool test=v.supprimer(v1.getCin());
    QMessageBox msgBox;

    if (test)
    {

      msgBox.setText("Supprimer avec succes.");
      ui->tab_voyageur->setModel(v.afficher());
    }

    else
       msgBox.setText("Echec de suppression");
       msgBox.exec();

}




void entite_voyageur::on_pb_modifier_clicked()
{
    int Cin=ui->le_Cin->text().toInt();
    QString Nom=ui->le_Nom->text();
    QString Prenom=ui->le_Prenom->text();
    int NumPass=ui->le_NumPass->text().toInt();
    int Numero=ui->le_Numero->text().toInt();
    Voyageur v (Cin,Nom,Prenom,NumPass,Numero);
    bool test=v.modifier();
    if(test){
        ui->tab_voyageur->setModel(v.afficher());
        QMessageBox::information(nullptr,"modification activite","activite modifie avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","activite non modifie");


    ui->le_Cin->clear();
    ui->le_Nom->clear();
    ui->le_Prenom->clear();
    ui->le_NumPass->clear();
    ui->le_Numero->clear();
}











/*
void entite_voyageur::setVoyageur(Voyageur v)
{
int ui->le_Cin->setText(v.getCin());
QString ui->le_Nom->setText(v.getNom());
QString ui->le_Prenom->setText(v.getPrenom());
int ui->le_NumPass->setText(v.getNumPass());
int ui->le_Numero->setText(v.getNumero());
}
*/
