
#ifndef CARRE_HPP
#define CARRE_HPP
#include "Forme.hpp"
#include <iostream>
using namespace std;


class Carre : public Forme {
    double cote;

public:
    Carre(double c = 1.0) : cote(c) {
        cout << "[Carre] Constructeur" << endl;
    } // Constructeur par défaut initialise le côté à 1.0

    Carre(const Carre& car) : cote(car.cote) {
        cout << "[Carre] Constructeur de copie" << endl;
    } // Constructeur de copie qui initialise le côté à celui de l'objet passé en paramètre

    ~Carre() {
        cout << "[Carre] Destructeur" << endl;
    }   // Destructeur

    Forme* copie() const override {
        return new Carre(*this);
    } // Méthode qui crée une copie de l'objet Carre et retourne un pointeur vers cette copie

    void affiche() const override {
        cout << "Carré de côté " << cote << endl;
    } // Méthode qui affiche le côté du carré
};

#endif