#ifndef STACKARRAY_H
#define STACKARRAY_H

#include <stdexcept> // exceptions standard

#include <iostream>

class stackArray {
private:
    static const int default_size = 50; // taille par défaut
    const int tailleMax;                // taille maximale de la pile
    int head;                           // index du sommet
    int* data;                          // tableau dynamique

public:
    // Constructeur
    stackArray(int size = default_size);

    // Destructeur
    ~stackArray();

    // Opérations de la pile
    void push(int value);      // empiler
    int pop();                 // dépiler
    int peek() const;          // sommet
    bool isEmpty() const;      // est vide ?
    int getSize() const;       // nombre d'éléments

    // Afficher le contenu de la pile
    void afficher() const;
};

#endif
