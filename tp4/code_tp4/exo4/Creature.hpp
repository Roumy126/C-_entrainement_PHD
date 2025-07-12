#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Creature {
protected:
    string nom;
    int niveau, pointsDeVie, force, position;

public:
    Creature(string nom, int niv, int pv, int f, int pos = 0)
        : nom(nom), niveau(niv), pointsDeVie(pv), force(f), position(pos) {}

    bool estVivant() const {
        return pointsDeVie > 0;
    }

    int pointsAttaque() const {
        return estVivant() ? niveau * force : 0;
    }       

    void deplacer(int delta) {
        position += delta;
    }

    void adieux() {
        cout << nom << " n’est plus !" << endl;
    }

    void recevoirDegats(int d) {
        if (!estVivant()) return;
        pointsDeVie -= d;
        if (pointsDeVie <= 0) {
            pointsDeVie = 0;
            adieux();
        }
    }

    void afficher() const {
        cout << nom << ", niveau: " << niveau
             << ", points de vie: " << pointsDeVie
             << ", force: " << force
             << ", points d’attaque: " << pointsAttaque()
             << ", position: " << position << endl;
    }

    int getPosition() const { return position; }
    string getNom() const { return nom; }
    int getNiveau() const { return niveau; }
    void monterNiveau() { ++niveau; }
};


#endif
