#include "connection.h"
Connection::Connection()
{

}
bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A27");
db.setUserName("mouhamed");
db.setPassword("mouhamed");

if (db.open())
test=true;
    return  test;
}
