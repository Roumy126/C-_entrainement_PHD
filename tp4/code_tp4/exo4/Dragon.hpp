#ifndef DRAGON_HPP
#define DRAGON_HPP

#include "Creature.hpp"

class Dragon : public Creature {
    int porteeFlamme;

public:
    Dragon(string nom, int niv, int pv, int f, int portee, int pos = 0)
        : Creature(nom, niv, pv, f, pos), porteeFlamme(portee) {}

    void voler(int pos) {
        position = pos;
    }

    void lancerFlamme(Creature& cible) {
        int distance = abs(position - cible.getPosition());
        if (!estVivant() || !cible.estVivant() || distance > porteeFlamme)
            return;

        int degats = pointsAttaque();
        cible.recevoirDegats(degats);
        this->recevoirDegats(distance); // le dragon s’affaiblit avec la distance

        if (estVivant() && !cible.estVivant())
            monterNiveau();
    }
};

#endif
