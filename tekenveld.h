#ifndef TEKENVELD_H
#define TEKENVELD_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "graaf.h"


class tekenveld : public QGraphicsScene
{
public:
    tekenveld();
    bool knoopButton; //true als de radiobutton "knoop" aan staat
    bool startknoopButton; //true als de radiobutton "start knoop" aan staat
    bool eindknoopButton; //true als de radiobutton "eind knoop" aan staat
    bool ongerichtetakButton; //true als de radiobutton "ongerichte tak" aan staat
    bool gerichtetakButton; //true als de radiobutton "gerichte tak" aan staat
    bool firstClick; //nodig om takken te tekenen om te weten tussen welke twee knopen een tak komt
    bool resultaatScherm; //true als het om de graphicsScene in het resultaatscherm gaat
    void vulGraafArrays();
    void setTextEdits(bool readOnly);
    Graaf graaf;
    friend class Knoop;
    friend class MainWindow;
private:
    bool startknoop; //true als er een startknoop voor komt in de graaf
    bool eindknoop; //true als er een eindknoop voor komt in de graaf
    Knoop *eersteKnoop;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event); //wordt aangeroepen bij een muisklik op het tekenveld
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event); //wordt aangeroepen bij een muisklik op het tekenveld
};

#endif // TEKENVELD_H
