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
#include"employe.h"
#include"modify.h"
#include"smtp.h"
#include"pdf.h"
#include"stat1.h"

#include <QPixmap>
#include <QFileDialog>
#include <QTextDocument>
#include <QTextEdit>
#include <QTextStream>
#include<QWidget>
#include <QtSvg/QSvgRenderer>
#include<QDirModel>
#include "qrcode.h"
#include "arduino.h"
#include "entite_voyageur.h"
#include "ui_entite_voyageur.h"
#include <QSystemTrayIcon>

using namespace std;
using qrcodegen::QrCode;
using qrcodegen::QrSegment;

// valid id code : only uppercase and number (4 caracters exaclty) //
bool valid_id(QString id)
{
    for (int i = 0;i < id.length(); i++)
    {
       if((id[i] >= 'A' && id[i] <= 'Z') || (id[i] >= '0' && id[i] <= '9'))
       {

       }
           else
       {
       return false ;
       }
    }
    return true ;
}
// valid first name && last name //
bool valid_names(QString name)
{
    for (int i = 0;i < name.length(); i++)
    {
 if ((name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= 'a' && name[i] <= 'z'))
 {

 }
 else return false;
    }
         return true ;
}

bool isChar(QChar c)
{
    return ((c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z'));
}

bool isDigit(QChar c)
{
    return (c >= '0' && c <= '9');
}
bool nbis_valid(QString numb)
{
    for (int i = 0; i < numb.length(); i++) {
        if(!isDigit(numb[i])){
            return false;
        }
        else {
            return true;
        }
    }
}

bool is_valid(QString email)
{
    // Check the first character
    // is an alphabet or not
    if (!isChar(email[0])) {

        // If it's not an alphabet
        // email id is not valid
        return 0;
    }
    // Variable to store position
    // of At and Dot
    int At = -1, Dot = -1;

    // Traverse over the email id
    // string to find position of
    // Dot and At
    for (int i = 0;i < email.length(); i++)
    {
        // If the character is '@'
        if (email[i] == '@')
        {
            At = i;
        }
        // If character is '.'
        else if (email[i] == '.') {

            Dot = i;
        }
    }

    // If At or Dot is not present
    if (At == -1 || Dot == -1)
        return 0;

    // If Dot is present before At
    if (At > Dot)
        return 0;

    // If Dot is present at the end
    return !(Dot >= (email.length() - 1));
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->SEND, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->BROWSE, SIGNAL(clicked()), this, SLOT(browse()));

    ui->tableView->setModel(g.Afficher());
    ui->tableView_delete->setModel(d.Afficher_2());


        ui->le_Cin->setValidator( new QIntValidator(100, 99999999, this));//controle de saisie
        ui->le_NumPass->setValidator( new QIntValidator(100, 99999999, this));
        ui->le_Age->setValidator( new QIntValidator(100, 99999999, this));
        ui->le_Nom->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));
        ui->le_Prenom->setValidator(new QRegExpValidator(QRegExp("[a-z]*")));

        ui->tab_voyageur->setModel(v.afficher());




    setWindowTitle("employees managment");
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).



    qDebug()<<"start";
}
/*
void MainWindow::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")
{
         qDebug()<<"1";
        QMessageBox::information(nullptr, QObject::tr("ALERT!"),
                                   QObject::tr("!!!!!FIRE EXIT!!!!!!\n"), QMessageBox::Ok);

}

}
*/
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_add_clicked()
{
    QString id = ui->lineID_E->text();
    QString nom = ui->lineNom_E->text();
    QString prenom = ui->linePrenom_E->text();
    QString status = ui->combo_status->currentText();
    QString mail = ui->lineMail_E->text();
    int age = ui->spinAge_E->value();
    int salaire = ui->lineSalaire_E->text().toInt();

    Employe E(id, nom, prenom, status, mail, age, salaire);
    bool test = true;


 if (ui->lineID_E->text().size() == 4 && valid_id(ui->lineID_E->text()) )
    {
     if (valid_names(ui->lineNom_E->text()) && valid_names(ui->linePrenom_E->text()))

    {
    if (is_valid(ui->lineMail_E->text()))
    {
    if(test)
        {
        E.Ajouter();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                     QObject::tr("Ajout avec succés.\nClick Cancel to exit."), QMessageBox::Ok);


        }
        else
        {
        QMessageBox::information(nullptr, QObject::tr("database is not open"),
                                QObject::tr("Ajout échoué.\nClick Cancel to exit."), QMessageBox::Ok);
        qDebug() << "test";
        }
    ui->tableView->setModel(g.Afficher());
    ui->tableView_delete->setModel(g.Afficher());
}
    else {

        QMessageBox::information(nullptr, QObject::tr("ERROR"),
                                        QObject::tr("INVALID MAIL.\nClick Cancel to exit."), QMessageBox::Ok);
    }
    }
    else
{ QMessageBox::information(nullptr, QObject::tr("a"),
                           QObject::tr("INVALID PHONE NUMBER.\nClick Cancel to exit."), QMessageBox::Ok);

    }
}
else
{
    QMessageBox::information(nullptr, QObject::tr("ERROR"),
                                    QObject::tr("INVALID FIRST NAME OR LAST NAME.\nClick Cancel to exit."), QMessageBox::Ok);
}
}




