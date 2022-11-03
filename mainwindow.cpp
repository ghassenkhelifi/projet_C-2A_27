#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "vol.h"
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_numero->setValidator(new QIntValidator(0,99999,this));
    ui->le_capacite->setValidator(new QIntValidator(0,99999,this));
    ui->tab_vol->setModel(v.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
   int numero_de_vol=ui->le_numero->text().toInt();
   int capacite=ui->le_capacite->text().toInt();
   QString nom_pilote=ui->le_nom_pilote->text();
   QString ville_depart=ui->le_ville_depart->text();
   QString ville_arrivee=ui->le_ville_arrivee->text();
   QString type=ui->le_type->text();

    vol v(numero_de_vol,capacite,nom_pilote,ville_depart,ville_arrivee,type);



    /////
    bool test=v.ajouter();

            if(test)
            {

                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("ajout effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
           else
                QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("ajout non effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            ui->le_numero->clear();
            ui->le_capacite->clear();
            ui->le_nom_pilote->clear();
            ui->le_ville_depart->clear();
            ui->le_ville_arrivee->clear();
            ui->le_type->clear();


}

void MainWindow::on_le_modifier_clicked()
{
    int numero_de_vol=ui->le_numero->text().toInt();
    int capacite=ui->le_capacite->text().toInt();
    QString nom_pilote=ui->le_nom_pilote->text();
    QString ville_depart=ui->le_ville_depart->text();
    QString ville_arrivee=ui->le_ville_arrivee->text();
    QString type=ui->le_type->text();
        vol v(numero_de_vol,capacite,type,ville_depart,ville_arrivee,nom_pilote);

        bool test=v.ajouter();
            if(test)
            {
                ui->tab_vol->setModel(v.afficher());
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                            QObject::tr("modification effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

        }
           else
                QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                            QObject::tr("modification non effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            ui->le_numero->clear();
            ui->le_capacite->clear();
            ui->le_nom_pilote->clear();
            ui->le_ville_depart->clear();
            ui->le_ville_arrivee->clear();
            ui->le_type->clear();
}
void MainWindow::on_le_supprimer_clicked()
{
     int numero_de_vol=ui->le_numero->text().toInt();

        bool test=v.supprimer(numero_de_vol);

        if(test)
        {
            ui->tab_vol->setModel(v.afficher());
            QMessageBox::information(nullptr, QObject::tr("OK"),
                        QObject::tr("suppression effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
       else
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                        QObject::tr("suppression non effectué.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        ui->le_numero->clear();
        ui->le_capacite->clear();
        ui->le_nom_pilote->clear();
        ui->le_ville_depart->clear();
        ui->le_ville_arrivee->clear();
        ui->le_type->clear();
}
