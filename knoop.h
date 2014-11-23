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
    Knoop( );
    Knoop(const int xPos, const int yPos, bool start, bool eind); //constructor
    int x; //x-coordinaat
    int y; //y-coordinaat    
    friend class Graaf;
    friend class tekenveld;
private:
    bool startknoop; //true als de knoop een startknoop is
    bool eindknoop; //true als de knoop een eindknoop is
    QList<Tak *> takken() const;//geeft takkenlijst
    QList<Tak *> takkenList;//taklijst met alle takken    Q
    QRectF boundingRect() const; //vorm van de knoop
    QLineEdit *pLineEdit; //text box voor naamgeving
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //tekent de knoop
    void addTak(Tak *tak);//voegt tak toe aan taklijst
    void deleteTakFromList(Tak* tak);
    QGraphicsProxyWidget* pMyProxy; //nodig om de text box weer te geven
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event); //wordt aangeroepen bij een muisklik op de knoop
};

#endif // KNOOP_H
