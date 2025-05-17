//
// Created by szila on 04/05/2025.
//
#pragma once
#ifndef UI_H
#define UI_H
#include <string>
#include "Colectie.h"
#include "Tranzactie.h"

using namespace std;

class Tranzactie;


class UI {
    string options[10] = {"Afisare bancnote", "Retragere suma", "Afisare tranzactii"};
    Colectie<int> bancnote;
    Multime<Tranzactie> tranzactie;

    bool (*tranzactii)(Tranzactie&, Tranzactie&);
    int nrTranzactii = 0;
    void printOptions();
    void initBancnote();
    static int citireSuma();
    static std::string citireData();
    static bool cmp(Tranzactie &t1, Tranzactie &t2);
public:
    UI();
    void printBancnote();
    void runConsole();
    void RetragereSuma();
    void AfisareTranzactii();
};



#endif //UI_H
