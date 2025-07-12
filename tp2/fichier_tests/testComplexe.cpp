#include <iostream>
#include "complexe.hpp"

using namespace std;

int main()
{
    
    //********  Question 2
    Complexe defaut;
    Complexe zero (0.0, 0.0) ;
    Complexe un (1.0, 0.0) ;
    Complexe i (0.0, 1.0) ;
    Complexe j ;

    //********  Question 3
  
    cout << "Test égalité entre complexes" << endl;
    cout << zero << "== ? " << defaut ;

    if (zero == defaut)
        cout << " oui " << endl ;
    else
        cout << " non " << endl ;

    cout << zero << " == ? " << i ;
    if (zero == i)
        cout << " oui " << endl ;
    else
        cout << " non " << endl ;
    

    //********  Question 4
    
    cout << "Test somme de deux complexes" << endl;
    j = un + i ;
    cout << un << " + " << i << " = " << j << endl << endl ;
    


    //********  Question 4
    
    cout << "Test operateur +=" << endl;
    Complexe trois(un) ;
    trois += un ;
    trois += 1.0 ;
    cout << un << " + " << un << " + " << un << " = " << trois << endl << endl;
    


    //********  Question 4
    
    cout << "Test operateur -=" << endl;
    Complexe deux(trois) ;
    deux -= un ;
    cout << trois << " - " << un << " = " << deux << endl << endl;

    trois = 1.0 + deux ;
    cout << un << " + " << deux << " = " << trois << endl << endl;
    

    //********  Question 5
    
    cout << "Test operateurs *= and /=" << endl;
    Complexe z(i*i);
    cout << i << " * " << i << " = " << z << endl;
    cout << z << " / " << i << " = " << z/i << " = ";
    cout << (z/=i) << endl << endl;
    
    Complexe k(2.0,-3.0);
    z = k;
    z *= 2.0;
    z *= i;
    cout << k << " * 2.0 * " << i << " = " << z << endl;
    z = 2.0 * k * i / 1.0;
    cout << " 2.0 * " << k << " * " << i << " / 1 = " << z << endl;
    

    return 0;
}

