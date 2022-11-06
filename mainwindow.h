#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"entite_voyageur.h"
#include <QMainWindow>
#include"voyageur.h"
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


    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    Voyageur v;
    entite_voyageur e;
};

#endif // MAINWINDOW_H
