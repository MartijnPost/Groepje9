#include "tekenveld.h"
#include <QDebug>
#include <QCursor>
#include "knoop.h"

tekenveld::tekenveld() {
    resultaatScherm = false;
    knoopButton = false;
    startknoop = false;
    startknoopButton = false;
    eindknoop = false;
    eindknoopButton = false;
    ongerichtetakButton = false;
    gerichtetakButton = false;
    firstClick = true;
    takPlaced = false;
    eersteKnoop = NULL;
    eindknoopPointer = NULL;
    startknoopPointer = NULL;
}//constructor

void tekenveld::setTextEdits(bool readOnly) {
    QList<QGraphicsItem*> list = items(QRectF(0,0,2000,2000), Qt::IntersectsItemShape, Qt::DescendingOrder, QTransform()); //alle items in het tekenveld
    Knoop *knoop = NULL;
    Tak *tak = NULL;
    while (!list.empty()) { //doorloop de lijst van items
        knoop = NULL;
        tak = NULL;
        if ((knoop = dynamic_cast<Knoop *>(list.front()))) { //als het voorste item in de lijst een knoop betreft
            if(readOnly)
                knoop->pLineEdit->setReadOnly(true);
            else
                knoop->pLineEdit->setReadOnly(false);
        }//if
        else if ((tak = dynamic_cast<Tak *>(list.front()))) { //als het voorste item in de lijst een tak betreft
            if (readOnly)
                tak->pLineEdit->setReadOnly(true);
            else
                tak->pLineEdit->setReadOnly(false);
        }//else if
    list.pop_front(); //item is bekeken, verwijder uit lijst
    }//while
}//setReadOnly

void tekenveld::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
    mousePressEvent(event); //double click also triggers the mousePressEvent function
}

void tekenveld::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Tak *tak = NULL;
    if (!resultaatScherm) {
        qreal x = event->scenePos().x();
        qreal y = event->scenePos().y();
        Knoop *knoop = NULL;
        QList<QGraphicsItem*> list;
        QList<Tak*> takList;
        bool knoopInLijst = false;
        //als de knoopButton aan staat en er op de linkermuisknop is gedrukt en er geen
        //ander object snijdt met de knoop die neergezet gaat worden, voeg knoop toe op deze positie
        if ((event->button() == Qt::LeftButton) &&
        (items(QRectF(x-37.5,y-37.5,75,75), Qt::IntersectsItemShape, Qt::DescendingOrder, QTransform())).empty()) {
            if (knoopButton) { //voeg normale knoop toe
                knoop = new Knoop(x, y, false, false);
                addItem(knoop);
            }//if
            else if (startknoopButton && !startknoop) { //voeg startknoop toe
                startknoop = true;
                knoop = new Knoop(x, y, true, false);
                startknoopPointer = knoop;
                addItem(knoop);
            }//else if
            else if (eindknoopButton && !eindknoop) { //voeg eindknoop toe
                eindknoop = true;
                knoop = new Knoop(x, y, false, true);
                eindknoopPointer = knoop;
                addItem(knoop);
            }//else if
       }//if
       //anders als een takButton aan staat en met de linkermuisknop op een knoop wordt gedrukt
       //en daarna een tweede knoop wordt gedrukt, maak een lijn
       else if ((ongerichtetakButton || gerichtetakButton) && (itemAt(event->scenePos(), QTransform())) &&
       (event->button() == Qt::LeftButton)) {
            //sla eerste knoop op
            if (firstClick) { //stel eerste knoop van tak in
                list = items(event->scenePos(), Qt::IntersectsItemShape, Qt::DescendingOrder, QTransform());
                while (!list.empty() && eersteKnoop == NULL) {
                    eersteKnoop = dynamic_cast<Knoop *>(list.front());
                    if (eersteKnoop != NULL)
                        firstClick = false;
                    else
                        list.pop_front();
                }//while
            }//if
            //maak de tak
            else if (!firstClick) { //stel tweede knoop in
                if (itemAt(event->scenePos(), QTransform())) {
                    list = items(event->scenePos(), Qt::IntersectsItemShape, Qt::DescendingOrder, QTransform());
                    while (!list.empty() && knoop == NULL) {
                        knoop = dynamic_cast<Knoop *>(list.front());
                        if (knoop != NULL)
                            firstClick = false;
                        else
                            list.pop_front();
                    }//while
                    if (knoop != NULL && eersteKnoop != knoop) {
                        if (gerichtetakButton)
                            tak = new Tak(eersteKnoop, knoop, true);
                        else
                            tak = new Tak(eersteKnoop, knoop, false);
                        eersteKnoop->addTak(tak);
                        knoop->addTak(tak);
                        addItem(tak);
                        takPlaced = true;
                        firstClick = true;
                        eersteKnoop = NULL;
                    }//if
                }//while
            }//else
        }//else if
        //anders als er zich een object op de coordinaten (x,y) bevindt en er op de rechtermuisknop gedrukt
        //wordt en de knoopbutton aan staat, verwijder de knoop
        else if (itemAt(event->scenePos(), QTransform()) &&
        (event->button() == Qt::RightButton)) {            
            foreach (QGraphicsItem* item, items(event->scenePos(), Qt::IntersectsItemShape, Qt::DescendingOrder, QTransform())) {
                knoop = dynamic_cast<Knoop *>(item);
                if (knoop != NULL)
                    knoopInLijst = true;           
            }//foreach
            foreach (QGraphicsItem* item, items(event->scenePos(), Qt::IntersectsItemShape, Qt::DescendingOrder, QTransform())) {
                //als het object een knoop is
                knoop = dynamic_cast<Knoop *>(item);
                tak = dynamic_cast<Tak *>(item);
                if (knoop != NULL) {
                    if (knoop->startknoop)
                        startknoop = false;
                    if (knoop->eindknoop)
                        eindknoop = false;
                    if (knoop == eersteKnoop) { //als de knoop die verwijderd wordt, zich op dit moment in de eersteKnoop pointer bevindt
                        eersteKnoop = NULL;
                        firstClick = true;
                    }//if
                    takList = knoop->takken();
                    foreach (Tak *tak, takList) {
                        if (tak != NULL) {
                            tak->source->deleteTakFromList(tak);
                            tak->dest->deleteTakFromList(tak);
                            removeItem(tak);
                            delete tak;
                            tak = NULL;
                        }//if
                    }//foreach
                removeItem(knoop); //verwijder het object
                delete knoop;
                knoop = NULL;
                }//if
                if (tak != NULL) {
                    if (!knoopInLijst) {
                        tak->source->deleteTakFromList(tak);
                        tak->dest->deleteTakFromList(tak);
                        removeItem(tak);
                        delete tak;
                        tak = NULL;                        
                    }//if
                }//if
            }//foreach
        }//else if
     }//if    
     QGraphicsScene::mousePressEvent(event); //needed to retain standard mouse click functionality
     if (takPlaced) { //als er een tak is geplaatst
         takPlaced = false;
         tak->pLineEdit->setFocus(); //zet de focus op de text edit van de tak
     }//if
}//mousePressEvent
