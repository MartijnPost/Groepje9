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
    eersteKnoop = NULL;
}

void tekenveld::setTextEdits(bool readOnly) {
    QList<QGraphicsItem*> list = items(QRectF(160,40,1500,1500), Qt::IntersectsItemShape, Qt::DescendingOrder, QTransform());
    Knoop *knoop = NULL;
    Tak *tak = NULL;
    while (!list.empty()) {
        knoop = dynamic_cast<Knoop *>(list.front());
        if (knoop != NULL) {
            if(readOnly)
                knoop->pLineEdit->setReadOnly(true);
            else
                knoop->pLineEdit->setReadOnly(false);
        }//if
        else {
            tak = dynamic_cast<Tak *>(list.front());
            if (tak != NULL) {
                if (readOnly)
                    tak->pLineEdit->setReadOnly(true);
                else
                    tak->pLineEdit->setReadOnly(false);
            }//if
        }//else
        list.pop_front();
    }//while
}//setReadOnly

void tekenveld::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event) {
    mousePressEvent(event);
}

void tekenveld::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (!resultaatScherm) {
        int x = event->scenePos().x();
        int y = event->scenePos().y();
        Tak *tak = NULL;
        Knoop *knoop = NULL;
        QList<QGraphicsItem*> list;
        QList<Tak*> takList;
        bool knoopInLijst = false;
        //als de knoopButton aan staat en er op de linkermuisknop is gedrukt en er geen
        //ander object snijdt met de knoop die neergezet gaat worden, voeg knoop toe op deze positie
        if ((event->button() == Qt::LeftButton) &&
        (items(QRectF(x-37.5,y-37.5,75,75), Qt::IntersectsItemShape, Qt::DescendingOrder, QTransform())).empty()) {
            if (knoopButton) {
                knoop = new Knoop(x, y, false, false);
                addItem(knoop);
            }//if
            else if (startknoopButton && !startknoop) {
                startknoop = true;
                knoop = new Knoop(x, y, true, false);
                graaf.startknoop = knoop;
                addItem(knoop);
            }//else if
            else if (eindknoopButton && !eindknoop) {
                eindknoop = true;
                knoop = new Knoop(x, y, false, true);
                graaf.eindknoop = knoop;
                addItem(knoop);
            }//else if
            graaf.expandList(knoop, graaf.listEntrance);
        }//if
       //anders als een takButton aan staat en met de linkermuisknop op een knoop wordt gedrukt
       //en daarna een tweede knoop wordt gedrukt, maak een lijn
       else if ((ongerichtetakButton || gerichtetakButton) && (itemAt(event->scenePos(), QTransform())) &&
       (event->button() == Qt::LeftButton))  {
            if (ongerichtetakButton || gerichtetakButton) {
                //sla eerste knoop op
                if (firstClick) {
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
                else if (!firstClick) {
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
                            graaf.expandList(tak, graaf.listEntrance);
                            firstClick = true;
                            eersteKnoop = NULL;
                        }//if
                    }//while
                }//else if
            }//if
        }//else if
        //anders als er zich een object op de coordinaten (x,y) bevindt en er op de rechtermuisknop gedrukt
        //wordt en de knoopbutton aan staat, verwijder de knoop
        else if (itemAt(event->scenePos(), QTransform()) &&
        (event->button() == Qt::RightButton)) {
            list = items(event->scenePos(), Qt::IntersectsItemShape, Qt::DescendingOrder, QTransform());
            while (!list.empty()) {
                knoop = dynamic_cast<Knoop *>(list.front());
                if (knoop != NULL)
                    knoopInLijst = true;
                list.pop_front();
            }//while
            list = items(event->scenePos(), Qt::IntersectsItemShape, Qt::DescendingOrder, QTransform());
            while (!list.empty()) {
                //als het object een knoop is
                knoop = (dynamic_cast<Knoop *>(list.front()));
                tak = (dynamic_cast<Tak *>(list.front()));
                list.pop_front();
                if (knoop != NULL) {
                    if (knoop->startknoop)
                        startknoop = false;
                    if (knoop->eindknoop)
                        eindknoop = false;
                    if (knoop == eersteKnoop) { //als de knoop die verwijderd wordt, zich op dit moment in de eersteKnoop pointer bevindt
                        eersteKnoop = NULL;
                        firstClick = true;
                    }//if
                }//if
                if (knoop != NULL) {
                    takList = knoop->takken();
                    while (!takList.empty()) {
                        if (takList.front() != NULL) {
                            takList.front()->source->deleteTakFromList(takList.front());
                            takList.front()->dest->deleteTakFromList(takList.front());
                            removeItem(takList.front());
                        }//if
                        takList.pop_front();
                    }//while
                    removeItem(knoop); //verwijder het object             
                }//if
                if (tak != NULL) {
                    if (!knoopInLijst) {
                        tak->source->deleteTakFromList(tak);
                        tak->dest->deleteTakFromList(tak);
                        removeItem(tak);
                    }//if
                }//if
            }//while
        }//else if
     }//if
     QGraphicsScene::mousePressEvent(event); //needed to retain standard mouse click functionality
}
