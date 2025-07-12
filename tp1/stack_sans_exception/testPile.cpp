#include <iostream>
#include "stackArray.h"

int main()
{
    stackArray pile(5); // pile de taille max 5

    std::cout << "Empile 10, 20, 30" << std::endl;
    pile.push(10);
    pile.push(20);
    pile.push(30);

    std::cout << "Sommet : " << pile.peek() << std::endl;
    std::cout << "Taille actuelle : " << pile.getSize() << std::endl;

    std::cout << "Dépile : " << pile.pop() << std::endl;
    std::cout << "Dépile : " << pile.pop() << std::endl;

    std::cout << "Sommet maintenant : " << pile.peek() << std::endl;
    std::cout << "Pile vide ? " << (pile.isEmpty() ? "Oui" : "Non") << std::endl;

    return 0;
}
