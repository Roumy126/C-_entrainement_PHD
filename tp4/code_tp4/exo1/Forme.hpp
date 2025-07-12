#ifndef FORME_HPP
#define FORME_HPP

#include <iostream>
using namespace std;

class Forme {
public:
    virtual void description() {
        cout << "Ceci est une forme !" << endl;
    }
    
};

#endif
