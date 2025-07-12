#ifndef FORME_HPP
#define FORME_HPP

#include <iostream>
using namespace std;

class Forme {
public:
     virtual void description() const {
        cout << "Ceci est une forme !" << endl;
    };
    
    virtual double aire() = 0;
};

#endif
