#include <iostream>
#include <vector>
#include "Voiture.hpp"
#include "Avion.hpp"

int main() {
    vector<Vehicule*> v;

    v.push_back(new Voiture("Peugeot", 1998, 147326, 2.5, 5, 180, 12000));
    v.push_back(new Voiture("Porsche", 1985, 250000, 6.5, 2, 280, 81320));
    v.push_back(new Voiture("Fiat", 2001, 7327.3, 1.6, 3, 65, 3000));
    v.push_back(new Avion("Cessna", 1972, 1.23067e6, "helices", 250));
    v.push_back(new Avion("Nain Connu", 1992, 4.3211e6, "reaction", 1300));

    for (auto ve : v) {
        ve->calculePrix();
        ve->affiche(cout);
        cout << endl;
    }

    for (auto ve : v) delete ve;
    return 0;
}
