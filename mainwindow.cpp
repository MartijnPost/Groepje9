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
    r = new ResultatenScherm(); //maak nieuw resultaatscherm aan
    r->setModal(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::vulGraafArrays() {
    QList<QGraphicsItem*> list = scene->items(QRectF(0,0,2000,2000), Qt::IntersectsItemShape, Qt::DescendingOrder, QTransform());
    Knoop* knoop = NULL;
    Tak* tak = NULL;
    r->graaf.reset();
    if (scene->startknoop && scene->eindknoop) {
        r->graaf.startknoop = scene->startknoopPointer;
        r->graaf.eindknoop = scene->eindknoopPointer;
        foreach (QGraphicsItem* item, list) {
            if ((knoop = dynamic_cast<Knoop *>(item)))
                r->graaf.expandList(knoop, r->graaf.listEntrance);
        }//foreach
        foreach (QGraphicsItem* item, list) {
            if ((tak = dynamic_cast<Tak *>(item)))
                r->graaf.expandList(tak, r->graaf.listEntrance);
        }//foreach
    }//if
}//vulGraafArrays

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
        vulGraafArrays();
        hide(); //verberg hoofdscherm
        scene->setTextEdits(true);
        r->setScene(scene); //kopieer het tekenveld van het hoofdscherm en plaats in resultaatscherm
        if (r->graaf.algoritme == 0) {
            r->graaf.Dijkstra();
            r->graaf.vul_kortste_pad();
        }
        else if (r->graaf.algoritme == 1) {
            r->graaf.BellmanFord();
            r->graaf.vul_kortste_pad();
        }
        r->exec(); //open het resultaatscherm.
        for (int i = 0; i < r->graaf.aantalTakken; i++) {
            r->graaf.takken[i].tak->paintRed = false;
            r->graaf.takken[i].tak->paintBlue = false;
            r->graaf.takken[i].tak->paintPurple = false;
            r->graaf.takken[i].tak->update();
        }//for
        for (int i = 0; i < r->graaf.aantalKnopen; i++) {
            r->graaf.knopen[i]->paintGreen = false;
        }
        scene->setTextEdits(false);
        show(); //als het resultaatscherm wordt afgesloten, toon het hoofdscherm
        scene->resultaatScherm = false; //resultaatscherm is afgesloten
    }//if
}//on_Startknop_clicked

void MainWindow::on_InvoegenKnop_clicked()
{
    InvoegScherm i;
    i.setModal(true);
    i.exec();
}

void MainWindow::on_AfsluitenKnop_clicked()
{
    r = NULL;
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
    r->graaf.algoritme = index;
    qDebug() << index;
}
