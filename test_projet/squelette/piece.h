#ifndef PIECE_H
#define PIECE_H

#include "playerEnum.h"

enum Size{
    NONE,
    SMALL,
    MEDIUM,
    LARGE
};

class Piece
{
    private:
        Player owner;
        Size size;

    public:
        Piece(); // constructeur par défaut, crée une pièce vide (owner = NO_PLAYER, size = NONE)
        Piece(Player owner, Size size); //crée une pièce avec un joueur et une taille donnés constructeur avec paramètres
        
        Piece(const Piece& other); // constructeur de copie

        Player getOwner() const; // retourne le joueur propriétaire de la pièce const signifient que ces fonctions ne modifient pas l'objet
        Size getSize() const; // retourne la taille de la pièce

        Piece& operator=(const Piece& other); // opérateur d'affectation, permet de copier une pièce dans une autre
};

#endif // PIECE_H




