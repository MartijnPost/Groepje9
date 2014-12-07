#include "knoop.h"
#include "tak.h"

Knoop::Knoop(const qreal xPos, const qreal yPos, bool start, bool eind)
{
    xHuidig = xPos; //de x-coordinaat van de knoop
    xStart = xPos;
    yHuidig = yPos; //de y-coordinaat van de knoop
    yStart = yPos;
    startknoop = start;    //deze zijn later nodig om takken te tekenen
    eindknoop = eind;
    paintGreen = false;
    pLineEdit = new QLineEdit("");
    pLineEdit->setMaxLength(6); //er kunnen maximaal 6 karakters in de text box geplaatst worden
    pLineEdit->setFixedSize(70, 20); //de grootte van de text box
    pLineEdit->setAlignment(Qt::AlignHCenter); //de tekst staat in het midden van de knoop
    pLineEdit->setStyleSheet("QLineEdit{background: transparent; border: none;}");
    pMyProxy = new QGraphicsProxyWidget(this); // the proxy's parent is the 2d object
    pMyProxy->setWidget(pLineEdit); //voeg de text box toe
    pMyProxy->moveBy(xStart-35,yStart-10); //zet de text box op de juiste positie in het tekenveld
    lengteTekst = new QLineEdit(""); //nieuwe tekst box om de actuele afstanden per knoop weer te geven
    lengteTekst->setReadOnly(true); //tekst mag natuurlijk niet veranderd worden door de gebruiker zelf
    lengteTekst->setAlignment(Qt::AlignHCenter); //de tekst staat in het midden van de knoop
    lengteTekst->setStyleSheet("QLineEdit{background: transparent; border: none; color: black; font-weight: bold;}");
    lengteTekst->setFixedSize(70, 20); //de grootte van de text box
    lengteWidget = new QGraphicsProxyWidget(this); // the proxy's parent is the 2d object
    lengteWidget->setWidget(lengteTekst); //voeg de text box toe
    lengteWidget->moveBy(xStart-35,yStart-30); //zet de text box op de juiste positie in het tekenveld
    setFlag(ItemIsMovable);
    setFlag(ItemSendsGeometryChanges);
}//constructor

QVariant Knoop::itemChange(GraphicsItemChange change, const QVariant &value) {
    if (change == ItemPositionChange) {
        prepareGeometryChange();
        xHuidig = xStart + value.toPointF().x();
        yHuidig = yStart + value.toPointF().y();
        foreach (Tak *tak, takkenList) {
           tak->pMyProxy->update();
           tak->calcCoordinates();
           tak->boundingRect();
           tak->placeTextBox();
           tak->update();
        }
    }//if
    return QGraphicsItem::itemChange(change, value);
}

void Knoop::addTak(Tak *tak)
{
    takkenList << tak;
}

QList<Tak *> Knoop::takken() const
{
    return takkenList;
}

void Knoop::deleteTakFromList(Tak* tak) {
    takkenList.removeOne(tak);
}//deleteTakFromList

QRectF Knoop::boundingRect() const
{
    if (startknoop)
        return QRectF(xStart-75,yStart-37.5,115,75); //maak cirkel aan
    else
        return QRectF(xStart-37.5,yStart-37.5,75,75); //maak cirkel aan
}//boundingRect

void Knoop::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
QWidget *widget)
{
    QPen paintpen(Qt::black); //de pen waarmee de knoop getekend wordt, is zwart
    if (paintGreen)
        paintpen.setColor("limegreen");
    paintpen.setWidth(1); //de dikte van de pen is 1
    painter->setPen(paintpen); //de pen waarmee getekend gaat worden is paintpen
    painter->setRenderHint(QPainter::Antialiasing); //er wordt AA gebruikt om de knoop mooier te maken
    painter->drawEllipse(QRectF(xStart-37.5,yStart-37.5,75,75)); //de knoop wordt getekend
    if (startknoop) { //als het een startknoop betreft, teken een pijl naar de cirkel
        painter->drawLine(xStart-75, yStart, xStart-37.5, yStart);
        painter->drawLine(xStart-45, yStart-6, xStart-37.5, yStart);
        painter->drawLine(xStart-45, yStart+6, xStart-37.5, yStart);
    }//if
    if (eindknoop) //als het een eindknoop betreft, teken een 2e kleinere cirkel
        painter->drawEllipse(QRectF(xStart-32.5,yStart-32.5,65,65)); //teken de cirkel
}//paint

void Knoop::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event); // move the item...
}//mouseMoveEvent
