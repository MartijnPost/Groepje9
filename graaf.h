#ifndef GRAAF_H
#define GRAAF_H

#include "knoop.h"
#include "tak.h"

class Graaf
{
public:
    Graaf();
    Knoop *startknoop;
    //Een pointer naar de eindknoop is denk ik niet nodig
private:
    void expandList(Knoop *k); //Bereidt de adjacency list uit
    // void expandList(tak* t);
    // void contractList(knoop* k);
    // void contractList(tak* t);
};

#endif // GRAAF_H
