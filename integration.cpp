#include "ui_mainwindow.h"
#include "employe.h"
#include"integration.h"
#include "produits.h"
#include "qrcode.h"
#include"qrwidget.h"
#include "modify.h"
#include <qdebug.h>
#include "QMessageBox"
#include <bits/stdc++.h>
#include <QFileDialog>
#include <QtCore>
#include "smtp.h"
#include "stat1.h"
#include "pdf.h"
#include "arduino.h"
using namespace std;

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

/*/////////////////////////////////////////////////////////////////////
////////////////////////////////  GESTION DES PRODUITS   //////////////////////////////////////*/

void MainWindow::on_pb_suppr_clicked()
{
    Produits p;
       bool test=false;
       p.set_id(ui->lineEditsupr->text().toInt());
       test=p.supprimer(p.get_id());
           if(test)
           {
                ui->tab_produits->setModel(P.afficher());
               QMessageBox::information(nullptr, QObject::tr("database is open"),
                           QObject::tr("suppression effectué.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);
               ui->lineEditsup_2->clear();

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



/*void MainWindow::on_pb_image_clicked()
{
    QString filename= QFileDialog::getOpenFileName(this,tr("CHOOSE"),"",tr("Images(*.png *.jpg *.jpeg *.bmp *.gif)"));
                if(QString::compare(filename,QString())!=0)
                {
                    QImage image;
                    bool valid = image.load(filename);
                    if(valid)
                    {
                        image= image.scaledToWidth(ui->le_image->width(), Qt::SmoothTransformation);
                        image= image.scaledToHeight(ui->le_image->height(), Qt::SmoothTransformation);
                        ui->le_image->setPixmap(QPixmap::fromImage(image));
                    }
                    else
                    {
                        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                        QObject::tr("Add Failed !"), QMessageBox::Ok);
                    }
                }

}*/





