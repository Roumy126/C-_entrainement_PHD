#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Forme.hpp"

class Triangle : public Forme {
    double base, hauteur;

public:
    Triangle(double b = 1, double h = 1) : base(b), hauteur(h) {
        cout << "Constructeur Triangle" << endl;
    } // Constructeur par défaut initialise la base et la hauteur à 1

    Triangle(const Triangle& other) : base(other.base), hauteur(other.hauteur) {
        cout << "Constructeur de copie Triangle" << endl;
    }   // Constructeur de copie qui initialise la base et la hauteur à celles de l'objet passé en paramètre

    ~Triangle() {
        cout << "Destructeur Triangle" << endl;
    }   // Destructeur

    void affiche() const override {
        cout << "Triangle - base: " << base << ", hauteur: " << hauteur << endl;
    } // Méthode qui affiche la base et la hauteur du triangle

    Forme* copie() const override {
        return new Triangle(*this);
    }   // Méthode qui crée une copie de l'objet Triangle et retourne un pointeur vers cette copie
};

#endif
