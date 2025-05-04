//
// Created by szila on 04/05/2025.
//

#ifndef MULTIMEELEMENTEGENERICEORDONATA_H
#define MULTIMEELEMENTEGENERICEORDONATA_H
#include "Colectie.h"


template<typename T>
using Comparator = bool (*)(const T&, const T&);  //pointer la functie

template<typename T>
class Multime {
private:
    Node<T>* head;
    int noElems;
    Comparator<T> cmp;  // folosește aliasul de tip
    Node<T>* searchNode( T& e) const;

public:
    explicit Multime(Comparator<T> cmpFunc);
    ~Multime();
    void add(const T &e);
    int remove( const T& e);
    bool ifExist( const T& e) ;
    int size() const;
    T getElem(int poz) const;
    T getElem(int poz);
    void destroy();
};



#endif //MULTIMEELEMENTEGENERICEORDONATA_H
