#ifndef POINT3D_HPP
#define POINT3D_HPP

#include <iostream>
#include <cmath>

class Point3D {
protected:
    double x, y, z;

public:
    Point3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

    bool operator==(const Point3D& other) const {
        return x == other.x && y == other.y && z == other.z;
    } // Opérateur d'égalité
    friend std::ostream& operator<<(std::ostream& os, const Point3D& p) {
        os << "(" << p.x << ", " << p.y << ", " << p.z << ")";
        return os;
    } // Opérateur d'affichage
};

#endif
