//
// Created by szila on 04/05/2025.
//

#include "MultimeElementeGenericeOrdonata.tpp"
//Constructor
template <typename T>
Multime<T>::Multime(Comparator<T> cmpFunc):head(nullptr),
    noElems(0),
    cmp(cmpFunc){}

//Destructor
template <typename T>
Multime<T>::~Multime() {
    destroy();
}

//Adaugare element
template <typename T>
void Multime<T>::add(const T& e) {
    if (ifExist(e))
        return;

    // Adaugare la inceput
    if (head == nullptr || cmp(e, head->info)) {
        Node<T>* newNode = new Node<T>(e, head);
        head = newNode;
        noElems++;
        return;
    }

    // Adaugare in mijloc sau la sfarsit
    Node<T>* current = head;
    while (current->next != nullptr && cmp(current->next->info, e)) {
        current = current->next;
    }

    // Adaugare dupa nodul curent
    Node<T>* newNode = new Node<T>(e, current->next);
    current->next = newNode;
    noElems++;
}

//Stergere element
template <typename T>
int Multime<T>::remove(const T& e) {
    Node<T>* current = head;
    Node<T>* previous = nullptr;

    while (current != nullptr) {
        if (current->info == e) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            noElems--;
            return 1;
        }
        previous = current;
        current = current->next;
    }

    return 0;
}

//Verificare existenta element
template<typename T>
bool Multime<T>::ifExist(const T &e) {
    return searchNode(e) != nullptr;

}

//Cautare element
template<typename T>
Node<T>* Multime<T>::searchNode(T &e) const {
    Node<T>* current = head;
    while (current) {
        if (current->info == e)
            return current;
        current = current->next;
    }
    return nullptr;
}

//Dimensiune multime
template<typename T>
int Multime<T>::size() const {
    return noElems;
}

//Obtinere element
template<typename T>
T Multime<T>::getElem(int poz) const{
    if (poz < 0 || poz >= noElems) {
        throw std::out_of_range("Pozitie invalida");
    }
    Node<T>* current = head;
    for (int i = 0; i < poz; ++i) {
        current = current->next;
    }
    return current->info;
}

template<typename T>
void Multime<T>::destroy() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* nextNode = current->next;
        delete current;
        current = nextNode;
    }
    head = nullptr;
    noElems = 0;
}

template<typename T>
T Multime<T>::getElem(int poz) {
    if (poz < 0 || poz >= noElems) {
        throw std::out_of_range("Pozitie invalida");
    }
    Node<T>* current = head;
    for (int i = 0; i < poz; ++i) {
        current = current->next;
    }
    return current->info;
}



