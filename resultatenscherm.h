#ifndef RESULTATENSCHERM_H
#define RESULTATENSCHERM_H

#include <QDialog>
#include <QtCore>
#include <QtWidgets>
#include "tekenveld.h"

namespace Ui {
class ResultatenScherm;
}

class ResultatenScherm : public QDialog
{
    Q_OBJECT

public:
    explicit ResultatenScherm(QWidget *parent = 0);
    ~ResultatenScherm();
    void setScene(tekenveld *graaf);
    friend class MainWindow;
private slots:
    void on_Begin_clicked();

    void on_Vorige_clicked();

    void on_Volgende_clicked();

    void on_Einde_clicked();

    void on_Upload_clicked();

    void on_Stop_clicked();

private:    
    tekenveld *scene;
    Ui::ResultatenScherm *ui;    
};

#endif // RESULTATENSCHERM_H
