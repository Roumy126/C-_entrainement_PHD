#ifndef CERCLE_HPP
#define CERCLE_HPP

#include "Forme.hpp"

class Cercle : public Forme {
public:
    void description() override {
        cout << "Ceci est un cercle." << endl;
    }
};

#endif
