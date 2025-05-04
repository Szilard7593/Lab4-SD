//
// Created by camel on 4/7/2025.
//

#include "Colectie.h"
#include <iostream>
#include <stdexcept>
#include "Iterator.h"
#include "Node.h"
#include "MultimeElementeGenericeOrdonata.tpp"

#include "UI.h"
template <typename E>
Colectie<E>::Colectie() : head(nullptr), len(0) {}

template <typename E>
Colectie<E>::~Colectie() {
    destroy();
}

template <typename E>
void Colectie<E>:: add(E valoare) {
    Node<E>* newNode = new Node<E>(valoare, head);
    head = newNode;
    len++;
}

template <typename E>
bool Colectie<E>::remove(E valoare) {
    Node<E>* current = head;
    Node<E>* previous = nullptr;

    while (current != nullptr) {
        if (current->info == valoare) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            len--;
            return true;
        }
        previous = current;
        current = current->next;
    }

    return false;
}

template <typename E>
bool Colectie<E>::search(E valoare) {
    Node<E>* current = head;
    while (current != nullptr) {
        if (current->info == valoare) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename E>
int Colectie<E>::size() {
    return len;
}

template <typename E>
int Colectie<E>::nrOcurencies(E valoare) {
    int count = 0;
    Node<E>* current = head;
    while (current != nullptr) {
        if (current->info == valoare) {
            count++;
        }
        current = current->next;
    }
    return count;
}

template <typename E>
void Colectie<E>::destroy() {
    Node<E>* current = head;
    while (current != nullptr) {
        Node<E>* nextNode = current->next;
        current = nextNode;
    }
    head = nullptr;
    len = 0;
}

template <typename E>
E Colectie<E>:: getAt(int position) {
    if (position < 0 || position >= len) {
        throw std::out_of_range("Pozitie invalida");
    }

    Node<E>* current = head;
    int index = 0;
    while (index < position) {
        current = current->next;
        index++;
    }

    return current->info;
}

template <typename E>
Iterator<E> Colectie<E>:: iterator() const {
    return Iterator<E>(head);
}

template <typename E>
std::ostream& operator<<(std::ostream& os, const Colectie<E>& colectie) {
    // Check if collection is empty

    // Use the iterator to traverse the collection
    Iterator<E> it = colectie.iterator();
    os << "Colectie: \n";

    bool first = true;
    while (it.valid()) {
        // Add separator except for first element
        if (!first) {
            os << ", ";
        } else {
            first = false;
        }

        // Output the current element
        os << it.element();
        it.next();
    }

    return os;
}

