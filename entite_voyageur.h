#ifndef ENTITE_VOYAGEUR_H
#define ENTITE_VOYAGEUR_H
#include"voyageur.h"
#include <QDialog>

namespace Ui {
class entite_voyageur;
}

class entite_voyageur : public QDialog
{
    Q_OBJECT

public:
    explicit entite_voyageur(QWidget *parent = nullptr);
    //void setVoyageur(Voyageur v);
    ~entite_voyageur();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();


    void on_pb_modifier_clicked();

private:
    Ui::entite_voyageur *ui;
    Voyageur v;

};


#endif // ENTITE_VOYAGEUR_H
