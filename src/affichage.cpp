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


/** Affiche le plateau de jeu ou le renvoie sous forme de chaine de caracteres
 * @param role une chaine de caracteres qui correspond au role de la fonction
 * @param t de type Plateau qui correspond au plateau de jeu
 * @return os.str() qui correspond au plateau de jeu sous forme de chaine de caracteres si role est egal a test
 **/
string affiche_plateau(string role, Plateau t) {
   ostringstream os;
   os << "*************************" << endl;
   for(vector<int> ligne : t) {
      os << "*";
      for(int nombre : ligne) {
         if(nombre > 0){
         int pos = ((5-taille_nombre(nombre))/2);
         if(pos > 0) {
         os << setw(pos) << " " << setw(5-pos) << left << nombre << "*";
         } else {
            os << setw(5) << left << nombre << "*";
         }
         } else {
            os << setw(5) << " " << "*";
         }
      }
      os << endl << "*************************" << endl;
   }
   if(role == "test") {
      return os.str();
   }
   cout << os.str();
   return "";
}


/** Effectue une serie de test sur la fonction affiche_plateau **/
void test_affiche_plateau() {
   assert(affiche_plateau("test", {{2,4,8,16}, {32,64,128,256}, {512,1024,2048,4096}, {2,2,2,2}}) == "*************************\n*  2  *  4  *  8  * 16  *\n*************************\n* 32  * 64  * 128 * 256 *\n*************************\n* 512 *1024 *2048 *4096 *\n*************************\n*  2  *  2  *  2  *  2  *\n*************************");
}
