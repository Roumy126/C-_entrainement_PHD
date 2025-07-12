#include "stackArray.h"
#include <cstdlib>  // pour exit()

// Constructeur
stackArray::stackArray(int size) : tailleMax(size), head(-1)
{
    data = new int[tailleMax];
}

// Destructeur
stackArray::~stackArray()
{
    delete[] data;
}

// push
void stackArray::push(int value)
{
    if (head == tailleMax - 1)
    {
        std::cerr << "Erreur : pile pleine (overflow)." << std::endl;
        exit(1);
    }
    head++;
    data[head] = value;
}

// pop
int stackArray::pop()
{
    if (isEmpty())
    {
        std::cerr << "Erreur : pile vide (underflow)." << std::endl;
        exit(1);
    }
    return data[head--];
}

// peek
int stackArray::peek() const
{
    if (isEmpty())
    {
        std::cerr << "Erreur : pile vide (peek impossible)." << std::endl;
        exit(1);
    }
    return data[head];
}

// isEmpty
bool stackArray::isEmpty() const
{
    return head == -1;
}

// getSize
int stackArray::getSize() const
{
    return head + 1;
}
