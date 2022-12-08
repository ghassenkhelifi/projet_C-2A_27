#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"
#include "arduino.h"

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
        void update_label();

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

private:
    Ui::MainWindow *ui;
    Employe g;
    Employe d;
    Employe supp;
    QStringList files;
    QByteArray data; // variable contenant les données reçues

    Arduino A;
};

#endif // MAINWINDOW_H
