//
// Created by camel on 4/7/2025.
//

#ifndef CURS7_LSI_COLECTIE_H
#define CURS7_LSI_COLECTIE_H

#include <stdexcept>
#include "Node.h"
#include "MultimeElementeGenericeOrdonata.h"

template <class E>
class Colectie {
private:
    Node<E>* head;
    int len;

public:
    Colectie();
    ~Colectie();
    void add(E valoare);
    bool remove(E valoare);
    bool search(E valoare);
    int size();
    int nrOcurencies(E valoare);
    void destroy();
    E getAt(int position);
    Iterator<E> iterator() const;
    friend class Iterator<E>;

};


#include "Colectie.tpp"
#endif //CURS7_LSI_COLECTIE_H
