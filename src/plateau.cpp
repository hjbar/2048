#include "plateau.hpp"


/** Fonction aleaInt
 * @param a un entier représentant le minimum du nombre aléatoire généré
 * @param b un entier représentant le maximum du nombre aléatoire généré
 * @return un entier aléatoire n tel que a <= n <= b
 **/
int aleaint(int a, int b) {
    return rand() % (b - a + 1) + a;
}


/** Genere un nombre aléatoirement entre 2 avec 90% de chance et 4 avec 10% de chance
 * @return 2 ou 4
 **/
int genere_nombre(){
   int chiffre = aleaint(1,10);
   if(chiffre == 10) {
      return 4;
   }
   return 2;
}


/** Initialise un nouveau plateau de jeu
 * @return tab
 **/
Plateau init_plateau(int nombre){
   Plateau tab;
   tab = Plateau(4);
   for(int i = 0 ; i < 4 ; i++) {
      tab[i] = vector<int>(4);
      for(int j = 0 ; j < 4 ; j++) {
         tab[i][j] = 0;
      }
   }
   int x = aleaint(0,3);
   int y = aleaint(0,3);
   tab[x][y] = nombre;
   return tab;
}


Plateau ajoute_nombre_plateau(Plateau tab, int nombre) {
   bool case_libre = false;
   while(not case_libre) {
      int x = aleaint(0, 3);
      int y = aleaint(0, 3);
      if(tab[x][y] == 0){
         tab[x][y] = nombre;
         case_libre = true;
      }
   }
   return tab;
}
