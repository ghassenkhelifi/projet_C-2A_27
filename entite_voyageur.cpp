#include "entite_voyageur.h"
#include "voyageur.h"
#include "ui_entite_voyageur.h"
#include <QMessageBox>
#include<QSqlQuery>
#include<QString>
#include <QIntValidator>
#include<QPdfWriter>
#include<QPainter>
#include<QPixmap>
#include<QPrinter>
#include<QTextStream>
#include<QTextDocument>
#include<QFileDialog>
#include <QSystemTrayIcon>

entite_voyageur::entite_voyageur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::entite_voyageur)
{
    ui->setupUi(this);
    ui->le_Cin->setValidator( new QIntValidator(100, 99999999, this));//controle de saisie
    ui->le_NumPass->setValidator( new QIntValidator(100, 99999999, this));
    ui->le_Age->setValidator( new QIntValidator(100, 99999999, this));
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
    int Age=ui->le_Age->text().toInt();

   Voyageur v (Cin,Nom,Prenom,NumPass,Age );
   bool test=v.ajouter();
       if(test)
       {
           ui->tab_voyageur->setModel(v.afficher());
           QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

           notifyIcon->show();
           notifyIcon->showMessage("ALERTE NOTIF","un element est ajoutée ",QSystemTrayIcon::Information,15000);
           QMessageBox::information(nullptr, QObject::tr("database is open"),
                       QObject::tr("ajout effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
      else
           QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                       QObject::tr("ajout non effectué.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       ui->le_Cin->clear();
       ui->le_Nom->clear();
       ui->le_Prenom->clear();
       ui->le_NumPass->clear();
       ui->le_Age->clear();
}



void entite_voyageur::on_pb_supprimer_clicked()
{
    Voyageur v1; v1.setCin(ui->le_Cin_supp->text().toInt());
    bool test=false;
    bool trouver=v1.verification(v1.getCin());
       if (trouver)
         test=v.supprimer(v1.getCin());
    QMessageBox msgBox;

    if (test)
    {

      msgBox.setText("Supprimer avec succes.");
      ui->tab_voyageur->setModel(v.afficher());
      QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

      notifyIcon->show();
      notifyIcon->showMessage("ALERTE NOTIF","un element Supprimée",QSystemTrayIcon::Information,15000);
    }

    else
       msgBox.setText("Echec de suppression");
       msgBox.exec();

       ui->le_Cin_supp->clear();

}

void entite_voyageur::on_pb_modifier_clicked()
{
    int Cin=ui->le_Cin->text().toInt();
    QString Nom=ui->le_Nom->text();
    QString Prenom=ui->le_Prenom->text();
    int NumPass=ui->le_NumPass->text().toInt();
    int Age=ui->le_Age->text().toInt();
    Voyageur v (Cin,Nom,Prenom,NumPass,Age);
    v.setCin(ui->le_Cin->text().toInt());
    bool test =false;
    bool trouver=v.verification(v.getCin());
     if (trouver)
      test=v.modifier();
    if(test){
        ui->tab_voyageur->setModel(v.afficher());
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

        notifyIcon->show();
        notifyIcon->showMessage("ALERTE NOTIF ","Un element est modifiée",QSystemTrayIcon::Information,15000);

        QMessageBox::information(nullptr,"modification activite","activite modifie avec succés");
    }
    else
            QMessageBox::warning(nullptr,"Error","activite non modifie");


    ui->le_Cin->clear();
    ui->le_Nom->clear();
    ui->le_Prenom->clear();
    ui->le_NumPass->clear();
    ui->le_Age->clear();
}

/*
void entite_voyageur::on_pb_trier_clicked()
{

        Voyageur v;
        ui->tab_voyageur->setModel(v.trier());

}
*/
void entite_voyageur::on_tri_Cin_clicked()
{
    Voyageur *v=new Voyageur();
     ui->tab_voyageur->setModel(v->tri_Cin());
}

void entite_voyageur::on_tri_Age_clicked()
{
    Voyageur *v=new Voyageur();
     ui->tab_voyageur->setModel(v->tri_Age());
}



void entite_voyageur::on_le_Cin_rech_cursorPositionChanged(int arg1, int arg2)
{
    ui->tab_voyageur->setModel(v.rechercher(ui->le_Cin_rech->text()));

        QString test =ui->le_Cin_rech->text();

        if(test=="")
        {
            ui->tab_voyageur->setModel(v.afficher());//refresh
        }
}


void entite_voyageur::on_pb_pdf_clicked()
{
    QPrinter printer;
         printer.setPrinterName("desired printer name");
     QString strStream;
                    QTextStream out(&strStream);
                    const int rowCount = ui->tab_voyageur->model()->rowCount();
                    const int columnCount =ui->tab_voyageur->model()->columnCount();


                    out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("eleve")
                            <<  "</head>\n"
                            "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                                "<h1>Liste des Voyageurs</h1>"
                                  "<img src=\"C:/Users/malek bdiri/Desktop/logo\" >"
                                  "<img src=\"C:/Users/malek bdiri/Desktop/logo si pdf.png\" >"
                                "<table border=1 cellspacing=0 cellpadding=2>\n";

                    // headers
                        out << "<thead><tr bgcolor=#f0f0f0>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tab_voyageur->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->tab_voyageur->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";
                        // data table
                           for (int row = 0; row < rowCount; row++) {
                               out << "<tr>";
                               for (int column = 0; column < columnCount; column++) {
                                   if (!ui->tab_voyageur->isColumnHidden(column)) {
                                       QString data = ui->tab_voyageur->model()->data(ui->tab_voyageur->model()->index(row, column)).toString().simplified();
                                       out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));

                                       QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

                                       notifyIcon->show();
                                       notifyIcon->showMessage("ALERTE NOTIF ","Un PDF a été crée",QSystemTrayIcon::Information,15000);
                                   }
                               }
                               out << "</tr>\n";
                           }
                           out <<  "</table>\n"
                               "</body>\n"
                               "</html>\n";



            QTextDocument *document = new QTextDocument();
            document->setHtml(strStream);


            //QTextDocument document;
            //document.setHtml(html);
        //    QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("voyageur.pdf");
            document->print(&printer);
}


void entite_voyageur::on_pb_image_clicked()
{
    QMessageBox msgbox;
        QString filename= QFileDialog::getOpenFileName(this,tr("Selectionnez"),"",tr("Images(*.png *.jpeg *.jpg)"));
        if(QString::compare(filename, QString())!=0)
        {
            QImage image;
            bool valid = image.load(filename);
            if (valid)
            {
                image=image.scaledToWidth(ui->pb_image->width(), Qt::SmoothTransformation);
                ui->le_image->setPixmap(QPixmap::fromImage(image));
            }
            else
                msgbox.setText("failed");
        }
}

void entite_voyageur::on_pushButton_stat_clicked()
{
    s = new stats_age();
    s->setWindowTitle("statistique Age voyageur");
    s->stats();
    s->show();

}

