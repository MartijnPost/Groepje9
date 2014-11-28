#include "graaf.h"

Graaf::Graaf() {
    algoritme = 0;
    listEntrance = NULL;
    startknoop = NULL;
    eindknoop = NULL;
    voorganger = NULL;
    knopen = NULL;
    takken = NULL;
    aantalKnopen = 0;
    aantalTakken = 0;
    stappenWaardes = NULL;
    vastGezet = NULL;
    afstand = NULL;
    stap = 0;
}

void Graaf::reset() {
    Header* hHelp1 = listEntrance;
    Header* hHelp2 = NULL;
    Element* eHelp1 = NULL;
    Element* eHelp2 = NULL;
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
    stap = 0;
    knopen = NULL;
    takken = NULL;
    voorganger = NULL;
    if (afstand != NULL) {
        delete[] afstand;
        afstand = NULL;
    }//if
    if (vastGezet != NULL) {
        delete[] vastGezet;
        vastGezet = NULL;
    }//if
    if (stappenWaardes != NULL) {
        qDebug() << aantalKnopen;
        for (int i = 0; i <= aantalKnopen; i++) {
            delete[] stappenWaardes[i].afstand;
            stappenWaardes[i].knoop = NULL;
            stappenWaardes[i].afstand = NULL;
        }//for
        delete[] stappenWaardes;
        stappenWaardes = NULL;
    }//if
    listEntrance = NULL;
    aantalKnopen = 0;
    aantalTakken = 0;
}//reset

void Graaf::expandList(Knoop* k, Header*& h) {
    if(h)
        expandList(k, h->next);
    else {
        h = new Header(k);
        aantalKnopen++;
    }//else
    return;
}//expandList

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
    }//if
    return;
}//expandList

void Graaf::addToRow(Element*& e, Knoop *k, Tak *t) {
    if(e)
        addToRow(e->next, k, t);
    else
        e = new Element(k, t);
    return;
}//addToRow

void Graaf::writeToDebug(Header *h) const {
    if(h){
        qDebug() << "Grenzend aan knoop " << h->knoop->pLineEdit->text() << ":";
        writeToDebug(h->row);
        writeToDebug(h->next);
    }//if
    return;
}//writeToDebug

void Graaf::writeToDebug(Element *e) const {
    if(e) {
        qDebug() << "  knoop" << e->knoop->pLineEdit->text()
                 << "met gewicht" << e->tak->pLineEdit->text();
        writeToDebug(e->next);
    }//if
    return;
}//writeToDebug

/* * * Bellman-Ford * * */

void Graaf::vul_array() {
    //stappenArray vullen
    int n = 1;
    Header* hulp = listEntrance;
    //Loop de headerijst door
    for (int i = 0; i < aantalKnopen; i++) {
        while(hulp != NULL) {
            if(hulp->knoop != startknoop && hulp->knoop != eindknoop){
                n++;
            }//if
            hulp = hulp->next;
        }//while
    }//for
    //stappenWaardes initializeren
    stappenWaardes = new huidigeStap[aantalKnopen+1];
    for (int i = 0; i <= aantalKnopen; i++){
        stappenWaardes[i].afstand = new int[aantalKnopen];
        stappenWaardes[i].gekleurdeTakken.clear();
        for (int j = 1; j < aantalKnopen; j++)
            stappenWaardes[i].afstand[j] = INT_MAX;
        stappenWaardes[i].afstand[0] = 0;
    }//for
    afstand = new int[aantalKnopen];
}//vul_array

void Graaf::vul_knopen() {
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
        }//if
        hulp = hulp->next;
    }//while
    return;
}//vul_knopen

void Graaf::vul_takken() {
    int n = 0;
    Header* hulp1 = listEntrance;
    Element* hulp2 = NULL;
    takken = new takInfo[aantalTakken];
    //Loop de gehele adjacency list door
    while(hulp1 != NULL) {
        hulp2 = hulp1->row;
        while(hulp2 != NULL) {
            takken[n].tak = hulp2->tak;
            takken[n].source1 = hulp2->tak->source;
            takken[n].dest1 = hulp2->tak->dest;
            if (!hulp2->tak->directed) {
                takken[n].source2 = hulp2->tak->dest;
                takken[n].dest2 = hulp2->tak->source;
            }//if
            n++;
            hulp2 = hulp2->next;
        }//while
        hulp1 = hulp1->next;
    }//while
    return;
}//vul_takken

int Graaf::zoek_index(Knoop* k) const {
    for(int i=0;i<aantalKnopen;i++)
        if(knopen[i] == k)
            return i;
    return -1;
}//zoek_index

