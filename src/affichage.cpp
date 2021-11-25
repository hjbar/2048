#include "affichage.hpp"


string plateau_to_string(Plateau t) {
   ostringstream os;
   os << "*************************" << endl;
   for(vector<int> ligne : t) {
      os << "*";
      for(int nombre : ligne) {
         // On utilise la biblioteque fmt/core.h presente dans le standard de c++ 2020 qui aligne les nombres correctement sur un format de 5 characteres
         string s = nombre != 0 ? fmt::format("{:^5}", nombre) : "     ";
         os << s << "*";
      }
      os << endl << "*************************" << endl;
   }
   return os.str();
}


void affiche_plateau(string plateau){
   cout << plateau;
}
