//
// Created by szila on 04/05/2025.
//

#include "Tranzactie.h"
#include <utility>

void Tranzactie::calculSuma(Colectie<int>& bancnote) {
    Colectie<int> temp = bancnote; //Fcem o copie
    Colectie<int> tempTransaction; //Macar de data asta nu fura bancnotele la greu daca suma de retragere este mai mare ca suma bancnotelor disponibile

    int sumaRamasa = this->suma;
    bool valid = true;

    while (sumaRamasa && valid) {
        int el = -1;
        int difMin = sumaRamasa;

        for (int i = 0; i < temp.size(); i++) {
            int val = temp.getAt(i);

            if ( sumaRamasa - val >= 0 && sumaRamasa - val < difMin) {
                difMin = sumaRamasa - val;
                el = val;
            }
        }
        if (el == -1)
            valid = false;
        else {
            temp.remove(el);
            sumaRamasa -= el;
            tempTransaction.add(el);
        }
    }

    tranzactieValida = sumaRamasa == 0;

    if (tranzactieValida) {
        bancnote = temp;
        colection = tempTransaction;  //Salveaza tranzactia daca totul este in regula
    }
}


Tranzactie::Tranzactie() {
    id = 0;
    suma = 0;
    tranzactieValida = false;
}

Tranzactie::Tranzactie(const Tranzactie &t){
    id = t.id;
    data = t.data;
    suma = t.suma;
    tranzactieValida = t.tranzactieValida;
    colection = t.colection;
}

Tranzactie::Tranzactie(int id, int suma, std::string data, Colectie<int>& bancnote) {
    this->id = id;
    this->suma = suma;
    calculSuma(bancnote);
    this->data = std::move(data);
}


int Tranzactie::getId() const {
    return id;
}

int Tranzactie::getSuma() const {
    return suma;
}

bool Tranzactie::getTranzactieValida() const {
    return tranzactieValida;
}

std::string Tranzactie::getData() {
    return data;
}

Colectie<int>& Tranzactie::getColection() {
    return this->colection;
}

bool Tranzactie::operator<(const Tranzactie &t) const {
    return data < t.data;
}

bool Tranzactie::operator>(const Tranzactie &t) const {
    return data > t.data;
}

bool Tranzactie::operator==(const Tranzactie &t) const {
    return t.id == id;
}


std::ostream & operator<<(std::ostream &os, const Tranzactie &t) {
    if (t.tranzactieValida)
        os << "Tranzactie in data de "<< t.data<< ",in valoare de:" << t.suma << " \n" << t.colection;
    else
        os << "Tranzactia in valoare de " << t.suma << " nu se poate realiza\n";
    return os;
}

