#include "graaf.h"

Graaf::Graaf()
{
    algoritme = 0;
    listEntrance = NULL;
    startknoop = NULL;
    eindknoop = NULL;
    reset_1();
}

void Graaf::reset_1() {
    aantalKnopen = 0;
    aantalTakken = 0;
    stap = 0;
}//reset_1

void Graaf::reset_2() {
    Header* hHelp1 = listEntrance;
    Header* hHelp2 = NULL;
    Element* eHelp1 = NULL;
    Element* eHelp2 = NULL;
    reset_1();
    while (hHelp1 != NULL) {
        eHelp1 = hHelp1->row;
        while (eHelp1 != NULL) {
            eHelp2 = eHelp1->next;
            delete eHelp1;
            eHelp1 = eHelp2;
        }//while
        hHelp2 = hHelp1->next;
        delete hHelp1;
        hHelp1 = hHelp2;
    }//while
    listEntrance = NULL;
}//reset_2

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
        else if(h->knoop == k2 && !t->directed) {
            addToRow(h->row, k1, t);
            aantalTakken++;
        }//else if
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

void Graaf::vul_array( ){
    //stappenArray vullen
    int n = 1;
    Header* hulp = listEntrance;
    stappenArray = new arrayPtr*[aantalKnopen];
    for(int i = 0; i < aantalKnopen; i++)
        stappenArray[i] = new arrayPtr[aantalKnopen];

    for (int i = 0; i < aantalKnopen; i++){
        stappenArray[i][0] = startknoop;
    }//for
    for (int i = 0; i < aantalKnopen; i++){
        stappenArray[i][aantalKnopen-1] = eindknoop;
    }//for
    //Loop de headerijst door
    for (int i = 0; i < aantalKnopen; i++){
        while(hulp != NULL) {
            if(hulp->knoop != startknoop && hulp->knoop != eindknoop){
                n++;
            }//if
            hulp = hulp->next;
        }//while
    }//for

    //stappenWaardes initializeren
    stappenWaardes = new int*[aantalKnopen];
    for(int i = 0; i < aantalKnopen; i++)
        stappenWaardes[i] = new int[aantalKnopen];

    for (int i = 0; i < aantalKnopen; i++){
        for (int j = 1; j < aantalKnopen; j++)
            stappenWaardes[i][j] = INT_MAX;
        stappenWaardes[i][0] = 0;
    }//for
}//vul_array

void Graaf::vul_knopen( ) {
    int n = 1;
    Header* hulp = listEntrance;
    knopen = new knoopPtr[aantalKnopen];    
    knopen[0] = startknoop;
    knopen[aantalKnopen-1] = eindknoop;
    //Loop de headerlijst door
    while(hulp != NULL) {
        if(hulp->knoop != startknoop && hulp->knoop != eindknoop) {
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
    vul_array( );
    afstand = new int[aantalKnopen];
    voorganger = new knoopPtr[aantalKnopen];
    for(int i=0;i<aantalKnopen;i++) {
        afstand[i] = INT_MAX; //Oneindig groot (2147483647 is de max waarde van een int)
        voorganger[i] = knopen[0]; //Eigenlijk NULL, crasht anders soms bij debuggen
    }
    afstand[0] = 0;
    //Kortste pad berekenen
    for(int i=0;i<aantalKnopen-1;i++) {
        for(int j=0;j<aantalTakken;j++) {
            if(afstand[zoek_index(takken[j]->source)] != INT_MAX &&
            (afstand[zoek_index(takken[j]->source)] + takken[j]->pLineEdit->text().toInt()
            < afstand[zoek_index(takken[j]->dest)])) {
                afstand[zoek_index(takken[j]->dest)] =
                afstand[zoek_index(takken[j]->source)] + takken[j]->pLineEdit->text().toInt();
                voorganger[zoek_index(takken[j]->dest)] = takken[j]->source;
                stappenWaardes[i][zoek_index(takken[j]->dest)] =
                afstand[zoek_index(takken[j]->source)] + takken[j]->pLineEdit->text().toInt();
                qDebug() << "Beter stap" << (afstand[zoek_index(takken[j]->source)] + takken[j]->pLineEdit->text().toInt());
            }//if
        }//for
    }//for
    return;
}

void Graaf::vul_kortste_pad( ) {
   //Bereken het aantal knopen op het pad
   int index = zoek_index(eindknoop);
   qDebug() << "Pad lengte: " << afstand[index];
   return;
}

/* * * Bellman-Ford * * */

void Graaf::stapVooruit() {
    if (stap != aantalKnopen-1){
        stap++;
        for (int i = 0; i < aantalKnopen; i++){
            qDebug() << "VooruitKnoop " << i <<" : " <<stappenArray[stap][i];
        }//for
    }//if
}//stapVooruit

void Graaf::stapAchteruit() {
    if (stap != 0){
        stap--;
        for (int i = 0; i < aantalKnopen; i++){
            qDebug() << "AchteruitKnoop " << i <<" : " <<stappenArray[stap][i];
        }//for
    }//if
}//stapAchteruit

void Graaf::stapBegin() {
    stap = 0;
    for (int i = 0; i < aantalKnopen; i++){
        qDebug() << "BeginKnoop " << i <<" : " <<stappenArray[stap][i];
    }//for
}//stapBegin

void Graaf::stapEinde() {
    stap = aantalKnopen-1;
    for (int i = 0; i < aantalKnopen; i++){
        qDebug() << "EindKnoop " << i <<" : " <<stappenArray[stap][i];
    }//for
}//stapEinde

