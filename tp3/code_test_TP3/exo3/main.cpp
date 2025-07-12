#include <iostream>
#include "VecteurUnitaire.hpp"

int main() {
    Vecteur v1(1, 2, -0.1), v2(2.6, 3.5, 4.1), zero(0, 0, 0);

    std::cout << v1 << " + " << v2 << " = " << v1 + v2 << std::endl;
    std::cout << v1 << " - " << v2 << " = " << v1 - v2 << std::endl;
    std::cout << "-" << v1 << " = " << -v1 << std::endl;
    std::cout << "3 * " << v1 << " = " << 3 * v1 << std::endl;
    std::cout << v1 << " * " << v2 << " = " << (v1 * v2) << std::endl;
    std::cout << "||" << v1 << "|| = " << v1.norme() << std::endl;
    std::cout << "||" << v2 << "|| = " << v2.norme() << std::endl;

    VecteurUnitaire vu(1, 2, -0.1);
    std::cout << "Vecteur unitaire normalisé : " << vu << " (norme = " << vu.norme() << ")" << std::endl;

    return 0;
}
