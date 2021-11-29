#include "affichage.hpp"
#include <algorithm>


string couleur_nombre(int nombre) {
   if(nombre <= 4) {
      return GREEN;
   } else if(nombre <= 16) {
      return PURPLE;
   } else if(nombre <= 64) {
      return BLUE;
   } else if(nombre <= 512) {
      return RED;
   } else if(nombre <= 2048) {
      return YELLOW;
   } else {
      return CYAN;
   }
}


string plateau_to_string(Plateau t) {
   ostringstream os;
   os << "*************************" << endl;
   for(vector<int> ligne : t) {
      os << "*";
      for(int nombre : ligne) {
         // On utilise une biblioteque externe fmt/core.h qui permet d'implementer la biblioteque stdlib::fmt qui est presente dans le standard de c++ 2020 (mais non implementer dans le compilateur g++) qui permet d'aligne les nombres correctement sur un format de 5 characteres
         string s = nombre != 0 ? fmt::format("{:^5}", nombre) : "     ";
         os << s << "*";
      }
      os << endl << "*************************" << endl;
   }
   return os.str();
}


string plateau_to_string_avec_couleur(Plateau t) {
  ostringstream os;
  os << WHITE << "*************************" << RESET_COLOR << endl;
  for(vector<int> ligne : t) {
     os << WHITE << "*" << RESET_COLOR;
     for(int nombre : ligne) {
        // On utilise une biblioteque externe fmt/core.h qui permet d'implementer la biblioteque stdlib::fmt qui est presente dans le standard de c++ 2020 (mais non implementer dans le compilateur g++) qui permet d'aligne les nombres correctement sur un format de 5 characteres
        string s = nombre != 0 ? fmt::format("{:^5}", nombre) : "     ";
        os << couleur_nombre(nombre);
        os << s << WHITE << "*" << RESET_COLOR;
     }
     os << endl << WHITE << "*************************" << RESET_COLOR << endl;
  }
  return os.str();
}


void affiche_plateau(string plateau){
   cout << plateau;
}
