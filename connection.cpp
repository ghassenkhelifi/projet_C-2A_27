#include "connection.h"
Connection::Connection()
{

}
bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test2-bd");
db.setUserName("habib");
db.setPassword("habib");

if (db.open())
test=true;
    return  test;
}
