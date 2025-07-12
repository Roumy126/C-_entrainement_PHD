#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include "Point3D.hpp"

class Vecteur : public Point3D {
public:
    Vecteur(double x = 0, double y = 0, double z = 0) : Point3D(x, y, z) {}

    Vecteur& operator+=(const Vecteur& v) {
        x += v.x; y += v.y; z += v.z;
        return *this;
    } // Opérateur d'addition

    Vecteur& operator-=(const Vecteur& v) {
        x -= v.x; y -= v.y; z -= v.z;
        return *this;
    } // Opérateur de soustraction

    friend const Vecteur operator+(Vecteur v1, const Vecteur& v2) {
        return v1 += v2;
    }   // Opérateur d'addition

    friend const Vecteur operator-(Vecteur v1, const Vecteur& v2) {
        return v1 -= v2;
    }  // Opérateur de soustraction

    const Vecteur operator-() const {
        return Vecteur(-x, -y, -z);
    } // Opérateur unaire de négation

    Vecteur& operator*=(double a) {
        x *= a; y *= a; z *= a;
        return *this;
    } // Opérateur de multiplication par un scalaire

    friend const Vecteur operator*(Vecteur v, double a) {
        return v *= a;
    } 

    friend const Vecteur operator*(double a, const Vecteur& v) {
        return Vecteur(v.x * a, v.y * a, v.z * a);
    }

    friend double operator*(const Vecteur& v1, const Vecteur& v2) {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    double norme() const {
        return std::sqrt((*this) * (*this));
    }
};

#endif
