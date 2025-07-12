#ifndef CERCLE_HPP
#define CERCLE_HPP
#include "Forme.hpp"
#include <iostream>
#include <cmath>
using namespace std;


class Cercle : public Forme {
    double rayon;

public:
    Cercle(double r = 1.0) : rayon(r) {
        cout << "[Cercle] Constructeur" << endl;
    } // Constructeur par défaut  initialise le rayon à 1.0

    Cercle(const Cercle& c) : rayon(c.rayon) {
        cout << "[Cercle] Constructeur de copie" << endl;
    } // Constructeur de copie qui initialise le rayon à celui de l'objet passé en paramètre

    ~Cercle() {
        cout << "[Cercle] Destructeur" << endl;
    } // Destructeur 

    Forme* copie() const override {
        return new Cercle(*this);
    } // Méthode qui crée une copie de l'objet Cercle et retourne un pointeur vers cette copie

    void affiche() const override {
        cout << "Cercle de rayon " << rayon << endl;
    } // Méthode qui affiche le rayon du cercle
};
#endif
