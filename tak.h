#ifndef TAK_H
#define TAK_H

#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>
#include <QGraphicsProxyWidget>
#include <QLineEdit>
#include <QList>
#include <QPoint>

class Knoop;

class Tak : public QGraphicsItem
{
public:
    Tak(Knoop *sourceKnoop, Knoop *destKnoop, bool directedEdge);//constructor
    ~Tak();    
    int midX;
    int midY;
    friend class tekenveld;
    friend class Graaf;
private:
    Knoop *source, *dest;//de begin en eindknoop
    QLineF line;
    QPoint sourcePoint;
    QPoint destPoint;
    bool directed;
    QGraphicsProxyWidget* pMyProxy; //nodig om de text box weer te geven
    QLineEdit *pLineEdit; //text box voor naamgeving
    QRectF boundingRect() const;//bepaalt grootte van de pijl
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);//tekent de pijl
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event); //wordt aangeroepen bij een muisklik op de knoop
};

#endif
