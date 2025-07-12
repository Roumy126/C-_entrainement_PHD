#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "Constructeur A" << endl; }
    ~A() { cout << "Destructeur A" << endl; }
};

class B : public A {
public:
    B() { cout << "Constructeur B" << endl; }
    ~B() { cout << "Destructeur B" << endl; }
};

class C : public B {
public:
    C() { cout << "Constructeur C" << endl; }
    ~C() { cout << "Destructeur C" << endl; }
};

int main() {
    C obj; //Appel des constructeurs de la base vers le dérivé   À la destruction, ordre inverse (du dérivé vers la base)
    return 0;
}
