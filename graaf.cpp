#include "graaf.h"

Graaf::Graaf()
{
    algoritme = 0;
    listEntrance = NULL;
    startknoop = NULL;
    eindknoop = NULL;
    voorganger = NULL;
    knopen = NULL;
    takken = NULL;
    kortste_pad = NULL;
    vastGezet = NULL;
    stappenWaardes = NULL;
    stappenArray = NULL;
    reset_1();
}

void Graaf::reset_1() {
    aantalKnopen = 0;
    aantalTakken = 0;
    stappenWaardes = NULL;
    stap = 0;
}//reset_1

void Graaf::reset_2() {
    Header* hHelp1 = listEntrance;
    Header* hHelp2 = NULL;
    Element* eHelp1 = NULL;
    Element* eHelp2 = NULL;
    int aantal = aantalKnopen;
    if (algoritme == 0)
        aantal++;
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
    int aantal = aantalKnopen;
    if (algoritme == 0)
        aantal++; //1 extra nodig voor Dijkstra
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
    stappenWaardes = new huidigeStap*[aantalKnopen];
    for (int i = 0; i < aantal; i++){
        stappenWaardes[i] = new huidigeStap;
        stappenWaardes[i]->afstand = new int[aantalKnopen];
        stappenWaardes[i]->gekleurdeTakken.clear();
        for (int j = 1; j < aantalKnopen; j++)
            stappenWaardes[i]->afstand[j] = INT_MAX;
        stappenWaardes[i]->afstand[0] = 0;
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

void Graaf::vul_takken() {
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

void Graaf::verwijder_arrays() {
    delete[] afstand;
    delete[] vastGezet;
    delete[] stappenWaardes;
    return;
}

int Graaf::zoek_index(Knoop* k) const {
    for(int i=0;i<aantalKnopen;i++)
        if(knopen[i] == k)
            return i;
    return -1;
}

void Graaf::BellmanFord( ) {
    qDebug() << "test";
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
    stappenWaardes[1]->knoop = startknoop;
    //Kortste pad berekenen
    for(int i=1;i<aantalKnopen;i++) {
        stappenWaardes[i]->gekleurdeTakken = stappenWaardes[i-1]->gekleurdeTakken;
        for(int j=0;j<aantalTakken;j++) {
            if(afstand[zoek_index(takken[j]->source)] != INT_MAX &&
            (afstand[zoek_index(takken[j]->source)] + takken[j]->pLineEdit->text().toInt()
            < afstand[zoek_index(takken[j]->dest)])) {
                afstand[zoek_index(takken[j]->dest)] =
                afstand[zoek_index(takken[j]->source)] + takken[j]->pLineEdit->text().toInt();
                voorganger[zoek_index(takken[j]->dest)] = takken[j]->source;
                foreach(Tak* tak, stappenWaardes[i]->gekleurdeTakken) {
                    if (tak->dest == knopen[zoek_index(takken[j]->dest)] || tak->source == knopen[zoek_index(takken[j]->dest)]) {
                        stappenWaardes[i]->gekleurdeTakken.removeOne(tak);
                        break;
                    }//if
                }//foreach
                stappenWaardes[i]->gekleurdeTakken << takken[j]; //Voeg de tak toe aan de lijst
            }//if
            stappenWaardes[i]->afstand[zoek_index(takken[j]->dest)] = afstand[zoek_index(takken[j]->dest)];
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

Element* Graaf::vindRij(Knoop* knoop) {
    Header* h = listEntrance;
    while (h != NULL && h->knoop != knoop)
        h = h->next;
    return h->row;
}

void Graaf::Dijkstra() {
    //Opschonen
    Element* rij = NULL;
    int waarde = INT_MAX;
    int takAfstand = 0;
    int index_source = 0;
    int index_dest = 0;
    verwijder_arrays();
    vul_knopen();
    vul_takken();
    vul_array();
    afstand = new int[aantalKnopen];
    vastGezet = new bool[aantalKnopen];
    //Initialiseren
    for (int i=1; i < aantalKnopen; i++) {
        afstand[i] = INT_MAX;            //beginafstand van start naar willekeurige knoop is 'oneindig'
        vastGezet[i] = false;
    }
    afstand[0] = 0; //afstand van start naar start is 0
    //Kortste pad berekenen:
    for (int i = 0; i < aantalKnopen; i++) {
        waarde = INT_MAX;
            stappenWaardes[i+1]->gekleurdeTakken = stappenWaardes[i]->gekleurdeTakken;
        for (int k = 0; k < aantalKnopen; k++)
            stappenWaardes[i+1]->afstand[k] = stappenWaardes[i]->afstand[k];
        for (int j = 0; j < aantalKnopen; j++) {
            if (afstand[j] < waarde && !vastGezet[j]) {
                waarde = afstand[j];
                index_source = j;
            }//if
        }//for
        stappenWaardes[i+1]->afstand[index_source] = afstand[index_source];
        stappenWaardes[i+1]->knoop = knopen[index_source];
        vastGezet[index_source] = true;
        rij = vindRij(knopen[index_source]);
        while (rij != NULL) {
            index_dest = zoek_index(rij->knoop);
            if (!vastGezet[index_dest]) {
                takAfstand = rij->tak->pLineEdit->text().toInt();
                if (afstand[index_dest] > afstand[index_source] + takAfstand){
                    afstand[index_dest] = afstand[index_source] + takAfstand;
                    stappenWaardes[i+1]->afstand[index_dest] = afstand[index_dest];
                    foreach(Tak* tak, stappenWaardes[i]->gekleurdeTakken) {
                        if (tak->dest == knopen[index_dest] || tak->source == knopen[index_dest]) {
                            stappenWaardes[i+1]->gekleurdeTakken.removeOne(tak);
                            break;
                        }//if
                    }//foreach
                    stappenWaardes[i+1]->gekleurdeTakken << rij->tak;
                }//if
            }//if
            rij = rij->next;
        }//while
    }//for
}//Dijkstra

void Graaf::verwijderAfstanden() {
    for(int i=0; i<aantalKnopen; i++)
        knopen[i]->lengteTekst->setText("");
}

void Graaf::afstandInKnoop(int stap, int i) {
    if(stappenWaardes[stap]->afstand[i] == INT_MAX)
        knopen[i]->lengteTekst->setText("∞");
    else
        knopen[i]->lengteTekst->setText(QString::number(stappenWaardes[stap]->afstand[i]));
}

void Graaf::kleurTakken() {
     for (int i = 0; i < aantalTakken; i++) {
        takken[i]->paintRed = false;
        takken[i]->paintBlue = false;
     }//for
     foreach (Tak *tak, stappenWaardes[stap]->gekleurdeTakken) {
         if (blauweTakken.contains(tak))
             tak->paintBlue = true;
         else
            tak->paintRed = true;
     }//foreach
     for (int i = 0; i < aantalTakken; i++)
         takken[i]->update();
}

bool Graaf::kleurKortstePadRec(Knoop* currentKnoop, Knoop* previousKnoop) {
    if (currentKnoop == startknoop)
        return true;
    foreach(Tak* tak, currentKnoop->takkenList) {
        if (tak->paintRed) {
            if (tak->source == currentKnoop && !(tak->dest == previousKnoop)) {
                if (kleurKortstePadRec(tak->dest, currentKnoop)) {
                    blauweTakken << tak;
                    return true;
                }//if
            }//if
            else if (tak->dest == currentKnoop && !(tak->source == previousKnoop)){
                if (kleurKortstePadRec(tak->source, currentKnoop)) {
                    blauweTakken << tak;
                    return true;
                }//if
            }//else
        }//if
    }//foreach
    return false;
}//kleurKortstePad

void Graaf::kleurKortstePad() {
    int aantal = aantalKnopen;
    if (algoritme == 1)
        aantal--;
    foreach (Tak *tak, stappenWaardes[aantal]->gekleurdeTakken)
        tak->paintRed = true;
    if (kleurKortstePadRec(eindknoop, NULL))
        qDebug() << "korstepad gevonden";
    else {
        blauweTakken.clear();
        qDebug() << "start- en eindknoop niet verbonden";
    }//else
    foreach (Tak *tak, stappenWaardes[aantal]->gekleurdeTakken)
        tak->paintRed = false;
}

void Graaf::stapVooruit() {
    if (!((algoritme == 0 && stap == aantalKnopen) || (algoritme == 1 && stap == aantalKnopen-1))) {
        stap++;
        for (int i = 0; i < aantalKnopen; i++){
            qDebug() << "VooruitKnoop " << i <<" : " <<stappenWaardes[stap]->afstand[i];
            afstandInKnoop(stap, i);
        }//for
        if (algoritme == 0) {
            stappenWaardes[stap]->knoop->paintGreen = true;
            stappenWaardes[stap]->knoop->update();
        }//if
        kleurTakken();        
    }//if
    else
        qDebug() << "einde";
}//stapVooruit

void Graaf::stapAchteruit() {
    if (stap != 0){
        if (algoritme == 0) {
            stappenWaardes[stap]->knoop->paintGreen = false;
            stappenWaardes[stap]->knoop->update();
        }//if
        stap--;
        for (int i = 0; i < aantalKnopen; i++){
            qDebug() << "AchteruitKnoop " << i <<" : " <<stappenWaardes[stap]->afstand[i];
            afstandInKnoop(stap, i);
        }//for
        kleurTakken();
    }//if
    else
        qDebug() << "begin";
}//stapAchteruit

void Graaf::stapBegin() {
    stap = 0;
    for (int i = 0; i < aantalKnopen; i++){
        qDebug() << "BeginKnoop " << i <<" : " <<stappenWaardes[stap]->afstand[i];
        afstandInKnoop(stap, i);
        if (algoritme == 0) {
            stappenWaardes[i+1]->knoop->paintGreen = false;
            stappenWaardes[i+1]->knoop->update();
        }//if
    }//for
    kleurTakken();
}//stapBegin

void Graaf::stapEinde() {
    if (algoritme == 0)
        stap = aantalKnopen;
    else
        stap = aantalKnopen-1;
    for (int i = 0; i < aantalKnopen; i++){
        qDebug() << "EindKnoop " << i <<" : " <<stappenWaardes[stap]->afstand[i];
        afstandInKnoop(stap, i);
        if (algoritme == 0) {
            stappenWaardes[i+1]->knoop->paintGreen = true;
            stappenWaardes[i+1]->knoop->update();
        }//if
    }//for
    kleurTakken();
}//stapEinde
