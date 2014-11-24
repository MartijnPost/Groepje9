#include "invoegscherm.h"
#include "ui_invoegscherm.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


InvoegScherm::InvoegScherm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InvoegScherm)
{
    ui->setupUi(this);
    this->setWindowTitle("Invoegscherm");   
}

InvoegScherm::~InvoegScherm()
{
    delete ui;
}

void InvoegScherm::on_Toevoegen_clicked()
{
    QString algName = ui->addAlgBox->text();
    if (algName == "") { //het algoritme moet een naam hebben, mag dus niet leeg zijn
        QMessageBox msgBox;
        msgBox.setText("Vul alstublieft een naam voor het algoritme in");
        msgBox.exec();
    }
    else {            
        //MainWindow::ui->algChoice->addItem(algName);//nieuwe algoritme wordt toegevoegd aan de combobox
        InvoegScherm::close();//function exit program
    }
}

void InvoegScherm::on_Terug_clicked()
{
    InvoegScherm::close();//function exit program
}
