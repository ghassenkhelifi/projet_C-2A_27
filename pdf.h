#ifndef PDF_H
#define PDF_H

#include <QDialog>

namespace Ui {
class pdf;
}

class pdf : public QDialog
{
    Q_OBJECT

public:
    explicit pdf(QWidget *parent = nullptr);
    ~pdf();

private slots:
    void on_pushButton_clicked();

private:
    Ui::pdf *ui;
};

#endif // PDF_H

