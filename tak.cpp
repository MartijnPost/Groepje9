#include "tak.h"
#include "knoop.h"
#include <math.h>
#include <QPainter>
#include <QIntValidator>

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

Tak::Tak(Knoop *sourceNode, Knoop *destNode, bool directedEdge)
{
    source = sourceNode;
    dest = destNode;
    directed = directedEdge;
    double x1 = source->x;
    double x2 = dest->x;
    double y1 = source->y;
    double y2 = dest->y;
    double dX = abs(x2-x1);
    double dY = abs(y2-y1);
    double hoek1 = atan(dY/dX) * 180 / Pi;//hoek source cirkel
    double hoek2 = 90 - hoek1;//hoek dest cirkel
    double convertToDegrees = Pi / 180.0;
    /* Eerste kwadrant */
    if (x1 < x2 && y1 > y2){
        sourcePoint.setX(x1+(cos(hoek1 * convertToDegrees)*37.5));
        sourcePoint.setY(y1-(sin(hoek1 * convertToDegrees)*37.5));
        destPoint.setX(x2-(sin(hoek2 * convertToDegrees)*37.5));
        destPoint.setY(y2+(cos(hoek2 * convertToDegrees)*37.5));
    }//if
    /* Tweede kwadrant */
    if (x1 < x2 && y1 < y2){
        sourcePoint.setX(x1+(sin(hoek2 * convertToDegrees)*37.5));
        sourcePoint.setY(y1+(cos(hoek2 * convertToDegrees)*37.5));
        destPoint.setX(x2-(cos(hoek1 * convertToDegrees)*37.5));
        destPoint.setY(y2-(sin(hoek1 * convertToDegrees)*37.5));
    }//if
    /* Derde kwadrant */
    if (x1 > x2 && y1 > y2){
        sourcePoint.setX(x1-(cos(hoek1 * convertToDegrees)*37.5));
        sourcePoint.setY(y1-(sin(hoek1 * convertToDegrees)*37.5));
        destPoint.setX(x2+(sin(hoek2 * convertToDegrees)*37.5));
        destPoint.setY(y2+(cos(hoek2 * convertToDegrees)*37.5));
    }//if
    /* Vierde kwadrant */
    if (x1 > x2 && y1 < y2){
        sourcePoint.setX(x1-(sin(hoek2 * convertToDegrees)*37.5));
        sourcePoint.setY(y1+(cos(hoek2 * convertToDegrees)*37.5));
        destPoint.setX(x2+(cos(hoek1 * convertToDegrees)*37.5));
        destPoint.setY(y2-(sin(hoek1 * convertToDegrees)*37.5));
    }//if
    /* Boven elkaar */
    if (x1 == x2 && y1 < y2){
        sourcePoint.setX(x1);
        sourcePoint.setY(y1+37.5);
        destPoint.setX(x2);
        destPoint.setY(y2-37.5);
    }//if
    if (x1 == x2 && y1 > y2){
        sourcePoint.setX(x1);
        sourcePoint.setY(y1-37.5);
        destPoint.setX(x2);
        destPoint.setY(y2+37.5);
    }//if
    /* Naast elkaar */
    if (x1 > x2 && y1 == y2){
        sourcePoint.setX(x1-37.5);
        sourcePoint.setY(y1);
        destPoint.setX(x2+37.5);
        destPoint.setY(y2);
    }//if
    if (x1 < x2 && y1 == y2){
        sourcePoint.setX(x1+37.5);
        sourcePoint.setY(y1);
        destPoint.setX(x2-37.5);
        destPoint.setY(y2);
    }//if   
    line.setLine(source->x, source->y, dest->x, dest->y);
    //voeg toe aan adjancency list
    pLineEdit = new QLineEdit("");
    pLineEdit->setMaxLength(3); //er kunnen maximaal 3 karakters in de text box geplaatst worden
    pLineEdit->setFixedSize(40, 20); //de grootte van de text box
    pLineEdit->setStyleSheet("QLineEdit{background: transparent; }");//border: none;
    pLineEdit->setValidator(new QIntValidator);
    pMyProxy = new QGraphicsProxyWidget(this); // the proxy's parent is the 2d object
    pMyProxy->setWidget(pLineEdit); //voeg de text box toe
    midX = (source->x + dest->x)/2; //berekene de X-coördinaat het midden van de lijn
    midY = (source->y + dest->y)/2; //berekene de Y-coördinaat het midden van de lijn
    if((dest->x >= source->x && dest->x >= source->y) || (dest->x < source->x && dest->x < source->y)) //lijn als y=x
        pMyProxy->moveBy(midX-20,midY-30); //zet de text box rechts boven het midden van de lijn
    if((dest->x >= source->x && dest->x < source->y) || (dest->x < source->x && dest->x >= source->y)) //lijn als y=-x
        pMyProxy->moveBy(midX-30,midY-30); //zet de text box links boven het midden van de lijn
}

