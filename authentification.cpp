#include "authentification.h"
#include "ui_authentification.h"
#include <QMessageBox>
#include"mainwindow.h"
#include <QThread>
authentification::authentification(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::authentification)
{
    ui->setupUi(this);
    setWindowTitle("LOGIN");
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



}
void authentification::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")
{
         qDebug()<<"1";
         QMessageBox::information(nullptr, QObject::tr("ALERT!"),
                                    QObject::tr("!!!!!FIRE EXIT!!!!!!\n"), QMessageBox::Ok);

}

}

authentification::~authentification()
{
    delete ui;
}

void authentification::on_pushButton_clicked()
{
    QString username = ui->user->text();
    QString password = ui->password->text();


    if (username == "malek" && password == "malek")
    {
        hide();
        qDebug()<<"WELCOME !";
        menu.show();

    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("ERROR"),
                                   QObject::tr("INVALID USERNAME OR PASSWORD.\nClick Cancel to exit."), QMessageBox::Ok);
    }
}
