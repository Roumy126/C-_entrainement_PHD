#ifndef STACKARRAY_HPP
#define STACKARRAY_HPP

#include <iostream>
#include <stdexcept>

class stackArray
{
private:
    static const int defaultSize = 50;
    const int tailleMax;
    int head;
    int* data;

public:
    // Constructeurs et destructeur
    stackArray(int size = defaultSize); // constructeur par défaut
    stackArray(const stackArray& other);              // constructeur de copie
    ~stackArray();  // destructeur

    // Méthodes de pile
    void push_to_stack(int value);
    int pop_from_stack();
    int peek_from_stack() const;
    bool isEmpty() const;
    int size_stack() const;
    int count() const;
    void print() const;

    // Opérateurs surchargés
    stackArray& operator=(const stackArray& other);   // affectation
    bool operator==(const stackArray& other) const;
    bool operator!=(const stackArray& other) const;
    stackArray& operator+=(const stackArray& other);

    // Fonctions amies pour opérateurs externes
    friend std::ostream& operator<<(std::ostream& os, const stackArray& p);
    friend stackArray& operator<(stackArray& p, int value);
    friend stackArray& operator>(stackArray& p, int& value);
};

#endif
