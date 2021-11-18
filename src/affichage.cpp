#include "affichage.hpp"


/** Calcul la longeur d'un entier
 * @param nombre un entier
 * @return taille, la longeur d'un entier
 **/
int taille_nombre(int nombre) {
   int taille = 1;
   while(nombre >= 10) {
      nombre = nombre / 10;
      taille++;
   }
   return taille;
}


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
         if(nombre > 0){
            const int pos = 3 - ((1+taille_nombre(nombre))/2); // vaut 2 si taille_nombre = 1 ou 2, vaut 1 si taille_nombre = 3 ou 4
            os << setw(5-pos) << right << nombre << setw(pos) << " " << "*";
         } else {
            os << setw(5) << " " << "*";
         }
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


/** Effectue une serie de test sur la fonction affiche_plateau **/
void test_plateau_to_string() {
   assert(plateau_to_string({{2,4,8,16}, {32,64,128,256}, {512,1024,2048,4096}, {2,2,2,2}}) == "*************************\n*  2  *  4  *  8  * 16  *\n*************************\n* 32  * 64  * 128 * 256 *\n*************************\n* 512 *1024 *2048 *4096 *\n*************************\n*  2  *  2  *  2  *  2  *\n*************************");
}
