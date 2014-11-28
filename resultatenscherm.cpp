#include "resultatenscherm.h"
#include "ui_resultatenscherm.h"

ResultatenScherm::ResultatenScherm(QWidget *parent) : QDialog(parent),
    ui(new Ui::ResultatenScherm)
{
    ui->setupUi(this);
    this->setWindowTitle("Resultatenscherm");
}

ResultatenScherm::~ResultatenScherm()
{
    delete ui;
}

void ResultatenScherm::setScene(tekenveld* graaf) {
    scene = graaf; //kopieer het tekenveld van de mainwindow
    scene->setSceneRect(0,0,2000,2000); //zet tekenveld vast
    ui->tekenVeld->setScene(scene);
}

void ResultatenScherm::on_Begin_clicked()
{
   graaf.stapBegin();
}

void ResultatenScherm::on_Vorige_clicked()
{
    qDebug() << "vorige" << graaf.stap;
    graaf.stapAchteruit();
}

void ResultatenScherm::on_Volgende_clicked()
{
    qDebug() << "volgende" << graaf.stap;
    graaf.stapVooruit();
}

void ResultatenScherm::on_Einde_clicked()
{
    graaf.stapEinde();
}

void ResultatenScherm::on_Upload_clicked()
{

}

void ResultatenScherm::on_Stop_clicked()
{
    graaf.verwijderAfstanden();
    ResultatenScherm::close();//function exit program
}
