#ifndef FORME_HPP
#define FORME_HPP

#include <iostream>
using namespace std;

class Forme {
public:
    virtual void affiche() const = 0;
    virtual Forme* copie() const = 0; //une m´ethode Forme* copie() const,  virtuelle pure, charg´ee de faire une copie en m´emoire de l’objet et de retourner le pointeur sur cette copie
    virtual ~Forme() {} // un destructeur virtuel pour assurer la destruction correcte des objets dérivés
    
};

#endif
