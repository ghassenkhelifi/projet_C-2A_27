#include "connection.h"
Connection::Connection()
{

}
bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("test-bd");
db.setUserName("system");
db.setPassword("BD2023");

if (db.open())
test=true;
    return  test;
}
