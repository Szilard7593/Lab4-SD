//
// Created by camel on 4/7/2025.
//

#ifndef CURS7_LSI_NODE_H
#define CURS7_LSI_NODE_H

template <typename E>
class Colectie;

template <typename E>
class Iterator;


template <class E>
class Node {
    E info;
   // int frecventa;
    Node<E>* next;
public:
    Node(E info, Node<E>* next = nullptr) : info(info), next(next) {}
    friend class Colectie<E>;
    friend class Iterator<E>;
};


#endif //CURS7_LSI_NODE_H
