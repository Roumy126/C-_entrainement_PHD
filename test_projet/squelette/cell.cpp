#include "cell.h"

Cell::Cell() : index(-1) {}

Cell::Cell(const Cell& other) : index(other.index) {
    for (int i = 0; i <= index; ++i) {
        stack[i] = other.stack[i];
    }
}

bool Cell::canPush(const Piece& piece) {
    if (index == -1) return true;
    return piece.getSize() > stack[index].getSize();
}

void Cell::push(const Piece& piece) {
    if (canPush(piece) && index < NB_SIZE - 1) {
        stack[++index] = piece;
    }
}

bool Cell::canPop() {
    return index >= 0;
}

Piece& Cell::pop() {
    return stack[index--];
}

Piece& Cell::peek() {
    return stack[index];
} // Returns the top piece of the stack without removing it

Cell& Cell::operator=(const Cell& other) {
    if (this != &other) {
        index = other.index;
        for (int i = 0; i <= index; ++i) {
            stack[i] = other.stack[i];
        }
    }
    return *this;
}  // Assignment operator for copying a cell
