#ifndef INVOEGSCHERM_H
#define INVOEGSCHERM_H

#include <QDialog>

namespace Ui {
class InvoegScherm;
}

class InvoegScherm : public QDialog
{
    Q_OBJECT

public:
    explicit InvoegScherm(QWidget *parent = 0);
    ~InvoegScherm();
    friend class MainWindow;
private slots:
    void on_Toevoegen_clicked();

    void on_Terug_clicked();

private:
    Ui::InvoegScherm *ui;
    QString algName;
    bool toevoegen;
};

#endif // INVOEGSCHERM_H
