#ifndef GRAAF_H
#define GRAAF_H

#include "knoop.h"
#include "tak.h"

class tekenveld;

//Voor de dynamische arrays:
typedef Knoop* knoopPtr;
typedef Tak* takPtr;

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
    int aantalKnopen;                             //Aantal knopen in de graaf
    int aantalTakken;                             //Aantal takken in de graaf
    Knoop* startknoop;                            //Startknoop van de graaf
    Knoop* eindknoop;                             //Eindknoop van de graaf
    Header* listEntrance;                         //Pointer naar de bovenste Header uit de adjacency list
    void expandList(Knoop* k, Header*& h);        //Zet een nieuwe Knoop als Header van de adjacency list
    void expandList(Tak* t, Header*& h);          //Zet nieuwe Elementen in de adjacency list als een tak is toegevoegd
    void addToRow(Element*& e, Knoop* k, Tak* t); //Voegt een Element toe aan het einde van een rij
    void writeToDebug(Header* h) const;           //Drukt de adjacency list af in de debug
    void writeToDebug(Element* e) const;          //Drukt de adjacency list af in de debug
    /* Bellman-Ford Algoritme: */
    int* afstand;                                 //Lijst met de afstanden van elke knoop tot de startknoop
    knoopPtr* voorganger;                         //Lijst met voor elke knoop hun voorganger in hun korste pad
    knoopPtr* knopen;                             //Lijst met alle knopen uit de graaf
    takPtr* takken;                               //Lijst met alle takken uit de graafd
    knoopPtr* kortste_pad;                        //De knopen die op het kortste pad van start naar eind liggen (start = [0])
    void vul_knopen( );                           //Vult de lijst 'knopen'
    void vul_takken( );                           //Vult de lijst 'takken'
    void verwijder_arrays( );                     //Verwijderd de dynamische arrays (knopen, takken, afstand & voorganger)
    int zoek_index(Knoop* k) const;               //Zoekt voor een knoop zijn index in de lijst 'knopen'
    void BellmanFord( );                          //Implementatie functie voor het Bellman-Ford algoritme
    void vul_kortste_pad( );                      //Vult de lijst 'kortste_pad'
    int stappenArray[999][999];                   //Array waar alle lengtes van algoritme stap voor stap in opgeslagen zijn
    int stap;                                     //Tellertje voor stappenArray
    void stapVooruit( );                          //Zet een stap verder in het algoritme
    void stapAchteruit( );                        //Zet een stap terug in het algrotime
    void stapBegin( );                            //Ga terug naar het begin van het algoritme
    void stapEinde( );                            //Ga naar het einde van het algoritme

};

#endif // GRAAF_H
