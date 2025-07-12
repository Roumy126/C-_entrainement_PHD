#ifndef VECTEUR_UNITAIRE_HPP
#define VECTEUR_UNITAIRE_HPP

#include "Vecteur.hpp"

class VecteurUnitaire : public Vecteur {
public:
    VecteurUnitaire(double x, double y, double z) : Vecteur(x, y, z) {
        normalise();
    }

    void normalise() {
        double n = norme();
        if (n == 0) {
            std::cerr << "Erreur : vecteur nul, normalisation impossible." << std::endl;
            return;
        }
        x /= n; y /= n; z /= n;
    }

    // Redéfinition pour maintenir unicité
    VecteurUnitaire& operator+=(const Vecteur& v) {
        Vecteur::operator+=(v);
        normalise();
        return *this;
    }

    VecteurUnitaire& operator-=(const Vecteur& v) {
        Vecteur::operator-=(v);
        normalise();
        return *this;
    }

    VecteurUnitaire& operator*=(double a) {
        Vecteur::operator*=(a);
        normalise();
        return *this;
    }
};

#endif
