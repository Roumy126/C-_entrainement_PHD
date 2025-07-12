#include "BusinessTraveler.hpp"

int main() {
    BusinessTraveler b1("Alice", "Code123");
    cout << endl;

    BusinessTraveler b2 = b1;  // test constructeur de recopie
    cout << endl;

    BusinessTraveler b3("Temp", "TempCode");
    b3 = b1;  // test opérateur d’affectation
    cout << endl;

    cout << "Affichage de b3:" << endl;
    b3.print();

    return 0;
}
