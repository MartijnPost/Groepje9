#include "tak.h"
#include "knoop.h"
#include <math.h>
#include <QPainter>

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

Tak::Tak(Knoop *sourceNode, Knoop *destNode, bool directedEdge)
{
    source = sourceNode;
    dest = destNode;
    directed = directedEdge;
    sourcePoint.setX(source->x);
    sourcePoint.setY(source->y);
    destPoint.setX(dest->x);
    destPoint.setY(dest->y);
    qDebug() << sourcePoint;
    arrowSize = 10; // TODO : grootte van zijkant van de pijl maken
    line.setLine(source->x, source->y, dest->x, dest->y);
    //gewicht van de tak meegeven
    //voeg toe aan adjancency list
}

QRectF Tak::boundingRect() const
{
    if (source->x > dest->x) {
        if (source->y > dest->y)
            return QRectF(dest->x-10, dest->y-10, abs(source->x-dest->x)+20, abs(source->y-dest->y)+20);
        else
            return QRectF(dest->x-10, source->y-10, abs(source->x-dest->x)+20, abs(source->y-dest->y)+20);
    }//if
    else {
        if (source->y > dest->y)
            return QRectF(source->x-10, dest->y-10, abs(source->x-dest->x)+20, abs(source->y-dest->y)+20);
        else
            return QRectF(source->x-10, source->y-10, abs(source->x-dest->x)+20, abs(source->y-dest->y)+20);
    }//else
}

QPainterPath Tak::shape() const
{
    QPainterPath path;
    QPolygon polygon;    
    polygon << QPoint(source->x-5, source->y-5);
    polygon << QPoint(source->x+5, source->y+5);
    polygon << QPoint(dest->x+5, dest->y+5);
    polygon << QPoint(dest->x-5, dest->y-5);
    polygon << QPoint(source->x-5, source->y-5);
    path.addPolygon(polygon);
    return path; // return the item's defined shape
}

void Tak::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget)
{
    //teken de lijn
    QPen paintpen(Qt::black); //de pen waarmee de knoop getekend wordt, is zwart
    paintpen.setWidth(2); //de dikte van de pen is 1

    painter->setPen(paintpen); //de pen waarmee getekend gaat worden is paintpen
    painter->setRenderHint(QPainter::Antialiasing); //er wordt AA gebruikt om de knoop mooier te maken
    painter->drawLine(sourcePoint, destPoint);
    //teken de zijkant van de pijl
    if (directed) {
        double angle = ::acos(line.dx() / line.length());
        if (line.dy() >= 0)
            angle = TwoPi - angle;
        QPointF destArrowP1 = destPoint + QPointF(sin(angle - Pi / 3) * arrowSize,
                                                  cos(angle - Pi / 3) * arrowSize);
        QPointF destArrowP2 = destPoint + QPointF(sin(angle - Pi + Pi / 3) * arrowSize,
                                                  cos(angle - Pi + Pi / 3) * arrowSize);
        painter->setBrush(Qt::black);
        painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);
    }//if
}

void Tak::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug("test");
}
