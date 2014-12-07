#include "invoegscherm.h"
#include "ui_invoegscherm.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <fstream>
#include <string>


InvoegScherm::InvoegScherm(QWidget *parent) : QDialog(parent), ui(new Ui::InvoegScherm)
{
    ui->setupUi(this);
    this->setWindowTitle("Invoegscherm");
    algName = "";
    eigenAlg = "";
    toevoegen = false;
}

InvoegScherm::~InvoegScherm()
{
    delete ui;
}

void InvoegScherm::updateGraaf() { //het algoritme wordt achter bestaande tekst in graaf.cpp geplakt
    std::ofstream updateFile;
    updateFile.open("graaf.cpp", std::ofstream::out | std::ofstream::app);
    eigenAlg = eigenAlgQ.toStdString();
    updateFile << "\r\n\r\n void Graaf::eigenAlgoritme() {\r\n" << eigenAlg << "\r\n}";
}

void InvoegScherm::on_Toevoegen_clicked()
{
    algName = ui->addAlgBox->text();
    eigenAlgQ = ui->insertAlg->toPlainText();
    if (algName == "") { //het algoritme moet een naam hebben, mag dus niet leeg zijn
        QMessageBox msgBox;
        msgBox.setText("Vul alstublieft een naam voor het algoritme in");
        msgBox.exec();
    }//if
    else if (eigenAlgQ == "") {//er moet natuurlijk ook een algoritme worden ingevuld
        QMessageBox msgBox;
        msgBox.setText("Vul alstublieft een algoritme in");
        msgBox.exec();
    }//else
    else {
        toevoegen = true;
        updateGraaf(); //voegt het algoritme toe aan graaf.cpp
        InvoegScherm::close();//function exit program
    }//else
}//on_Toevoegen_clicked

void InvoegScherm::on_Terug_clicked()
{
    toevoegen = false;
    InvoegScherm::close();//function exit program
}//on_Terug_clicked
