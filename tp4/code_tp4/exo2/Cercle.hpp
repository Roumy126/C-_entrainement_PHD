#ifndef CERCLE_HPP
#define CERCLE_HPP

#include "Forme.hpp"
#include <cmath>

class Cercle : public Forme {
    double rayon;
public:
    Cercle(double r) : rayon(r) {}

    void description() const override {
        cout << "Ceci est un cercle de rayon " << rayon << endl;
    }

    double aire() override {
        return M_PI * rayon * rayon;
    }
};

#endif
