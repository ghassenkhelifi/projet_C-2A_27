#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employe.h"

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

private:
    Ui::MainWindow *ui;
    Employe g;
    Employe d;
    Employe supp;
};

#endif // MAINWINDOW_H
