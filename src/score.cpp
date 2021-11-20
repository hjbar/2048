#include "score.hpp"


/** Fonction qui calcule les points donnés par un nombre
 * @param nombre un entier
 * @return le nombre de points obtenus
 **/
int score_nombre(int nombre) {
   int score = 0;
   int coefficient = 1;
   while(nombre > 2) {
      score = score + (nombre * coefficient);
      nombre = (nombre / 2);
      coefficient = (coefficient * 2);
   }
   return score;
}


/** Fonction qui renvoie les points du plateau en fonction du nombre de 4 generes aleatoirement
 * @param tab un plateau de jeu
 * @param nombre_de_quatre un entier correspond un nombre de 4 apparue de maniere aleatoire
 * @return le nombre de points du plateau de jeu
 **/
int score_plateau(Plateau tab, int nombre_de_quatre) {
   int score = 0;
   for(vector<int> ligne : tab) {
      for(int nombre : ligne) {
         score = score + score_nombre(nombre);
      }
   }
   return score - (4*nombre_de_quatre);
}


/** Fonction qui teste si la partie est terminée
 * @param tab un plateau de jeu
 * @return un bool, true si la partie est terminée, false sinon
 **/
bool fin_de_partie(Plateau tab) {
   for(vector<int> ligne : tab) {
      for(int nombre : ligne) {
         if(nombre == 0) {
            return false;
         }
      }
   }
   for(int i = 0 ; i <= 3 ; i++) {
      for(int j = 0 ; j <=2 ; j++) {
         if(tab[i][j] == tab[i][j+1]) {
            return false;
         }
      }
   }
   for(int n = 0 ; n <=2 ; n++) {
      for(int k = 0 ; k <=3 ; k++) {
         if(tab[n][k] == tab[n+1][k]) {
            return false;
         }
      }
   }
   return true;
}
