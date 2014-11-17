#ifndef KNOOP_H
#define KNOOP_H
#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>
#include <QGraphicsProxyWidget>
#include <QLineEdit>
#include <QList>

class Graaf;
class Tak;

class Knoop : public QGraphicsItem
{
public:
    void addTak(Tak *tak);//voegt tak toe aan taklijst
    QList<Tak *> takken() const;//geeft takkenlijst
    Knoop(const int xPos, const int yPos, bool start, bool eind); //constructor
    QRectF boundingRect() const; //vorm van de knoop
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //tekent de knoop
    int x; //x-coordinaat
    int y; //y-coordinaat
    bool startknoop; //true als de knoop een startknoop is
    bool eindknoop; //true als de knoop een eindknoop is
    friend class Graaf;
private:    
    QList<Tak *> takkenList;//taklijst met alle takken
    QLineEdit *pLineEdit; //text box voor naamgeving
    QGraphicsProxyWidget* pMyProxy; //nodig om de text box weer te geven
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event); //wordt aangeroepen bij een muisklik op de knoop
};

#endif // KNOOP_H
