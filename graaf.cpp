#include "graaf.h"

Graaf::Graaf()
{
    startknoop = NULL;
    listEntrance = NULL;
}

void Graaf::expandList(Knoop* k, Header*& h) {
    if(h)
        expandList(k, h->next);
    else
        h = new Header(k);
    return;
}

void Graaf::expandList(Tak* t, Header*& h) {
    Knoop *k1, *k2;
    k1 = t->source;
    k2 = t->dest;
    if(h) {
        if(h->knoop == k1)
            addToRow(h->row, k2, t);
        else if(h->knoop == k2 && !t->directed)
            addToRow(h->row, k1, t);
        expandList(t, h->next);
    }
    return;
}

void Graaf::addToRow(Element*& e, Knoop *k, Tak *t) {
    if(e)
        addToRow(e->next, k, t);
    else
        e = new Element(k, t);
    return;
}


void Graaf::writeToDebug(Header *h) const {
    if(h){
        qDebug() << "Grenzend aan knoop " << h->knoop->pLineEdit->text() << ":";
        writeToDebug(h->row);
        writeToDebug(h->next);
    }
    return;
}

void Graaf::writeToDebug(Element *e) const {
    if(e) {
        qDebug() << "  knoop" << e->knoop->pLineEdit->text()
                 << "met gewicht" << e->tak->pLineEdit->text();
        writeToDebug(e->next);
    }
    return;
}
