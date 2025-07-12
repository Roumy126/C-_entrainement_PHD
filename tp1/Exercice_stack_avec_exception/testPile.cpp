#include <iostream>
#include "stackArray.h"

int main()
{
    try {
        stackArray pile(2); // pile de taille 2

        std::cout << "Empile 10" << std::endl;
        pile.push(10);
        std::cout << "Empile 20" << std::endl;
        pile.push(20);

        std::cout << "Tentative d'empiler 30 (devrait échouer)" << std::endl;
        pile.push(30); // devrait lancer une exception

    } catch (const std::out_of_range& e) {
        std::cerr << "Exception capturée : " << e.what() << std::endl;
    }

    try {
        stackArray pile2(2);
        std::cout << "Dépile une pile vide (devrait échouer)" << std::endl;
        pile2.pop();
    } catch (const std::out_of_range& e) {
        std::cerr << "Exception capturée : " << e.what() << std::endl;
    }

    return 0;
}
