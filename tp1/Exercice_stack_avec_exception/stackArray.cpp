#include "stackArray.h"

stackArray::stackArray(int size) : tailleMax(size), head(-1)
{
    data = new int[tailleMax];
}

stackArray::~stackArray()
{
    delete[] data;
}

void stackArray::push(int value)
{
    if (head == tailleMax - 1)
        throw std::out_of_range("Erreur : pile pleine (overflow).");
    data[++head] = value;
}

int stackArray::pop()
{
    if (isEmpty())
        throw std::out_of_range("Erreur : pile vide (underflow).");
    return data[head--];
}

int stackArray::peek() const
{
    if (isEmpty())
        throw std::out_of_range("Erreur : pile vide (peek).");
    return data[head];
}

bool stackArray::isEmpty() const
{
    return head == -1;
}

int stackArray::getSize() const
{
    return head + 1;
}
