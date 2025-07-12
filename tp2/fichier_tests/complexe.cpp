#include "complexe.hpp"

// Constructeur
Complexe::Complexe(double r, double i) : re(r), im(i) {}

// Accesseurs
double Complexe::getRe() const { return re; }
double Complexe::getIm() const { return im; }

// Opérateurs internes
Complexe& Complexe::operator+=(const Complexe& c)
{
    re += c.re;
    im += c.im;
    return *this;
}

Complexe& Complexe::operator+=(double x)
{
    re += x;
    return *this;
}

Complexe& Complexe::operator-=(const Complexe& c)
{
    re -= c.re;
    im -= c.im;
    return *this;
}

Complexe& Complexe::operator*=(const Complexe& c)
{
    double r = re * c.re - im * c.im;
    double i = re * c.im + im * c.re;
    re = r;
    im = i;
    return *this;
}

Complexe& Complexe::operator*=(double x)
{
    re *= x;
    im *= x;
    return *this;
}

Complexe& Complexe::operator/=(const Complexe& c)
{
    double denom = c.re * c.re + c.im * c.im;
    double r = (re * c.re + im * c.im) / denom;
    double i = (im * c.re - re * c.im) / denom;
    re = r;
    im = i;
    return *this;
}

Complexe& Complexe::operator/=(double x)
{
    re /= x;
    im /= x;
    return *this;
}

// Opérateur ==
bool Complexe::operator==(const Complexe& c) const
{
    return re == c.re && im == c.im;
}

// Opérateur <<
std::ostream& operator<<(std::ostream& os, const Complexe& c)
{
    os << "(" << c.re << "," << c.im << ")";
    return os;
}

// Opérateurs externes

Complexe operator+(const Complexe& a, const Complexe& b)
{
    Complexe res(a);
    res += b;
    return res;
}

Complexe operator+(const Complexe& a, double x)
{
    Complexe res(a);
    res += x;
    return res;
}

Complexe operator+(double x, const Complexe& b)
{
    return b + x;
}

Complexe operator-(const Complexe& a, const Complexe& b)
{
    Complexe res(a);
    res -= b;
    return res;
}

Complexe operator*(const Complexe& a, const Complexe& b)
{
    Complexe res(a);
    res *= b;
    return res;
}

Complexe operator*(const Complexe& a, double x)
{
    Complexe res(a);
    res *= x;
    return res;
}

Complexe operator*(double x, const Complexe& b)
{
    return b * x;
}

Complexe operator/(const Complexe& a, const Complexe& b)
{
    Complexe res(a);
    res /= b;
    return res;
}

Complexe operator/(const Complexe& a, double x)
{
    Complexe res(a);
    res /= x;
    return res;
}
