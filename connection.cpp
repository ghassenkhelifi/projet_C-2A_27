#include "connection.h"
//test again 2
//Test Tutoriel Git
#include "produits.h"
Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test2-bd");
db.setUserName("habib");//inserer nom de l'utilisateur
db.setPassword("habib");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
