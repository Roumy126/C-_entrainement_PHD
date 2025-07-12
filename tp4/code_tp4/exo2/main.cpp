#include "Cercle.hpp"
#include "Triangle.hpp"

void afficheDesc(Forme& f) {
    f.description();
    cout << "Aire : " << f.aire() << endl;
}

int main() {
    Cercle c(5);
    Triangle t(10, 2);

    afficheDesc(c);
    afficheDesc(t);

    return 0;
}
