#ifndef GRAAF_H
#define GRAAF_H

#include "knoop.h"
#include "tak.h"

class tekenveld;

//De elementen uit de rijen van de adjacency list
struct Element
{
    Knoop* knoop;
    Tak* tak;
    Element* next;
    Element() : knoop(NULL), tak(NULL), next(NULL) {};
    Element(Knoop* k, Tak* t) : knoop(k), tak(t), next(NULL) {};
};

//De elementen uit de linker kolom in de adjacency list
struct Header
{
    Knoop* knoop;
    Element* row;
    Header* next;
    Header() : knoop(NULL), row(NULL), next(NULL) {};
    Header(Knoop* k) : knoop(k), row(NULL), next(NULL) {};
};

class Graaf
{
public:
    Graaf();
    friend class tekenveld;
private:
    Knoop *startknoop;
    Header* listEntrance;                         //Pointer naar de bovenste Header uit de adjacency list
    void expandList(Knoop* k, Header*& h);        //Zet een nieuwe Knoop als Header van de adjacency list
    void expandList(Tak* t, Header*& h);          //Zet nieuwe Elementen in de adjacency list als een tak is toegevoegd
    void addToRow(Element*& e, Knoop* k, Tak* t); //Voegt een Element toe aan het einde van een rij
    void writeToDebug(Header* h) const;           //Drukt de adjacency list af in de debug
    void writeToDebug(Element* e) const;          //Drukt de adjacency list af in de debug
};

#endif // GRAAF_H
