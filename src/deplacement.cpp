#include "deplacement.hpp"


/** Deplacement une fonction qui simule un deplacement de jeu
 * @param direction une chaine de caractere valant Right, Left, Top, Bottom
 * @param tab un plateau de jeu
 * @return tab modifie
 **/
Plateau deplacement(Direction d, Plateau tab) {
   if (d == Right) {
      for(int i = 3 ; i >= 0 ; i = i - 1) {
         for(int j = 3 ; j >= 1 ; j = j - 1) {
            if(tab[i][j] == tab[i][j-1]) {
              tab[i][j] = tab[i][j] + tab[i][j-1];
               tab[i][j-1] = 0;
            }
         }
      }
      for(int k = 3 ; k >= 0 ; k = k - 1) {
         for(int n = 3 ; n >= 1 ; n = n - 1) {
            if(tab[k][n-1] > 0 and tab[k][n] == 0) {
               tab[k][n] = tab[k][n-1];
               tab[k][n-1] = 0;
            }
         }
      }
      for(int q = 0 ; q < 4 ; q++) {
         for(int w = 0 ; w < 3 ; w++) {
            if(tab[q][w] > 0 and tab[q][w+1] == 0) {
               tab[q][w+1] = tab[q][w];
               tab[q][w] = 0;
            }
         }
      }
   }
   return tab;
}
