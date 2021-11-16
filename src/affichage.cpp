#include "affichage.hpp"

string affiche_plateau(Plateau t) {
   ostringstream fmt;
   fmt << "*************************" << endl;
   for(vector<int> ligne : t) {
      fmt << "*";
      for(int nombre : ligne) {
         if(0 <= nombre and nombre <= 9) {
            fmt << "  " << nombre << "  " << "*";
         } else if(10 <= nombre and nombre <= 99) {
            fmt << " " << nombre << "  " << "*";
         } else if(100 <= nombre and nombre <= 999) {
            fmt << " " << nombre << " " << "*";
         } else if(1000 <= nombre and nombre <= 9999) {
            fmt << nombre << " " << "*";
         } else {
            fmt << nombre << "*";
         }
      }
      fmt << endl;
      fmt << "*************************" << endl;
   }
   cout << fmt.str();
   return fmt.str();
}
