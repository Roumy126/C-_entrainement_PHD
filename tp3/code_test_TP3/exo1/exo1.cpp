#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "Constructeur A" << endl; }
};

class B {
public:
    B() { cout << "Constructeur B" << endl; }
};

class C : public A {
    B b;
    // Pas de constructeur
};

int main() {
    C obj; //C appelle le constructeur de A, puis celui de B automatiquement
    return 0;
}
