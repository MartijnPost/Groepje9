#ifndef KNOOP_H
#define KNOOP_H
#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>
#include <QGraphicsProxyWidget>
#include <QLineEdit>
#include <QList>
#include <QVariant>
#include <QGraphicsSceneMouseEvent>

class Graaf;
class Tak;

class Knoop : public QGraphicsItem
{
public:
    Knoop(const qreal xPos, const qreal yPos, bool start, bool eind); //constructor
    qreal xStart;
    qreal yStart;
    qreal xHuidig; //x-coordinaat
    qreal yHuidig; //y-coordinaat    
    friend class Graaf;
    friend class tekenveld;
    friend class MainWindow;
private:
    bool startknoop; //true als de knoop een startknoop is
    bool eindknoop; //true als de knoop een eindknoop is
    bool paintGreen; //true wanneer de kleur van de pen groen moet zijn
    QList<Tak *> takken() const;//geeft takkenlijst
    QList<Tak *> takkenList;//taklijst met alle takken    Q
    QRectF boundingRect() const; //vorm van de knoop
    QLineEdit *pLineEdit; //text box voor naamgeving
    QLineEdit *lengteTekst; //text box voor de afstand per knoop
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //tekent de knoop
    void addTak(Tak *tak);//voegt tak toe aan taklijst
    void deleteTakFromList(Tak* tak);
    QGraphicsProxyWidget* pMyProxy; //nodig om de text box weer te geven
    QGraphicsProxyWidget* lengteWidget; //nodig om de text box weer te geven
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event); //wordt aangeroepen bij een muisklik op de knoop
};

#endif // KNOOP_H
