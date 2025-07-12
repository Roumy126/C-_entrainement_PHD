#ifndef BUSINESSTRAVELER_HPP
#define BUSINESSTRAVELER_HPP

#include "Traveler.hpp"
#include "Pager.hpp"

class BusinessTraveler : public Traveler {
private:
    Pager pager;

public:
    // Constructeur avec paramètre pour les deux membres
    BusinessTraveler(string n, string code)
        : Traveler(n), pager(code) {
        cout << "Constructeur BusinessTraveler" << endl;
    }

    // Constructeur de recopie
    BusinessTraveler(const BusinessTraveler& other)
        : Traveler(other), pager(other.pager) {
        cout << "Constructeur de copie BusinessTraveler" << endl;
    }

    // Opérateur d’affectation
    BusinessTraveler& operator=(const BusinessTraveler& other) {
        if (this != &other) {
            Traveler::operator=(other); // appel à la base
            pager = other.pager;        // affectation du membre composé
            cout << "Operator= BusinessTraveler" << endl;
        }
        return *this;
    }
    

    void print() const override {
        Traveler::print();
        pager.print();
    }
};

#endif
