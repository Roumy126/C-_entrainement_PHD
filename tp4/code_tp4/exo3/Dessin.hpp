#ifndef DESSIN_HPP
#define DESSIN_HPP

#include "Forme.hpp"
#include <vector>

class Dessin {
    std::vector<Forme*> formes; //formes est un vecteur de pointeurs vers la classe de base Forme

public:
    void ajouteForme(const Forme& f) {
        formes.push_back(f.copie());
    } // ajouteForme prend une référence constante à un objet Forme, crée une copie de cet objet en mémoire et l'ajoute au vecteur formes

    void affiche() const {
        for (Forme* f : formes)
            f->affiche();
    } // affiche parcourt le vecteur formes et appelle la méthode affiche de chaque objet Forme

    ~Dessin() {
        cout << "Destructeur Dessin" << endl;
        for (Forme* f : formes) delete f;
    } // Le destructeur de Dessin libère la mémoire allouée pour chaque objet Forme dans le vecteur formes
};

#endif
