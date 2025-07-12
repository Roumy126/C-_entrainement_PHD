#ifndef AVION_HPP
#define AVION_HPP

#include "Vehicule.hpp"

class Avion : public Vehicule {
    string type;
    int heures;

public:
    Avion(string m, int a, double pa, string t, int h)
        : Vehicule(m, a, pa), type(t), heures(h) {}

    void calculePrix() override {
        double prix = prixAchat;
        int facteur = (type == "reaction") ? (heures / 1000) : (heures / 100);
        prix *= (1 - 0.1 * facteur);
        prixCourant = (prix < 0) ? 0 : prix;
    }

    void affiche(ostream& os) const override {
        os << "−−− Avion a " << type << " −−−" << endl;
        Vehicule::affiche(os);
        os << heures << " heures de vol." << endl;
    }
};

#endif
