
#ifndef MODIFY_H
#define MODIFY_H

#include <QDialog>
#include"employe.h"

namespace Ui {
class modify;
}

class modify : public QDialog
{
    Q_OBJECT

public:
    explicit modify(QWidget *parent = nullptr);
    ~modify();

private slots:


    void on_pushButton_2_clicked();

private:
    Ui::modify *ui;
    Employe e ;
};

#endif // MODIFY_H
