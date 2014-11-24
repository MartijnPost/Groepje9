#include "graaf.h"

Graaf::Graaf()
{
    aantalKnopen = 0;
    aantalTakken = 0;
    algoritme = 0;
    startknoop = NULL;
    eindknoop = NULL;
    listEntrance = NULL;
    for (int i =0; i < 999; i++){
        for(int j =1; j < 999; j++){
            stappenArray[i][j] = 2147483647; //Oneindig groot (2147483647 is de max waarde van een int)
        }//for
        stappenArray[i][0] = 0;//Startknoop heeft altijd een afstand van 0
    }//for
    stap = 0;
}

void Graaf::expandList(Knoop* k, Header*& h) {
    if(h)
        expandList(k, h->next);
    else {
        h = new Header(k);
        aantalKnopen++;
    }
    return;
}

void Graaf::expandList(Tak* t, Header*& h) {
    Knoop *k1, *k2;
    k1 = t->source;
    k2 = t->dest;
    if(h) {
        if(h->knoop == k1) {
            addToRow(h->row, k2, t);
            aantalTakken++;
        }
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

/* * * Bellman-Ford * * */

void Graaf::vul_knopen( ) {
    int n = 1;
    Header* hulp = listEntrance;
    knopen = new knoopPtr[aantalKnopen];
    knopen[0] = startknoop;
    //Loop de headerlijst door
    while(hulp != NULL) {
        if(hulp->knoop != startknoop) {
            knopen[n] = hulp->knoop;
            n++;
        }
        hulp = hulp->next;
    }
    return;
}

void Graaf::vul_takken( ) {
    int n = 0;
    Header* hulp1 = listEntrance;
    Element* hulp2 = NULL;
    takken = new takPtr[aantalTakken];
    //Loop de gehele adjacency list door
    while(hulp1 != NULL) {
        hulp2 = hulp1->row;
        while(hulp2 != NULL) {
            takken[n] = hulp2->tak;
            n++;
            hulp2 = hulp2->next;
        }
        hulp1 = hulp1->next;
    }
    return;
}

void Graaf::verwijder_arrays( ) {
    delete [] knopen;
    delete [] takken;
    delete [] afstand;
    delete [] voorganger;
    return;
}

int Graaf::zoek_index(Knoop* k) const {
    for(int i=0;i<aantalKnopen;i++)
        if(knopen[i] == k)
            return i;
    return -1;
}

void Graaf::BellmanFord( ) {
    //Opschonen
    verwijder_arrays( );
    //Initialiseren
    vul_knopen( );
    vul_takken( );
    afstand = new int[aantalKnopen];
    voorganger = new knoopPtr[aantalKnopen];
    for(int i=0;i<aantalKnopen;i++) {
        afstand[i] = 2147483647; //Oneindig groot (2147483647 is de max waarde van een int)
        voorganger[i] = knopen[0]; //Eigenlijk NULL, crasht anders soms bij debuggen
    }
    afstand[0] = 0;
    //Kortste pad berekenen
    for(int i=0;i<aantalKnopen-1;i++) {
        for(int j=0;j<aantalTakken;j++) {
            if(afstand[zoek_index(takken[j]->source)] + takken[j]->pLineEdit->text().toInt()
            < afstand[zoek_index(takken[j]->dest)]) {
                afstand[zoek_index(takken[j]->dest)] =
                afstand[zoek_index(takken[j]->source)] + takken[j]->pLineEdit->text().toInt();
                voorganger[zoek_index(takken[j]->dest)] = takken[j]->source;
                stappenArray[i][zoek_index(takken[j]->dest)] =
                afstand[zoek_index(takken[j]->source)] + takken[j]->pLineEdit->text().toInt();
            }//if
        }//for
    }//for
    return;
}

void Graaf::vul_kortste_pad( ) {
   //Bereken het aantal knopen op het pad
   int grootte = 1;
   int index = zoek_index(eindknoop);
   while(index != 0) {
       index = zoek_index(voorganger[index]);
       grootte++;
   }
   kortste_pad = new knoopPtr[grootte];
   //Vul het korste pad
   kortste_pad[0] = startknoop;
   kortste_pad[grootte-1] = eindknoop;
   index = zoek_index(eindknoop);
   for(int i=grootte-2;i>0;i--) {
       kortste_pad[i] = voorganger[index];
       index = zoek_index(voorganger[index]);
   }
   //Debugging
   for(int i=0;i<grootte;i++)
       qDebug() << kortste_pad[i]->pLineEdit->text();
   index = zoek_index(eindknoop);
   qDebug() << "Pad lengte: " << afstand[index];
   return;
}

/* * * Bellman-Ford * * */

void Graaf::stapVooruit() {
    if (stap != aantalKnopen-1){
        for (int i = 0; i < aantalKnopen; i++){
            qDebug() << "Knoop " << i <<" : " <<stappenArray[stap][i];
        }//for
        stap++;

    }//if
}//stapVooruit

void Graaf::stapAchteruit() {
    if (stap != 0){
        stap--;
        //TODO
    }//if
}//stapAchteruit

void Graaf::stapBegin() {
    stap = 0;
    //TODO
}//stapBegin

void Graaf::stapEinde() {
    stap = aantalKnopen-1;
    //TODO
}//stapEinde

