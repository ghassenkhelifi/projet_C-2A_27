#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <QMessageBox>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QFile>
#include <QSortFilterProxyModel>
#include <QtPrintSupport/QPrinter>
#include <QPdfWriter>
#include <QPainter>
#include "produits.h"
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QTextStream>
#include<QWidget>
#include <QtSvg/QSvgRenderer>
#include<QDirModel>
#include "qrcode.h"
using qrcodegen::QrCode;
using qrcodegen::QrSegment;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_produits->setModel(P.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
       QString nom=ui->le_nom->text();
       QString etat=ui->comboBox_etat->currentText();
       float prix=ui->le_prix->text().toFloat();
       Produits P(id,nom,etat,prix);


       bool test=P.ajouter();
       if(test)
       {
            ui->tab_produits->setModel(P.afficher());
           QMessageBox::information(nullptr, QObject::tr("database is open"),
                       QObject::tr("ajout effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
      else
           QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                       QObject::tr("ajout non effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_clicked()
{
    bool test=false;
       int id=ui->le_id_2->text().toInt();
       QString nom= ui->le_nom_2->text();
       QString etat=ui->l_etat_2->currentText();
       float prix= ui->le_prix_2->text().toFloat();
       Produits P(id,nom,etat,prix);
       P.set_id(ui->le_id_2->text().toInt());
       test=P.modifier(P.get_id());

       if(test)

           {
           ui->tab_produits->setModel(P.afficher());
           QMessageBox::information(nullptr, QObject::tr("effectué"),

                               QObject::tr(" Modifié.\n"

                                           "Click Cancel to exit."), QMessageBox::Cancel);
            ui->le_id_2->clear();
            ui->le_nom_2->clear();
            ui->le_prix_2->clear();

       }
       else

           {

               QMessageBox::critical(nullptr, QObject::tr("non effectué"),

                           QObject::tr("non modifié !.\n"

                                       "Click Cancel to exit."), QMessageBox::Cancel);
               ui->le_id_2->clear();
               ui->le_nom_2->clear();
               ui->le_prix_2->clear();



   }
}

void MainWindow::on_pb_Rech_clicked()
{
    QString nom = ui->rech_Nom->text();
           QString prix = ui->rech_Prix->text();
           QString id=ui->rech_ID->text();

           ui->tab_produits->setModel(P.recherche(nom,prix,id));
}

void MainWindow::on_pushButton_clicked()
{
    ui->tab_produits->setModel(P.afficher());
}

void MainWindow::on_tab_produits_activated(const QModelIndex &index)
{
    ui->le_id->setText(ui->tab_produits->model()->data(ui->tab_produits->model()->index(index.row(),0)).toString());
            ui->le_nom->setText(ui->tab_produits->model()->data(ui->tab_produits->model()->index(index.row(),1)).toString());
             ui->le_prix->setText(ui->tab_produits->model()->data(ui->tab_produits->model()->index(index.row(),2)).toString());
}

void MainWindow::on_pb_suppr_clicked()
{
    Produits p;
       bool test=false;
       p.set_id(ui->lineEditsup->text().toInt());
       test=p.supprimer(p.get_id());
           if(test)
           {
                ui->tab_produits->setModel(P.afficher());
               QMessageBox::information(nullptr, QObject::tr("database is open"),
                           QObject::tr("suppression effectué.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
               ui->lineEditsup->clear();

       }
          else
               QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                           QObject::tr("suppression non effectué.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_rb_id_toggled(bool checked)
{
    if (checked == true){
               ui->tab_produits->setModel(P.trierParId());
           } else {
                ui->tab_produits->setModel(P.afficher());
           }
}


void MainWindow::on_rb_1_toggled(bool checked)
{
    if (checked == true){
               ui->tab_produits->setModel(P.trier());
           } else {
                ui->tab_produits->setModel(P.afficher());
           }
}

void MainWindow::on_rb_2_toggled(bool checked)
{
    if (checked == true){
               ui->tab_produits->setModel(P.trierParPrix());
           } else {
                ui->tab_produits->setModel(P.afficher());
           }
}


void MainWindow::on_QR_clicked()
{
    if(ui->tab_produits->currentIndex().row()==-1)
                  QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                           QObject::tr("Veuillez Choisir un identifiant.\n"
                                                       "Click Ok to exit."), QMessageBox::Ok);
              else
              {

                   int le_id=ui->tab_produits->model()->data(ui->tab_produits->model()->index(ui->tab_produits->currentIndex().row(),0)).toInt();
                   const QrCode qr = QrCode::encodeText(std::to_string(le_id).c_str(), QrCode::Ecc::LOW);
                   std::ofstream myfile;
                   myfile.open ("qrcode.svg") ;
                   myfile << qr.toSvgString(1);
                   myfile.close();
                   QPixmap pix( QSize(90, 90) );
                   QPainter pixPainter( &pix );
                   QSvgRenderer svgRenderer(QString("qrcode.svg"));
                   svgRenderer.render( &pixPainter );
                   ui->QRCODE_3->setPixmap(pix);

              }
}

void MainWindow::on_pb_pdf_clicked()
{

    bool test=false;
    test=P.genererPDFproduit();
    if(test)

        {
        ui->tab_produits->setModel(P.afficher());
        QMessageBox::information(nullptr, QObject::tr("créé"),

                            QObject::tr(" PDF créé.\n"

                                        "Click Cancel to exit."), QMessageBox::Cancel);}
    else

        {

            QMessageBox::critical(nullptr, QObject::tr("non créé"),

                        QObject::tr("PDF non créé !.\n"

                                    "Click Cancel to exit."), QMessageBox::Cancel);



}
}
