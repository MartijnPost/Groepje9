#include "knoop.h"
#include "tak.h"

Knoop::Knoop(const int xPos, const int yPos, bool start, bool eind)
{
    x = xPos; //de x-coordinaat van de knoop
    y = yPos; //de y-coordinaat van de knoop
    startknoop = start;    //deze zijn later nodig om takken te tekenen
    eindknoop = eind;
    pLineEdit = new QLineEdit("");
    pLineEdit->setMaxLength(6); //er kunnen maximaal 6 karakters in de text box geplaatst worden
    pLineEdit->setFixedSize(70, 20); //de grootte van de text box
    pLineEdit->setAlignment(Qt::AlignHCenter); //de tekst staat in het midden van de knoop
    pLineEdit->setStyleSheet("QLineEdit{background: transparent; border: none;}");
    pMyProxy = new QGraphicsProxyWidget(this); // the proxy's parent is the 2d object
    pMyProxy->setWidget(pLineEdit); //voeg de text box toe
    pMyProxy->moveBy(x-35,y-10); //zet de text box op de juiste positie in het tekenveld
}

void Knoop::addTak(Tak *tak)
{
    takkenList << tak;
}

QList<Tak *> Knoop::takken() const
{
    return takkenList;
}

QRectF Knoop::boundingRect() const
{    
    if (startknoop)
        return QRectF(x-75,y-37.5,115,75); //maak cirkel aan
    else
        return QRectF(x-37.5,y-37.5,75,75); //maak cirkel aan
}

void Knoop::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
QWidget *widget)
{    
    QPen paintpen(Qt::black); //de pen waarmee de knoop getekend wordt, is zwart
    paintpen.setWidth(1); //de dikte van de pen is 1

    painter->setPen(paintpen); //de pen waarmee getekend gaat worden is paintpen
    painter->setRenderHint(QPainter::Antialiasing); //er wordt AA gebruikt om de knoop mooier te maken
    painter->drawEllipse(QRectF(x-37.5,y-37.5,75,75)); //de knoop wordt getekend
    if (startknoop) { //als het een startknoop betreft, teken een pijl naar de cirkel
        painter->drawLine(x-75, y, x-37.5, y);
        painter->drawLine(x-45, y-6, x-37.5, y);
        painter->drawLine(x-45, y+6, x-37.5, y);
    }
    if (eindknoop) //als het een eindknoop betreft, teken een 2e kleinere cirkel
        painter->drawEllipse(QRectF(x-32.5,y-32.5,65,65)); //teken de cirkel
}

void Knoop::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    qDebug() << pLineEdit->text(); //print tekst in knoop
    qDebug() << x << "," << y; //print x- en y-coordinaat
}
