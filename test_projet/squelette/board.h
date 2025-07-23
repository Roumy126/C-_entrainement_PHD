#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include "cell.h"
#include "playerEnum.h"
#include "config.h"
#include "statusEnum.h"
#include <iostream>

class Board
{
    private:
        Cell state[DIMENSIONS][DIMENSIONS];  //Représente le plateau de jeu 3x3 sous forme d’une matrice de Cell
        int p1Pieces[NB_SIZE]; // Nombre de pièces restantes pour le joueur 1, indexé par la taille de la pièce
        int p2Pieces[NB_SIZE]; // Nombre de pièces restantes pour le joueur 2, indexé par la taille de la pièce

       
        int* getHousesOfPlayer(Player player);  // Retourne le tableau de pièces restantes pour le joueur donné
    public:
        Board();
        Board(const Board& other);
        ~Board();

        Player nextPlayer(Player currentPlayer) const;
        Player getPlaceHolder(int line, int column);
        Size getPieceSize(int line, int column);
        int getNbPiecesInHouse(Player checkedPlayer, Size pieceSize);

        StatusEnum placePiece(Player currentPlayer, Size pieceSize, int line, int column);
        StatusEnum movePiece(int sourceLine, int sourceColumn, int targetLine, int targetColumn);

        Player getWinner();

        std::ostream& printHouses(std::ostream& stream, Player player);
        friend std::ostream& operator<<(std::ostream& stream, Board& board);

        void printMovablePieces(Player current);
        Cell& getCellAt(int line, int column);

};





#endif // BOARD_H
