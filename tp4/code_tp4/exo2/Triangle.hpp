#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Forme.hpp"

class Triangle : public Forme {
    double base, hauteur;
public:
    Triangle(double b, double h) : base(b), hauteur(h) {}

    void description() const override {
        cout << "Ceci est un triangle de base " << base << " et hauteur " << hauteur << endl;
    }

    double aire() override {
        return 0.5 * base * hauteur;
    }
};

#endif
