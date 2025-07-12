#ifndef PAGER_HPP
#define PAGER_HPP

#include <iostream>
#include <string>
using namespace std;

class Pager {
private:
    string code;

public:
    Pager(string c) : code(c) {
        cout << "Constructeur Pager: " << code << endl;
    } // Constructeur avec paramètre

    Pager(const Pager& other) : code(other.code) {
        cout << "Constructeur de copie Pager" << endl;
    }   // Constructeur de recopie

    Pager& operator=(const Pager& other) {
        if (this != &other) {
            code = other.code;
            cout << "Operator= Pager" << endl;
        }
        return *this;
    } // Opérateur d’affectation

    void print() const {
        cout << "Pager: " << code << endl;
    } // Méthode pour afficher le code du pager
};

#endif
