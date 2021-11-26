#include "affichage.hpp"


string couleur_nombre(int nombre) {
   if(nombre <= 4) {
      return green;
   } else if(nombre <= 16) {
      return purple;
   } else if(nombre <= 64) {
      return blue;
   } else if(nombre <= 512) {
      return red;
   } else if(nombre <= 2048) {
      return yellow;
   } else {
      return cyan;
   }
}


string plateau_to_string(Plateau t) {
   ostringstream os;
   os << white "*************************" reset << endl;
   for(vector<int> ligne : t) {
      os << white "*" reset;
      for(int nombre : ligne) {
         // On utilise la biblioteque fmt/core.h presente dans le standard de c++ 2020 qui aligne les nombres correctement sur un format de 5 characteres
         string s = nombre != 0 ? fmt::format("{:^5}", nombre) : "     ";
         os << couleur_nombre(nombre);
         os << s << white "*" reset;
      }
      os << endl << white "*************************" reset << endl;
   }
   return os.str();
}


void affiche_plateau(string plateau){
   cout << plateau;
}