void Graaf::BellmanFord() {
    //Initialiseren
    qDebug() << aantalKnopen;
    voorganger = new knoopPtr[aantalKnopen];
    for(int i=0;i<aantalKnopen;i++) {
        afstand[i] = INT_MAX; //Oneindig groot (2147483647 is de max waarde van een int)
        voorganger[i] = knopen[0]; //Eigenlijk NULL, crasht anders soms bij debuggen
    }//for
    afstand[0] = 0;
    stappenWaardes[1].knoop = startknoop;
    //Kortste pad berekenen
    for(int i=1;i<aantalKnopen;i++) {
        stappenWaardes[i].gekleurdeTakken = stappenWaardes[i-1].gekleurdeTakken;
        for(int j=0;j<aantalTakken;j++) {
            if (afstand[zoek_index(takken[j].source1)] != INT_MAX &&
            (afstand[zoek_index(takken[j].source1)] + takken[j].tak->pLineEdit->text().toInt()
            < afstand[zoek_index(takken[j].dest1)])) {
                afstand[zoek_index(takken[j].dest1)] =
                afstand[zoek_index(takken[j].source1)] + takken[j].tak->pLineEdit->text().toInt();
                voorganger[zoek_index(takken[j].dest1)] = takken[j].source1;
                foreach(Tak* tak, stappenWaardes[i].gekleurdeTakken) {
                    if (tak->dest == knopen[zoek_index(takken[j].dest1)] || tak->source == knopen[zoek_index(takken[j].dest1)]) {
                        stappenWaardes[i].gekleurdeTakken.removeOne(tak);
                        break;
                    }//if
                }//foreach
                stappenWaardes[i].gekleurdeTakken << takken[j].tak; //Voeg de tak toe aan de lijst
            }//if
            stappenWaardes[i].afstand[zoek_index(takken[j].dest1)] = afstand[zoek_index(takken[j].dest1)];
            if (!takken[j].tak->directed && (afstand[zoek_index(takken[j].source2)] != INT_MAX &&
            (afstand[zoek_index(takken[j].source2)] + takken[j].tak->pLineEdit->text().toInt()
            < afstand[zoek_index(takken[j].dest2)]))) {
                afstand[zoek_index(takken[j].dest2)] =
                afstand[zoek_index(takken[j].source2)] + takken[j].tak->pLineEdit->text().toInt();
                voorganger[zoek_index(takken[j].dest2)] = takken[j].source2;
                foreach(Tak* tak, stappenWaardes[i].gekleurdeTakken) {
                    if (tak->dest == knopen[zoek_index(takken[j].dest2)] || tak->source == knopen[zoek_index(takken[j].dest2)]) {
                        stappenWaardes[i].gekleurdeTakken.removeOne(tak);
                        break;
                    }//if
                }//foreach
                if (!stappenWaardes[i].gekleurdeTakken.contains(takken[j].tak))
                    stappenWaardes[i].gekleurdeTakken << takken[j].tak; //Voeg de tak toe aan de lijst
            }//if
            stappenWaardes[i].afstand[zoek_index(takken[j].dest2)] = afstand[zoek_index(takken[j].dest2)];
        }//for
    }//for
    return;
}//BellmanFord

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
}//vindRij

void Graaf::Dijkstra() {
    //Opschonen
    Element* rij = NULL;
    int waarde = INT_MAX;
    int takAfstand = 0;
    int index_source = 0;
    int index_dest = 0;
    stapEindknoop = aantalKnopen;
    vastGezet = new bool[aantalKnopen];
    //Initialiseren
    for (int i=1; i < aantalKnopen; i++) {
        afstand[i] = INT_MAX;            //beginafstand van start naar willekeurige knoop is 'oneindig'
        vastGezet[i] = false;
    }//for
    afstand[0] = 0; //afstand van start naar start is 0
    //Kortste pad berekenen:
    for (int i = 0; i < aantalKnopen; i++) {
        waarde = INT_MAX;
        stappenWaardes[i+1].gekleurdeTakken = stappenWaardes[i].gekleurdeTakken;
        for (int k = 0; k < aantalKnopen; k++)
            stappenWaardes[i+1].afstand[k] = stappenWaardes[i].afstand[k];
        for (int j = 0; j < aantalKnopen; j++) {
            if (afstand[j] < waarde && !vastGezet[j]) {
                waarde = afstand[j];
                index_source = j;
            }//if
        }//for
        if (i > 0) {
            stappenWaardes[i+1].paarseTakken = stappenWaardes[i].paarseTakken;
            foreach (Tak *tak, knopen[index_source]->takkenList) {
                if (tak->paintRed == false && ((tak->dest == knopen[index_source] &&
                vastGezet[zoek_index(tak->source)]) || (tak->source == knopen[index_source] &&
                vastGezet[zoek_index(tak->dest)]))) {
                    stappenWaardes[i+1].paarseTakken << tak;
                }//if
            }//foreach
        }//if
        stappenWaardes[i+1].afstand[index_source] = afstand[index_source];
        stappenWaardes[i+1].knoop = knopen[index_source];
        if (stappenWaardes[i+1].knoop == eindknoop)
            stapEindknoop = i;
        vastGezet[index_source] = true;
        rij = vindRij(knopen[index_source]);
        while (rij != NULL) {
            index_dest = zoek_index(rij->knoop);
            if (!vastGezet[index_dest]) {
                takAfstand = rij->tak->pLineEdit->text().toInt();
                if (afstand[index_dest] > afstand[index_source] + takAfstand){
                    afstand[index_dest] = afstand[index_source] + takAfstand;
                    stappenWaardes[i+1].afstand[index_dest] = afstand[index_dest];
                    foreach(Tak* tak, stappenWaardes[i].gekleurdeTakken) {
                        if (tak->dest == knopen[index_dest] || tak->source == knopen[index_dest]) {
                            stappenWaardes[i+1].gekleurdeTakken.removeOne(tak);
                            break;
                        }//if
                    }//foreach
                    stappenWaardes[i+1].gekleurdeTakken << rij->tak;
                }//if
            }//if
            rij = rij->next;
        }//while
    }//for
}//Dijkstra

