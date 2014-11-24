#include "resultatenscherm.h"
#include "ui_resultatenscherm.h"

ResultatenScherm::ResultatenScherm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ResultatenScherm)
{
    ui->setupUi(this);    
    this->setWindowTitle("Resultatenscherm");
    setFixedSize(1150,760); //zet grootte vast
}

ResultatenScherm::~ResultatenScherm()
{
    delete ui;
}

void ResultatenScherm::setScene(tekenveld* graaf) {
    scene = graaf; //kopieer het tekenveld van de mainwindow
    scene->setSceneRect(160,40,1500,1500); //zet tekenveld vast
    ui->tekenVeld->setScene(scene);
}

void ResultatenScherm::on_Begin_clicked()
{
    scene->tekenveld->graaf->stapVooruit();
}

void ResultatenScherm::on_Vorige_clicked()
{

}

void ResultatenScherm::on_Volgende_clicked()
{

}

void ResultatenScherm::on_Einde_clicked()
{

}

void ResultatenScherm::on_Upload_clicked()
{

}

void ResultatenScherm::on_Stop_clicked()
{
    ResultatenScherm::close();//function exit program
}
