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
    qreal midX;
    qreal midY;
    friend class tekenveld;
    friend class Graaf;  
    friend class Knoop;
    friend class ResultatenScherm;
    friend class MainWindow;
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
    void calcCoordinates();
    void placeTextBox();
    bool paintRed;
    bool paintBlue;
    bool paintPurple;
};

#endif
