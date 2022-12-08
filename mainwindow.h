#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"
#include "arduino.h"
#include "voyageur.h"
#include "stats_age.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_clicked();

    void on_delete_2_clicked();

    void on_modify_clicked();

    void on_age_clicked();

    void sendMail();

    void mailSent(QString);

    void browse();

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
       // void update_label();

        void on_pb_ajouter_clicked();

        void on_pb_modifier_clicked();

        void on_pb_Rech_clicked();

        void on_pushButton_clicked();

        void on_tab_produits_activated(const QModelIndex &index);

        void on_pb_suppr_clicked();

        void on_rb_id_toggled(bool checked);

        void on_rb_1_toggled(bool checked);

        void on_rb_2_toggled(bool checked);

        void on_QR_clicked();

        void on_pb_pdf_clicked();


        void on_pb_ajouter_2_clicked();

        void on_pb_modifier_2_clicked();

        void on_pb_pdf_2_clicked();

        void on_pushButton_stat_clicked();

        void on_pb_supprimer_clicked();

        void on_le_Cin_rech_cursorPositionChanged(int arg1, int arg2);

        void on_tri_Cin_clicked();

        void on_tri_Age_clicked();

        void updatelabel();

        void on_pushButton_5_clicked();

        void on_pushButton_2_clicked();



        void on_pb_image_clicked();

private:
    Ui::MainWindow *ui;
    Employe g;
    Employe d;
    Employe supp;
    Voyageur v;
    stats_age *s;
    QStringList files;
    QByteArray data; // variable contenant les données reçues

    Arduino A;
};

#endif // MAINWINDOW_H
