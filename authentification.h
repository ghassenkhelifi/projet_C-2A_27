#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H
#include "arduino.h"
#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class authentification;
}

class authentification : public QDialog
{
    Q_OBJECT

public:
    explicit authentification(QWidget *parent = nullptr);
    ~authentification();

private slots:
    void on_pushButton_clicked();
    void update_label();
private:
    Ui::authentification *ui;
    MainWindow menu;
    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
};

#endif // AUTHENTIFICATION_H
