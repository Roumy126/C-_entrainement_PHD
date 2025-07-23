#include "piece.h"

Piece::Piece() : owner(NO_PLAYER), size(NONE) {}  // Default constructor initializes an empty piece
Piece::Piece(Player owner, Size size) : owner(owner), size(size) {} // Constructor with parameters initializes a piece with given owner and size
Piece::Piece(const Piece& other) : owner(other.owner), size(other.size) {} // Copy constructor initializes a piece from another piece

Player Piece::getOwner() const { return owner; } // Returns the owner of the piece
Size Piece::getSize() const { return size; } // Returns the size of the piece

Piece& Piece::operator=(const Piece& other) {
    if (this != &other) {
        owner = other.owner;
        size = other.size;
    }
    return *this;
}   // Assignment operator allows copying a piece into another