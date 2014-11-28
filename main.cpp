#include <iostream>
#include "mainwindow.h"
#include "invoegscherm.h"
#include "resultatenscherm.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow m;
    m.show();
    return a.exec();
}
