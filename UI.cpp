#include "UI.h"
#include <fstream>
#include <iostream>
#include "Tranzactie.h"
#include "Colectie.h"

void UI::printOptions() {
    for (int i = 0; i < 3; ++i) {
        cout << i+1 << ". " << options[i] << '\n';
    }
}

void UI::initBancnote() {
    ifstream in("../Bancnote.in");
    int frecv;
    int val;
    while (in >> frecv >> val) {
        for (int i = 0; i < frecv; ++i)
            bancnote.add(val);
    }
    in.close();
}


int UI::citireSuma() {
    int suma;
    cout << "Suma: ";
    cin >> suma;
    return suma;
}

std::string UI::citireData() {
    std::string s;
    cout << "Data: ";
    cin >> s;
    return s;
}

bool UI::cmp(Tranzactie& t1, Tranzactie& t2) {
    return t1.getData() < t2.getData() ||
          (t1.getData() == t2.getData() && t1.getSuma() < t2.getSuma()) ||
          (t1.getSuma() == t2.getSuma() && t1.getColection().size() < t2.getColection().size());
}



UI::UI(): tranzactii(&UI::cmp) {
    initBancnote();
}

void UI::printBancnote() {
    cout << bancnote << '\n';
}


void UI::runConsole() {
    while (true) {
        printOptions();
        int option;
        cout << " Option: \n" <<endl;
        cin >> option;
        switch (option) {
            case 1:
                printBancnote();
            break;
            case 2:
                RetragereSuma();
            break;
            case 3:
                AfisareTranzactii();
            break;
            default:
                cout << "Invalid option!\n";
        }
    }
}

void UI::RetragereSuma() {
    int suma = citireSuma();
    string data = citireData();
    Tranzactie t(nrTranzactii, suma, data, bancnote);
    tranzactie.add(t);
    nrTranzactii++;
    cout << "Tranzactie adaugata: " << t << endl;
}

void UI::AfisareTranzactii() {
    cout << "Tranzactii: \n";
    for (int i = 0; i < tranzactie.size(); ++i) {
        cout << tranzactie.getAt(i) << endl;
    }
}