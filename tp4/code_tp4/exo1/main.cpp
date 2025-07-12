#include "Forme.hpp"
#include "Cercle.hpp"

void afficheDesc(Forme& f) {
    f.description();
}

int main() {
    Forme f;
    Cercle c;

    f.description();    // Ceci est une forme 
    c.description();    // Ceci est un cercle.
    afficheDesc(f);     // Ceci est une forme 
    afficheDesc(c);     // Ceci est un cercle.

//le résultat est contre-intuitif 
    Forme f2(c);
    f2.description(); // Ceci est une forme alors lobjet c est de type  Cercle
    return 0;
}
