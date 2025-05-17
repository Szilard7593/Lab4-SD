//
// Created by szila on 04/05/2025.
//

#ifndef MULTIMEELEMENTEGENERICEORDONATA_H
#define MULTIMEELEMENTEGENERICEORDONATA_H

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
    void add(T &e);
    int remove(T& e);
    bool ifExist(T& e) ;
    int size() const;
    T getAt(int poz) const;
    T getAt(int poz);
    void destroy();
};


#include "MultimeElementeGenericeOrdonata.tpp"
#endif //MULTIMEELEMENTEGENERICEORDONATA_H
