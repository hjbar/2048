#include "affichage.hpp"

void affiche_plateau(Plateau t) {
   cout << "*************************" << endl;
   for(auto ligne : t) {
      cout << "*";
      for(auto nombre : ligne) {
         if(0 <= nombre and nombre <= 9) {
            cout << "  " << nombre << "  " << "*";
         } else if(10 <= nombre and nombre <= 99) {
            cout << " " << nombre << "  " << "*";
         } else if(100 <= nombre and nombre <= 999) {
            cout << " " << nombre << " " << "*";
         } else if(1000 <= nombre and nombre <= 9999) {
            cout << nombre << " " << "*";
         } else {
            cout << nombre << "*";
         }
      }
      cout << endl;
      cout << "*************************" << endl;
   }
}
