#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QWidget>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    close();
    //ouvrir voyageur
    entite_voyageur *e=new entite_voyageur();
            e->setWindowTitle("entite_voyageur");
            e->show();

}


