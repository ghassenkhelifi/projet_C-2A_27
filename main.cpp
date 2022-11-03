#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "employe.h"
#include "connection.h"
#include"modify.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    bool test=c.createconnect();
    MainWindow w;

    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click OK to exit."), QMessageBox::Cancel);
        qDebug() << "test";

}
    else{
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    qDebug() << "test failed";
    }

    return a.exec();
}
