#ifndef CELL_H
#define CELL_H

#include "config.h"
#include "piece.h"

//Acts as a stack, where only larger pieces can be pushed.
class Cell
{
    private:
        Piece stack[NB_SIZE];
        //std::vector<Piece> stack;
        int index;
    public:
        Cell();
        Cell(const Cell& other);  // Copy constructor

        bool canPush(const Piece& piece); // Checks if a piece can be pushed onto the stack
        void push(const Piece& piece); // Pushes a piece onto the stack if it can be pushed
        bool canPop(); // Checks if a piece can be popped from the stack
        Piece& pop(); // Pops a piece from the stack if it can be popped
        Piece& peek(); // Returns the top piece of the stack without removing it

        Cell& operator=(const Cell& other); // Assignment operator for copying a cell
};

#endif // CELL_H





