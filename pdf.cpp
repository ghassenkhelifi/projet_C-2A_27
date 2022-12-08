#include "pdf.h"
#include "ui_pdf.h"
#include"employe.h"
#include"mainwindow.h"
#include<QPdfWriter>
#include<QMessageBox>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>

pdf::pdf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pdf)
{
    ui->setupUi(this);
    setWindowTitle("PDF");
}

pdf::~pdf()
{
    delete ui;
}

void pdf::on_pushButton_clicked() // pdf //
{
    QPdfWriter pdf("C:/Users/mhmdb/OneDrive/Desktop/employe.pdf");
    QPainter painter(&pdf);
    QString id = ui->line_pdf->text();
    QSqlQuery test ;
    test.prepare("SELECT COUNT(*) from EMPLOYES where ID= :id");
    test.bindValue(":id",id);
    test.exec();
    if (test.next())
    {
  if (test.value(0).toInt() == 1)
  {
    QSqlQuery query ;
    query.prepare("select ID , NOM ,PRENOM , STATUS ,  MAIL , AGE , SALAIRE  from EMPLOYES where ID= :id");
    query.bindValue(":id",id);
    query.exec();
    if (query.next())
    {
    QString ident = query.value(0).toString();
    QString nom = query.value(1).toString();
    QString prenom = query.value(2).toString();
    QString status = query.value(3).toString();
    QString mail= query.value(4).toString();
    QString age = query.value(5).toString();
    QString salary = query.value(6).toString();

    painter.setPen(Qt::blue);
    painter.drawText(600,500,"IDENTIFIANT : ");
    painter.drawText(600,700,"NOM : ");
    painter.drawText(600,900,"PRENOM : ");
    painter.drawText(600,1100,"STATUS : ");
    painter.drawText(600,1300,"MAIL : ");
    painter.drawText(600,1500,"AGE : ");
    painter.drawText(600,1700,"SALARY : ");



    painter.setPen(Qt::black);
    painter.drawText(1500,500,ident);
    painter.drawText(1500,700,nom);
    painter.drawText(1500,900,prenom);
    painter.drawText(1500,1100,status);
    painter.drawText(1500,1300,mail);
    painter.drawText(1500,1500,age);
    painter.drawText(1500,1700,salary);

    painter.end();

    }
    qDebug()<<"PDF DONE";
 }
  else
  {
     qDebug()<<"PDF NOT DONE";
  }
  }
}
