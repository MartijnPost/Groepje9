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

    void updateGraaf();

private:
    Ui::InvoegScherm *ui;
    QString algName; //titel van algoritme
    QString eigenAlgQ; //het algoritme van gebruiker
    std::string eigenAlg; //opnieuw het algoritme; nu in geschikt formaat voor fstream
    bool toevoegen;
};

#endif // INVOEGSCHERM_H
