#include <iostream>
#include <iomanip>

using namespace std;

#include "Point.h"

int main() 
{
   /* Question 1 */
   
   cout << "Question 1 : constructeur par défaut" << endl;   
   Point p0;
   cout << "Adresse de p0 : " << &p0 << endl; // Affiche l'adresse de l'objet p0
   cout << "cpt = " << Point::getCompteur() << endl; // Affiche le compteur d'instances de la classe Point

   
   
   /* Question 3 */ 
   
   cout << endl ;   
   cout << "Q3 : constructeur avec liste d'initialisation" << endl;   
   Point p1(2.0, 3.0);
   Point p2(2., 1.); 
   cout << "Adresse de p1 : " << &p1 << endl; // Affiche l'adresse de l'objet p1
   cout << "Adresse de p2 : " << &p2 << endl; // Affiche l'adresse de l'objet p2
   cout << "cpt = " << Point::getCompteur() << endl; // Affiche le compteur d'instances de la classe Point
  
 
 
    
    
    /* Question 4 */  
   cout << endl ;   
   cout << "Q4 : constructeur de copie de la classe Point !" << endl;   
   Point p3(p1);	
   cout << "Adresse de p3 : " << &p3 << endl; // Affiche l'adresse de l'objet p3
   cout << "cpt = " << Point::getCompteur() << endl; // Affiche le compteur d'instances de la classe Point
   

   
 




    /* Question 5 */  
   cout << endl ;  
   cout << "cpt = " << Point::getCompteur() << endl; 
   
	{ 
	  Point p4(1,1); 
	  cout << "cpt = " << Point::getCompteur() << endl; cout << endl ;  
	  Point p5(p4); 
	  cout << "cpt = " << Point::getCompteur() << endl; cout << endl ;  
	}
	cout << "cpt = " << Point::getCompteur() << endl;  cout << endl ;  
   // Le compteur d'instances de la classe Point est décrémenté lorsque les objets p4 et p5 sortent de la portée (scope) de la fonction main.
   // Cela signifie que le destructeur de ces objets est appelé, ce qui réduit le compteur d'instances de la classe Point de 1 pour chaque objet détruit.
   // Ainsi, après la destruction de p4 et p5, le compteur d'instances de la classe Point est réduit de 2, car deux objets de type Point ont été créés dans la portée de la fonction main.
   // Le compteur d'instances de la classe Point est donc décrémenté de 2 lorsque les objets p4 et p5 sortent de la portée de la fonction main. 

 
   /* Question 6 */  
   
   cout << "Q6 : accesseurs et mutateurs" << endl;   

   cout << "L'abscisse de p0 est " << p0.getX() << endl;   
   cout << "L'abscisse de p1 est " << p1.getX() << endl;
   cout << endl; 
   
   cout << "L'ordonnée de p0 est " << p0.getY() << endl;   
   cout << "L'ordonnée de p1 est " << p1.getY() << endl;
   cout << endl; 

   p0.setX(1.5);
   cout << "L'abscisse de p0 est maintenant " << p0.getX() << endl;   
   p0.setY(3.5);
   cout << "L'ordonnée de p0 est maintenant " << p0.getY() << endl;   
   cout << endl; 
   
   
   
   
   /* Question 7 */
   cout << "Q7 : allocation dynamique" << endl;  
   Point *p4; // variable pointeur non initialisé sur un objet de type Point
   p4 = new Point(1.,1.); // allouer dynamiquement un objet de type Point
   
   // Comme p4 est une adresse, il faut utiliser l'opérateur -> pour accéder aux membres de cet objet
   cout << "L'abscisse de p4 est " << p4->getX() << endl;   
   p4->setY(0); 
   cout << "L'ordonnée de p4 est " << p4->getY() << endl;
   delete p4; // il faut libérer la mémoire allouée pour cet objet
   cout << endl; 
   // Note: Il est important de libérer la mémoire allouée dynamiquement pour éviter les fuites de mémoire.
   // Le pointeur p4 est maintenant invalide, car il pointe vers un objet qui a été détruit.
   // Il est donc recommandé de le mettre à nullptr pour éviter d'accéder à une adresse mémoire invalide.
   p4 = nullptr; // Mettre le pointeur à nullptr pour éviter d'accéder à une adresse mémoire invalide
   cout << "p4 est maintenant un pointeur nul : " << p4 << endl; // Affiche l'adresse du pointeur p4, qui est maintenant nullptr
   cout << endl;
   
   
   
   /* Question 8 */
   
   cout << "Q8 : tableau d'objets" << endl;   
   
   Point *Points;
   Points = new Point[10];
   
   cout << "Un tableau de 10 Point : " << endl;
   for(int i = 0; i < 10; i++)
   {
      cout << "P" << i << " = <" << Points[i].getX() << "," << Points[i].getY() << ">\n";
   }
   
   delete [] Points; 
   cout << endl; 
   // Note: Il est important de libérer la mémoire allouée pour le tableau d'objets 
   Points = nullptr; // Mettre le pointeur à nullptr pour éviter d'accéder à une adresse mémoire invalide
   cout << "Points est maintenant un pointeur nul : " << Points << endl; // Affiche l'adresse du pointeur Points, qui est maintenant nullptr
   cout << endl;
   
   
   
   
   /* Question 9 */
   
   cout << "Q9 : objet constant" << endl;   
   const Point p5(3., 6.);
   cout << "L'abscisse de p4 est " << p5.getX() << endl;
   //p5.setX(5.);
   cout << "L'ordonnée de p4 est " << p5.getY() << endl;      
   cout << endl; 
   // Note: Les méthodes d'accès (getters) peuvent être utilisées sur des objets constants, mais les méthodes de modification (setters) ne peuvent pas être utilisées.  
   // Cela garantit que les objets constants ne peuvent pas être modifiés, ce qui est utile pour protéger les données et éviter les erreurs de programmation.
   // Les objets constants sont souvent utilisés pour représenter des valeurs qui ne doivent pas être modifiées, comme les constantes mathématiques ou les paramètres de configuration.


   /* Question 10 */
   cout << "Q10 : test services de la classe Point" << endl;   
   cout << "p0 = ";
   p0.afficher();
   cout << "p1 = ";
   p1.afficher();
   cout << "p2 = ";
   p2.afficher();
   cout << endl;
   

   cout << "calcul de la distance entre 2 points" << endl;   
   double distance = p1.distance(p2);
   cout << "La distance entre p1 et p2 est de " << distance << endl;
   cout << endl;
  
   Point pm = p1.milieu(p2);   
   cout << "Le point milieu entre p1 et p2 est "; 
   pm.afficher();
   cout << endl;

   

   
   return 0;
}
