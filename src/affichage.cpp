#include "affichage.hpp"


/** Tranforme le plateau en chaine de cracteres
 * @param t de type Plateau qui correspond au plateau de jeu
 * @return os.str() qui correspond au plateau de jeu sous forme de chaine de caracteres
 **/
string plateau_to_string(Plateau t) {
   ostringstream os;
   os << "*************************" << endl;
   for(vector<int> ligne : t) {
      os << "*";
      for(int nombre : ligne) {
         string s = nombre != 0 ? fmt::format("{:^5}", nombre) : "     ";
         os << s << "*";
      }
      os << endl << "*************************" << endl;
   }
   return os.str();
}


/** Affiche le plateau de jeu
 * @param plateau une chaine de caracteres correspondant au plateau
 * **/
void affiche_plateau(string plateau){
   cout << plateau;
}
