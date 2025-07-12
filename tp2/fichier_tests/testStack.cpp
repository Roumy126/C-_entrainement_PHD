#include <iostream>
#include <stdexcept> // pour out_of_range
using namespace std;

#include "stackArray.hpp"

int main() 
{
   // Question 1 TP1
   cout << "Test création d'une pile \n";
   stackArray p1(30);
   cout << endl;

   cout << "Test création d'une pile avec taille par défaut \n";
   stackArray p2;
   cout << endl;

   cout << "Test création d'une pile avec new:\n";
   stackArray* p3 = new stackArray(30);
   cout << endl;

   cout << "Test pop d'une pile vide:\n";    
   try {
       p1.pop_from_stack();
   } catch (out_of_range &e) {
       cerr << e.what() << endl;
   }
   cout << endl;

   cout << "Test sommet de pile vide:\n";    
   try {
       p1.peek_from_stack();
   } catch (out_of_range &e) {
       cerr << e.what() << endl;
   }
   cout << endl;

   // Question 2 TP1
   cout << "Empilement d'elements dans p1\n"; 
   p1.push_to_stack(1);
   p1.push_to_stack(2);
   p1.push_to_stack(3);
   p1.push_to_stack(4);   
   cout << endl;

   cout << "Affichage de p1 sans surcharge de l'operateur << \n"; 
   cout << "Contenu de p1 : "; p1.print();
   cout << "Nombre d'éléments présents sur p1 : " << p1.count() << endl;
   cout << "Taille de p1 : " << p1.size_stack() << endl << endl; 

   cout << "Dépilement d'un élément de p1: "; 
   int e = p1.pop_from_stack();
   cout << "Contenu de p1 après dépilement : "; p1.print(); 
   cout << endl; 

   // Question 3 TP1
   cout << "Sommet courant de p1: ";
   try {
       cout << p1.peek_from_stack() << endl << endl; 
   } catch (out_of_range &e) {
       cerr << e.what() << endl << endl; 
   }

   cout << "Empilement d'elements dans p3\n";
   p3->push_to_stack(6);   
   p3->push_to_stack(7);   
   p3->push_to_stack(8); 
   cout << endl;

   // Questions 1 & 2 TP2
   cout << "Affichage de p3 via l'opérateur << \n"; 
   cout << "Contenu de p3: " << *p3 << endl << endl;

   cout << "Affectation de p1 à p2\n"; 
   p2 = p1; 
   cout << "Contenu de p2 : " << p2 << endl << endl; 

   cout << "Affectation de p3 à p1\n"; 
   p1 = *p3; 
   cout << "Contenu de p1 : " << p1 << endl << endl; 

   // Question 3 TP2
   cout << "Test opérateur == entre p1 et p2: "; 
   cout << ((p1 == p2) ? "oui\n\n" : "non\n\n");

   cout << "Test opérateur == entre p1 et p3: "; 
   cout << ((*p3 == p1) ? "oui\n\n" : "non\n\n");

   cout << "Test opérateur != entre p1 et p2: "; 
   cout << ((p1 != p2) ? "p1 différent de p2\n\n" : "p1 égal à p2\n\n");

   cout << "Test opérateur != entre p1 et p3: ";  
   cout << ((p1 != *p3) ? "p1 différent de p3\n\n" : "p1 égal à p3\n\n");

   // Question 4 TP2
   cout << "Empilement de p2 avec p3\n";  
   p2 += *p3;
   cout << "Contenu de p2 : " << p2 << endl << endl;

   cout << "Empilement d'un élément dans p2: ";  
   p2 < 25; 
   cout << "Contenu de p2 : " << p2 << endl << endl;

   cout << "Dépilement du sommet dans p2: ";  
   p2 > e;
   cout << "Contenu de p2 après dépilement de " << e << " : " << p2 << endl << endl;

   cout << "Test pile vide \n";
   while (!p1.isEmpty())
       cout << p1.pop_from_stack() << endl;    
   cout << endl;

   delete p3; 
   return 0;
}
