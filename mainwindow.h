#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vol.h>

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
    void on_pb_ajouter_clicked();

    void on_le_modifier_clicked();

    void on_le_supprimer_clicked();

private:
    Ui::MainWindow *ui;
    vol v;
};

#endif // MAINWINDOW_H
