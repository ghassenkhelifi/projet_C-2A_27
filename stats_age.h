#ifndef STATS_AGE_H
#define STATS_AGE_H

#include <QDialog>
#include <QDialog>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

QT_CHARTS_USE_NAMESPACE
namespace Ui {
class stats_age;
}

class stats_age : public QDialog
{
    Q_OBJECT

public:
    explicit stats_age(QWidget *parent = nullptr);
    ~stats_age();
    void stats();
    QChartView *chartView ;

private:
    Ui::stats_age *ui;
};

#endif // STATS_AGE_H