void MainWindow::on_delete_2_clicked() //delete function //
{
       QString d=ui->lineID_d->text();
       bool test=true;
 supp.Supprimer(d);
        if(test)
        {

             QMessageBox::information(nullptr, QObject::tr("OK"),
                                     QObject::tr("suppression effectué.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
              }
                  else
            {
            QMessageBox::information(nullptr, QObject::tr("supprimer equipement"),
                                  QObject::tr("suppression echouée.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
            }
 ui->tableView->setModel(g.Afficher());
 ui->tableView_delete->setModel(g.Afficher());
}


void MainWindow::on_modify_clicked() //second window opener funtion //
{
    modify m;
    m.setModal(true);
    m.exec();
}

void MainWindow::on_age_clicked()
{
    QMessageBox msgBox ;
                QSqlQueryModel * model= new QSqlQueryModel();

                   model->setQuery("select * from EMPLOYES order by AGE");
                   model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENTIFIANT"));
                   model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
                   model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
                   model->setHeaderData(4, Qt::Horizontal, QObject::tr("STATUS"));
                   model->setHeaderData(3, Qt::Horizontal, QObject::tr("MAIL"));
                   model->setHeaderData(5, Qt::Horizontal, QObject::tr("AGE"));
                   if (ui->age->isChecked())
                   {
                            ui->tableView->setModel(model);
                            ui->tableView->show();
                            qDebug()<<"TRI DONE" ;
                   }
                   else {

                       ui->tableView->setModel(g.Afficher());
                       ui->tableView_delete->setModel(g.Afficher());
                   }
}

void  MainWindow::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
    fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );
    ui->file->setText( fileListString );

}

void   MainWindow::sendMail()
{
    Smtp* smtp = new Smtp("mouhamed.benabdallah@esprit.tn",ui->mail_pass->text(),"smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(" ", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void   MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
    QMessageBox::warning(nullptr, tr( "MAILLING" ), tr( "MESSAGE SENT\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}


void  MainWindow::on_checkBox_stateChanged(int arg1) //search //
{
    if (ui->checkBox->isChecked())
    {
    Employe s ;
    QString id = ui->line_research->text();
    ui->tableView->setModel(s.researchid(id));
    }
    else {
        ui->tableView->setModel(g.Afficher());
        ui->tableView_delete->setModel(g.Afficher());
}
}

void MainWindow::on_pushButton_3_clicked()
{
    pdf p;
    p.setModal(true);
    p.exec();
    qDebug()<<"pdf window open";
}

void MainWindow::on_pushButton_4_clicked()
{
    stat1 *w = new stat1();
               w->make_salary();
               w->show();
               qDebug()<<"stat window open";
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
    Produits P;
    QString nom = ui->rech_Nom->text();
           QString prix = ui->rech_Prix->text();
           QString id=ui->rech_ID->text();

           ui->tab_produits->setModel(P.recherche(nom,prix,id));
}

void MainWindow::on_pushButton_clicked()
{
    Produits P;
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
                ui->tab_produits->setModel(p.afficher());
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
    Produits P;
    if (checked == true){
               ui->tab_produits->setModel(P.trierParId());
           } else {
                ui->tab_produits->setModel(P.afficher());
           }
}

void MainWindow::on_rb_1_toggled(bool checked)
{
    Produits P;
    if (checked == true){
               ui->tab_produits->setModel(P.trier());
           } else {
                ui->tab_produits->setModel(P.afficher());
           }
}

void MainWindow::on_rb_2_toggled(bool checked)
{
    Produits P;
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
    Produits P;
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




void MainWindow::on_pb_ajouter_2_clicked()
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

void MainWindow::on_pb_modifier_2_clicked()
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

void MainWindow::on_pb_supprimer_clicked()
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


void MainWindow::on_tri_Cin_clicked()
{
    Voyageur *v=new Voyageur();
    ui->tab_voyageur->setModel(v->tri_Cin());
}

void MainWindow::on_tri_Age_clicked()
{
    Voyageur *v=new Voyageur();
    ui->tab_voyageur->setModel(v->tri_Age());
}

void MainWindow::on_le_Cin_rech_cursorPositionChanged(int arg1, int arg2)
{

    ui->tab_voyageur->setModel(v.rechercher(ui->le_Cin_rech->text()));

        QString test =ui->le_Cin_rech->text();

        if(test=="")
        {
            ui->tab_voyageur->setModel(v.afficher());//refresh
        }
}

void MainWindow::on_pb_pdf_2_clicked()
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

void MainWindow::on_pushButton_stat_clicked()
{
    s = new stats_age();
    s->setWindowTitle("statistique Age voyageur");
    s->stats();
    s->show();

}


void MainWindow::updatelabel()
{
data=A.read_from_arduino();

 ui->le_Cin1->setText(ui->le_Cin1->text()+data);
}


void MainWindow::on_pushButton_5_clicked()
{
    bool ch= v.chercher_voy(ui->le_Cin1->text());

    if(ch)
    {

        QMessageBox::information(nullptr, QObject::tr("sql query successful"),
                           QObject::tr("Voyageur found.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);


    }

    else{
        QMessageBox::critical(nullptr, QObject::tr("sql query unsuccessful"),
                           QObject::tr("Voyageur not found.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);



    }
}


void MainWindow::on_pb_image_clicked()
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

void MainWindow::on_pushButton_2_clicked()
{
    close();
    //ouvrir voyageur
    entite_voyageur *e=new entite_voyageur();
            e->setWindowTitle("entite_voyageur");
            e->show();

}




