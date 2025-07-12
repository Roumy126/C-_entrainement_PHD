#include "stackArray.hpp"

// Constructeur
stackArray::stackArray(int size) : tailleMax(size), head(-1)
{
    data = new int[tailleMax];
}

// Constructeur de copie
stackArray::stackArray(const stackArray& other) : tailleMax(other.tailleMax), head(other.head)
{
    data = new int[tailleMax];
    for (int i = 0; i <= head; ++i)
        data[i] = other.data[i];
}

// Destructeur
stackArray::~stackArray()
{
    delete[] data;
}

// Empilement
void stackArray::push_to_stack(int value)
{
    if (head == tailleMax - 1)
        throw std::out_of_range("Pile pleine !");
    data[++head] = value;
}

// Dépilement
int stackArray::pop_from_stack()
{
    if (isEmpty())
        throw std::out_of_range("Pile vide !");
    return data[head--];
}

// Lire sommet
int stackArray::peek_from_stack() const
{
    if (isEmpty())
        throw std::out_of_range("Pile vide !");
    return data[head];
}

// Pile vide ?
bool stackArray::isEmpty() const
{
    return head == -1;
}

// Taille max
int stackArray::size_stack() const
{
    return tailleMax;
}

// Nombre d'éléments
int stackArray::count() const
{
    return head + 1;
}

// Affichage simple sans <<
void stackArray::print() const
{
    std::cout << "<";
    for (int i = 0; i <= head; ++i)
    {
        std::cout << data[i];
        if (i != head) std::cout << ", ";
    }
    std::cout << ">" << std::endl;
}

// Opérateur d'affectation =
stackArray& stackArray::operator=(const stackArray& other)
{
    if (this != &other)
    {
        delete[] data;
        head = other.head;
        data = new int[other.tailleMax];
        for (int i = 0; i <= head; ++i)
            data[i] = other.data[i];
    }
    return *this;
}

// Opérateur ==
bool stackArray::operator==(const stackArray& other) const
{
    if (head != other.head)
        return false;
    for (int i = 0; i <= head; ++i)
    {
        if (data[i] != other.data[i])
            return false;
    }
    return true;
}

// Opérateur !=
bool stackArray::operator!=(const stackArray& other) const
{
    return !(*this == other);
}

// Opérateur +=
stackArray& stackArray::operator+=(const stackArray& other)
{
    for (int i = 0; i <= other.head; ++i)
    {
        this->push_to_stack(other.data[i]);
    }
    return *this;
}

// Opérateur <<
std::ostream& operator<<(std::ostream& os, const stackArray& p)
{
    os << "Stack → (size: " << p.count() << ", content: <";
    for (int i = 0; i <= p.head; ++i)
    {
        os << p.data[i];
        if (i != p.head)
            os << ", ";
    }
    os << ">)";
    return os;
}

// Opérateur <
stackArray& operator<(stackArray& p, int value)
{
    p.push_to_stack(value);
    return p;
}

// Opérateur >
stackArray& operator>(stackArray& p, int& value)
{
    value = p.pop_from_stack();
    return p;
}
