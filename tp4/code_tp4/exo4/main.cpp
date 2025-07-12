#include "Dragon.hpp"
#include "Hydre.hpp"

void combat(Dragon& d, Hydre& h) {
    h.empoisonne(d);
    d.lancerFlamme(h);
}

// -----------------------------------------
// main()
// -----------------------------------------
int main() {
    Dragon dr("Dragon rouge", 2, 10, 3, 2, 0);
    Hydre hy("Hydre maléfique", 2, 10, 1, 1, 1, 42);

    cout << "Préparation au combat :\n";
    dr.afficher();
    cout << "se prépare au combat avec :\n";
    hy.afficher();

    cout << "\n1er combat :\n";
    combat(dr, hy);
    cout << "\nAprès le combat :\n";
    dr.afficher();
    hy.afficher();

    cout << "\nLe dragon vole à proximité :\n";
    dr.voler(41);
    dr.afficher();

    cout << "L’hydre recule :\n";
    hy.deplacer(1); // vers 43
    hy.afficher();

    cout << "\n2e combat :\n";
    combat(dr, hy);
    dr.afficher();
    hy.afficher();

    cout << "\n3e combat :\n";
    dr.voler(42);
    combat(dr, hy);
    dr.afficher();
    hy.afficher();

    return 0;
}