#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "produits.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
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
    Produits P;
};
#endif // MAINWINDOW_H