void Graaf::verwijderAfstanden() {
    for(int i=0; i<aantalKnopen; i++)
        knopen[i]->lengteTekst->setText("");
}//verwijderAfstanden

void Graaf::afstandInKnoop(int stap, int i) {
    if(stappenWaardes[stap].afstand[i] == INT_MAX)
        knopen[i]->lengteTekst->setText("∞");
    else
        knopen[i]->lengteTekst->setText(QString::number(stappenWaardes[stap].afstand[i]));
}//afstandInKnoop

void Graaf::kleurTakken() {    
    for (int i = 0; i < aantalTakken; i++) {
        takken[i].tak->paintRed = false;
        takken[i].tak->paintBlue = false;
        takken[i].tak->paintPurple = false;
    }//for
    foreach (Tak *tak, stappenWaardes[stap].gekleurdeTakken)
        tak->paintRed = true;
    if (algoritme == 0) {
        foreach (Tak *tak, stappenWaardes[stap].paarseTakken)
            tak->paintPurple = true;
    }//if
    if (stap != 0 && algoritme == 0) {
        kleurKortstePadRec(stappenWaardes[stap].knoop, NULL, false);
        if (stap > stapEindknoop)
            kleurKortstePadRec(eindknoop, NULL, true);
        else
            kleurKortstePadRec(stappenWaardes[stap+1].knoop, NULL, true);
    }//if
    if (algoritme == 1 && stap == aantalKnopen-1)
        kleurKortstePadRec(eindknoop, NULL, true);
    for (int i = 0; i < aantalTakken; i++)
        takken[i].tak->update();
}//kleurTakken

bool Graaf::kleurKortstePadRec(Knoop* currentKnoop, Knoop* previousKnoop, bool blauw) {
    if (currentKnoop == startknoop)
        return true;
    foreach(Tak* tak, currentKnoop->takkenList) {
        if (tak->paintRed) {
            if (tak->source == currentKnoop && !(tak->dest == previousKnoop)) {
                if (kleurKortstePadRec(tak->dest, currentKnoop, blauw)) {
                    if (blauw) {
                        tak->paintRed = false;
                        tak->paintBlue = true;
                    }//if
                    else {
                        tak->paintRed = true;
                        tak->paintBlue = false;
                    }//else
                    tak->update();
                    return true;
                }//if
            }//if
            else if (tak->dest == currentKnoop && !(tak->source == previousKnoop)) {
                if (kleurKortstePadRec(tak->source, currentKnoop, blauw)) {
                    if (blauw) {
                        tak->paintRed = false;
                        tak->paintBlue = true;
                    }//if
                    else {
                        tak->paintRed = true;
                        tak->paintBlue = false;
                    }//else
                    tak->update();
                    return true;
                }//if
            }//else
        }//if
    }//foreach
    return false;
}//kleurKortstePad

void Graaf::stapVooruit() {
    if (!(stap == aantalKnopen || (algoritme == 1 && stap == aantalKnopen-1))) {
        stap++;
        for (int i = 0; i < aantalKnopen; i++){
            qDebug() << "VooruitKnoop " << i <<" : " <<stappenWaardes[stap].afstand[i];
            afstandInKnoop(stap, i);
        }//for
        if (algoritme == 0) {
            stappenWaardes[stap].knoop->paintGreen = true;
            stappenWaardes[stap].knoop->update();
        }//if
        kleurTakken();        
    }//if
    else
        qDebug() << "einde";
}//stapVooruit

void Graaf::stapAchteruit() {
    if (stap != 0){
        if (algoritme == 0) {
            stappenWaardes[stap].knoop->paintGreen = false;
            stappenWaardes[stap].knoop->update();
        }//if
        stap--;
        for (int i = 0; i < aantalKnopen; i++){
            qDebug() << "AchteruitKnoop " << i <<" : " <<stappenWaardes[stap].afstand[i];
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
        qDebug() << "BeginKnoop " << i <<" : " <<stappenWaardes[stap].afstand[i];
        afstandInKnoop(stap, i);
        if (algoritme == 0) {
            stappenWaardes[i+1].knoop->paintGreen = false;
            stappenWaardes[i+1].knoop->update();
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
        qDebug() << "EindKnoop " << i <<" : " <<stappenWaardes[stap].afstand[i];
        afstandInKnoop(stap, i);
        if (algoritme == 0) {
            stappenWaardes[i+1].knoop->paintGreen = true;
            stappenWaardes[i+1].knoop->update();
        }//if
    }//for
    kleurTakken();
}//stapEinde
