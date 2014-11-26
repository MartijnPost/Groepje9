#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "invoegscherm.h"
#include "resultatenscherm.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->algChoice->setEditable(true);
    ui->algChoice->lineEdit()->setReadOnly(true);
    ui->algChoice->lineEdit()->setAlignment(Qt::AlignCenter);
    this->setWindowTitle("Hoofdscherm");    
    scene = new tekenveld();
    scene->setSceneRect(0,0,2000,2000); //nodig om het tekenveld 'vast' te zetten
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_KnoopRadio_toggled(bool checked)
{
    if (checked)
        scene->knoopButton = true;
    else
        scene->knoopButton = false;
}

void MainWindow::on_StartKnoopRadio_toggled(bool checked)
{
    if (checked)
        scene->startknoopButton = true;
    else
        scene->startknoopButton = false;
}

void MainWindow::on_EindKnoopRadio_toggled(bool checked)
{
    if (checked)
        scene->eindknoopButton = true;
    else
        scene->eindknoopButton = false;
}

void MainWindow::on_OngerichteTakRadio_toggled(bool checked)
{
    if (checked)
        scene->ongerichtetakButton = true;
    else
        scene->ongerichtetakButton = false;
}

void MainWindow::on_GerichteTakRadio_toggled(bool checked)
{
    if (checked)
        scene->gerichtetakButton = true;
    else
        scene->gerichtetakButton = false;
}

void MainWindow::on_StartKnop_clicked()
{    
    //function open algoritme doorloop schermpje
    if (scene->startknoop && scene->eindknoop) {
        scene->resultaatScherm = true; //resultaatscherm gaat geopend worden
        scene->vulGraafArrays();
        hide(); //verberg hoofdscherm
        ResultatenScherm* r = new ResultatenScherm(); //maak nieuw resultaatscherm aan
        scene->setTextEdits(true);
        r->setScene(scene); //kopieer het tekenveld van het hoofdscherm en plaats in resultaatscherm
        if (r->scene->graaf.algoritme == 0) {
            r->scene->graaf.Dijkstra();
            r->scene->graaf.vul_kortste_pad();
        }
        else if (r->scene->graaf.algoritme == 1) {
            r->scene->graaf.BellmanFord();
            r->scene->graaf.vul_kortste_pad();
        }
        r->setModal(true);
        r->exec(); //open het resultaatscherm.
        for (int i = 0; i < r->scene->graaf.aantalTakken; i++) {
            r->scene->graaf.takken[i]->paintRed = false;
            r->scene->graaf.takken[i]->update();
        }//for
        for (int i = 0; i < r->scene->graaf.aantalKnopen; i++) {
            r->scene->graaf.knopen[i]->paintGreen = false;
        }
        delete r;
        r = NULL;
        scene->setTextEdits(false);
        show(); //als het resultaatscherm wordt afgesloten, toon het hoofdscherm
        scene->resultaatScherm = false; //resultaatscherm is afgesloten
    }//if
}

void MainWindow::on_InvoegenKnop_clicked()
{
    InvoegScherm i;
    i.setModal(true);
    i.exec();
}

void MainWindow::on_AfsluitenKnop_clicked()
{
    MainWindow::close();//function exit program
}

void MainWindow::on_ClearKnop_clicked()
{
    scene->clear();
    scene->startknoop = false;
    scene->eindknoop = false;
}

void MainWindow::on_algChoice_currentIndexChanged(int index)
{
    scene->graaf.algoritme = index;
    qDebug() << index;
}
