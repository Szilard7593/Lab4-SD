//
// Created by camel on 4/7/2025.
//

#ifndef CURS7_LSI_ITERATOR_H
#define CURS7_LSI_ITERATOR_H
#include <stdexcept>
#include "Node.h"

template <class E>
class Iterator {
private:
    Node<E>* current;


public:
    Iterator(Node<E>* start) : current(start) {}

    bool valid() const {
        return current != nullptr;
    }

    void next() {
        if (!valid())
            throw std::out_of_range("Iterator invalid!");
        current = current->next;
    }

    E element() const {
        if (!valid())
            throw std::out_of_range("Iterator invalid!");
        return current->info;
    }

    void first() {

    }
};



#endif //CURS7_LSI_ITERATOR_H
