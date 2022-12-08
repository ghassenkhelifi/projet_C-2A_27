#ifndef STAT_H
#define STAT_H

#include"mainwindow.h"
#include <QtCharts>
#include <QChartView>
#include<QPieSeries>
#include<QPieSlice>
#include <QDialog>
#include <QWidget>

namespace Ui {
class stat1;
}

class stat1 : public QDialog
{
    Q_OBJECT

public:
    explicit stat1(QWidget *parent = nullptr);
    void make_age();
    void make_salary();
    ~stat1();

private:
    Ui:: stat1 *ui;
};

#endif // STAT_H

