#include <iostream>
#include <cmath> /* pour sqrt */

using namespace std;

#include "Point.h"


// initialisation de la variable compteur
int Point::cpt = 0; // Initialisation du compteur statique


// Constructeur par defaut
Point::Point()
{
    x = 0;
    y = 0;
    cpt++;
    std::cout << "Je suis le constructeur par défaut de la classe Point !" << std::endl;
    std::cout << "Adresse : " << this << std::endl;
}


// constructeur avec liste d'initialisation
Point::Point(double x_, double y_) : x(x_), y(y_)
{
    cpt++;
    std::cout << "Je suis le constructeur de la classe Point !" << std::endl;
    std::cout << "Adresse : " << this << std::endl;
}


// constructeur de copie 
Point::Point(const Point &p) : x(p.x), y(p.y)
{
    cpt++;
    std::cout << "Je suis le constructeur de copie de la classe Point !" << std::endl;
    std::cout << "Adresse : " << this << std::endl;
}


// Destructeur  
Point::~Point()
{
    cpt--;
    std::cout << "Je suis le destructeur de la classe Point !" << std::endl;
}


// Accesseurs
double Point::getX() const { return x; }
double Point::getY() const { return y; }


// Mutateurs

void Point::setX(double x_) { x = x_; }
void Point::setY(double y_) { y = y_; }


// Services


// Méthode afficher

void Point::afficher() const
{
    std::cout << "<" << x << "," << y << ">" << std::endl;
}


// Méthode distance

double Point::distance(const Point &p) const
{
    double dx = x - p.x;
    double dy = y - p.y;
    return std::sqrt(dx * dx + dy * dy);
}


// Méthode milieu

Point Point::milieu(const Point &p) const
{
    double mx = (x + p.x) / 2.0;
    double my = (y + p.y) / 2.0;
    return Point(mx, my); // renvoie un nouveau point
}


// Méthode statique pour accéder au compteur

int Point::getCompteur()
{
    return cpt;
}


