#ifndef HYDRE_HPP
#define HYDRE_HPP

#include "Creature.hpp"

class Hydre : public Creature {
    int longueurCou;
    int dosePoison;

public:
    Hydre(string nom, int niv, int pv, int f, int cou, int poison, int pos = 0)
        : Creature(nom, niv, pv, f, pos), longueurCou(cou), dosePoison(poison) {}

    void empoisonne(Creature& cible) {
        int distance = abs(position - cible.getPosition());
        if (!estVivant() || !cible.estVivant() || distance > longueurCou)
            return;

        int degats = pointsAttaque() + dosePoison;
        cible.recevoirDegats(degats);

        if (!cible.estVivant())
            monterNiveau();
    }
};

#endif
