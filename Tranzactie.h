//
// Created by szila on 04/05/2025.
//

#ifndef TRANZACTIE_H
#define TRANZACTIE_H
#include <ostream>
#include "Iterator.h"
#include "Colectie.h"

class Tranzactie {
    int id, suma;
    bool tranzactieValida{};
    Colectie<int> colection;
    std::string data;
    void calculSuma(Colectie<int>& bancnote);
public:
    Tranzactie();
    Tranzactie(const Tranzactie& t);
    Tranzactie(int id, int suma, std::string data, Colectie<int>& bancnote);
    int getId() const;
    int getSuma() const;
    bool getTranzactieValida() const;
    std::string getData();
    Colectie<int>& getColection();
    friend std::ostream& operator<<(std::ostream& os, const Tranzactie& t);
    bool operator<(const Tranzactie& t) const;
    bool operator>(const Tranzactie& t) const;
    bool operator==(const Tranzactie& t) const;
};



#endif //TRANZACTIE_H
