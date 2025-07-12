#ifndef VEHICULE_HPP
#define VEHICULE_HPP

#include <iostream>
#include <string>
using namespace std;

class Vehicule {
protected:
    string marque;
    int annee;
    double prixAchat;
    double prixCourant;

public:
    Vehicule(string m, int a, double pa)
        : marque(m), annee(a), prixAchat(pa), prixCourant(pa) {}

    virtual void calculePrix() {
        int annees = 2025 - annee;
        prixCourant = prixAchat * (1 - 0.01 * annees);
        if (prixCourant < 0) prixCourant = 0;
    }

    virtual void affiche(ostream& os) const {
        os << "marque : " << marque
           << ", date d’achat : " << annee
           << ", prix d’achat : " << prixAchat
           << ", prix actuel : " << prixCourant << endl;
    }

    virtual ~Vehicule() {}
};

#endif
