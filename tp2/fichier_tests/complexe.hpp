#ifndef COMPLEXE_HPP
#define COMPLEXE_HPP

#include <iostream>

class Complexe
{
private:
    double re; // partie réelle
    double im; // partie imaginaire

public:
    // Constructeurs
    Complexe(double r = 0.0, double i = 0.0);

    // Accesseurs
    double getRe() const;
    double getIm() const;

    // Opérateurs internes
    Complexe& operator+=(const Complexe& c);
    Complexe& operator+=(double x);
    Complexe& operator-=(const Complexe& c);
    Complexe& operator*=(const Complexe& c);
    Complexe& operator*=(double x);
    Complexe& operator/=(const Complexe& c);
    Complexe& operator/=(double x);

    // Opérateur ==
    bool operator==(const Complexe& c) const;

    // Amis pour opérateurs externes
    friend std::ostream& operator<<(std::ostream& os, const Complexe& c);
    friend Complexe operator+(const Complexe& a, const Complexe& b);
    friend Complexe operator+(const Complexe& a, double x);
    friend Complexe operator+(double x, const Complexe& b);
    friend Complexe operator-(const Complexe& a, const Complexe& b);
    friend Complexe operator*(const Complexe& a, const Complexe& b);
    friend Complexe operator*(const Complexe& a, double x);
    friend Complexe operator*(double x, const Complexe& b);
    friend Complexe operator/(const Complexe& a, const Complexe& b);
    friend Complexe operator/(const Complexe& a, double x);
};

#endif