Tak::~Tak()
{
    delete pLineEdit;
}

QRectF Tak::boundingRect() const
{
    if (sourcePoint.x() > destPoint.x()) {
        if (sourcePoint.y() > destPoint.y())
            return QRectF(destPoint.x()-10, destPoint.y()-10, abs(sourcePoint.x()-destPoint.x())+20, abs(sourcePoint.y()-destPoint.y())+20);
        else
            return QRectF(destPoint.x()-10, sourcePoint.y()-10, abs(sourcePoint.x()-destPoint.x())+20, abs(sourcePoint.y()-destPoint.y())+20);
    }//if
    else {
        if (sourcePoint.y() > destPoint.y())
            return QRectF(sourcePoint.x()-10, destPoint.y()-10, abs(sourcePoint.x()-destPoint.x())+20, abs(sourcePoint.y()-destPoint.y())+20);
        else
            return QRectF(sourcePoint.x()-10, sourcePoint.y()-10, abs(sourcePoint.x()-destPoint.x())+20, abs(sourcePoint.y()-destPoint.y())+20);
    }//else
}

QPainterPath Tak::shape() const
{
    QPainterPath path;
    QPolygon polygon;
    if (abs(sourcePoint.x() - destPoint.x()) > abs(sourcePoint.y() - destPoint.y())) {
        polygon << QPoint(sourcePoint.x(), sourcePoint.y()-10);
        polygon << QPoint(sourcePoint.x(), sourcePoint.y()+10);
        polygon << QPoint(dest->x, destPoint.y()+10);
        polygon << QPoint(dest->x, destPoint.y()-10);
        polygon << QPoint(sourcePoint.x(), sourcePoint.y()-10);
    }//if
    else {
        polygon << QPoint(sourcePoint.x()-10, sourcePoint.y());
        polygon << QPoint(sourcePoint.x()+10, sourcePoint.y());
        polygon << QPoint(destPoint.x()+10, destPoint.y());
        polygon << QPoint(destPoint.x()-10, destPoint.y());
        polygon << QPoint(sourcePoint.x()-10, sourcePoint.y());
    }
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
        qreal arrowSize = 10; //grootte van de pijl
        double angle = ::acos(line.dx() / line.length());
        if (line.dy() >= 0)
            angle = TwoPi - angle;
        QPointF destArrowP1 = destPoint + QPointF(sin(angle - Pi / 3) * arrowSize,
                                                  cos(angle - Pi / 3) * arrowSize);
        QPointF destArrowP2 = destPoint + QPointF(sin(angle - Pi + Pi / 3) * arrowSize,
                                                  cos(angle - Pi + Pi / 3) * arrowSize);
        painter->setBrush(Qt::black);
        painter->drawPolygon(QPolygonF() << destPoint << destArrowP1 << destArrowP2);
    }//if
}

void Tak::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug("tak");
}
