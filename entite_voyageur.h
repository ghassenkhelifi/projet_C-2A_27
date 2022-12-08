#ifndef ENTITE_VOYAGEUR_H
#define ENTITE_VOYAGEUR_H
#include"voyageur.h"
#include <QDialog>
#include "stats_age.h"

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

    void on_pb_pdf_clicked();

    void on_pb_image_clicked();

    void on_pushButton_stat_clicked();

    void on_tri_Cin_clicked();

    void on_tri_Age_clicked();

    void on_le_Cin_rech_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::entite_voyageur *ui;
    stats_age *s;
    Voyageur v;
    int Cin,NumPass,Age;
    QString Nom, Prenom;

};


#endif // ENTITE_VOYAGEUR_H
