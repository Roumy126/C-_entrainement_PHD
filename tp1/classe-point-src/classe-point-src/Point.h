#ifndef POINT_H
#define POINT_H

class Point 
{
   private:
      double x;
      double y;
      static int cpt; // compteur d'instances de la classe Point
      
   public:
      
      // ---- Constructeurs ----
      Point();                        // constructeur par défaut
      Point(double x_, double y_);   // constructeur avec liste d'initialisation
      Point(const Point &p);          // constructeur de copie
      
      

       // ---- Accesseurs (getters) ----
       double getX() const; // retourne la valeur de x
       double getY() const;// retourne la valeur de y

      // ---- Mutateurs (setters) ----
      void setX(double xValue); // modifie la valeur de x
      void setY(double yValue);// modifie la valeur de y

      
      
      // Destructeur  
      ~Point(); // Déclaration seulement 
      
      
      // Services
      void afficher() const;                        // afficher <x,y>
      double distance(const Point &p) const;        // distance entre 2 points
      Point milieu(const Point &p) const;           // milieu entre 2 points

    // ---- Méthode pour accéder au compteur ----
    static int getCompteur(); // renvoie le nombre d'instances

      
};

#endif //POINT_H
