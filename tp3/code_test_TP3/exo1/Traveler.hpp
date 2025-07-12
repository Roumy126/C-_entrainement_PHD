#ifndef TRAVELER_HPP
#define TRAVELER_HPP

#include <iostream>
#include <string>
using namespace std;

class Traveler {
protected:
    string name;

public:
    Traveler(string n) : name(n) {
        cout << "Constructeur Traveler: " << name << endl;
    }// Constructeur avec paramètre

    Traveler(const Traveler& other) : name(other.name) {
        cout << "Constructeur de copie Traveler" << endl;
    } // Constructeur de recopie

    Traveler& operator=(const Traveler& other) {
        if (this != &other) {
            name = other.name;
            cout << "Operator= Traveler" << endl;
        }
        return *this;
    } // Opérateur d’affectation

    virtual void print() const {
        cout << "Traveler: " << name << endl;
    } // Méthode virtuelle pour l'affichage
};

#endif
