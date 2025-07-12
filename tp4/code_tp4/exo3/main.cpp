#include "Dessin.hpp"
#include "Triangle.hpp"

int main() {
    Dessin dessin;
    dessin.ajouteForme(Triangle(3, 4));
    dessin.ajouteForme(Triangle(6, 1));

    cout << "\nAffichage du dessin :\n";
    dessin.affiche();
    return 0;
}
