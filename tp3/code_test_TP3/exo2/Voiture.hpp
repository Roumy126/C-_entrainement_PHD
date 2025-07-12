#ifndef VOITURE_HPP
#define VOITURE_HPP

#include "Vehicule.hpp"
#include <cmath>

class Voiture : public Vehicule {
    double cylindree;
    int nbPortes;
    int puissance;
    int km;

public:
    Voiture(string m, int a, double pa, double cyl, int portes, int cv, int km_)
        : Vehicule(m, a, pa), cylindree(cyl), nbPortes(portes), puissance(cv), km(km_) {}

    void calculePrix() override {
        int annees = 2025 - annee;
        double prix = prixAchat;
        prix *= (1 - 0.02 * annees);
        prix *= (1 - 0.05 * round(km / 10000.0));
        if (marque == "Renault" || marque == "Fiat")
            prix *= 0.9;
        else if (marque == "Ferrari" || marque == "Porsche")
            prix *= 1.2;
        prixCourant = (prix < 0) ? 0 : prix;
    }

    void affiche(ostream& os) const override {
        os << "−−− Voiture −−−" << endl;
        Vehicule::affiche(os);
        os << cylindree << " litres, " << nbPortes << " portes, "
           << puissance << " CV, " << km << " km." << endl;
    }
};

#endif
