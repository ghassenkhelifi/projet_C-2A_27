#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QMessageBox>
#include "employe.h"
#include <authentification.h>
#include "connection.h"
#include"modify.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnect();
    authentification login;
    if(test)
    {
        login.show();

        qDebug() << "base connected successfully";

    }
    return a.exec();
}
