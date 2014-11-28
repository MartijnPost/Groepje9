#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtWidgets>
#include "tekenveld.h"
#include "resultatenscherm.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    friend class Knoop;
    friend class ResulatenScherm;
    ~MainWindow();

private slots:
    void on_KnoopRadio_toggled(bool checked);

    void on_StartKnoopRadio_toggled(bool checked);

    void on_EindKnoopRadio_toggled(bool checked);

    void on_OngerichteTakRadio_toggled(bool checked);

    void on_GerichteTakRadio_toggled(bool checked);

    void on_StartKnop_clicked();

    void on_InvoegenKnop_clicked();

    void on_AfsluitenKnop_clicked();

    void on_ClearKnop_clicked();

    void on_algChoice_currentIndexChanged(int index);

private:
    ResultatenScherm* r;
    void vulGraafArrays();
    tekenveld *scene;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
