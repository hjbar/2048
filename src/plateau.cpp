#include "plateau.hpp"


/** Fonction qui sert à faire fonctionner la fonction random_int
 * @return ((float) rnd / (float) RAND_MAX)
 **/
float random_float(void) {
   const int rnd = rand();
   return ((float) rnd / (float) RAND_MAX);
}


/** Fonction random_int
 * @param min un entier représentant le minimum du nombre aléatoire généré
 * @param max un entier représentant le maximum du nombre aléatoire généré
 * @return un entier aléatoire n tel que min <= n <= max
 **/
int random_int(const int min, const int max) {
    return (int) ((float) min + ((float) (max - min + 1) * random_float()));
}


/** Genere un nombre aléatoirement entre 2 avec 90% de chance et 4 avec 10% de chance
 * @return 2 ou 4
 **/
int genere_nombre(){
   return random_int(1, 10) == 10 ? 4 : 2;
}


/** Initialise un nouveau plateau de jeu
 * @param nombre un entier
 * @return tab
 **/
Plateau init_plateau(const int nombre){
   Plateau tab = Plateau(4);
   for(int i = 0 ; i < 4 ; i++) {
      tab[i] = vector<int>(4);
      for(int j = 0 ; j < 4 ; j++) {
         tab[i][j] = 0;
      }
   }
   int x = random_int(0,3);
   int y = random_int(0,3);
   tab[x][y] = nombre;
   return tab;
}


/** Ajoute un nomdre dans la plateau
 * @param tab un Plateau
 * @param nombre un entier
 * @return tab avec un nombre en plus
 **/
Plateau ajoute_nombre_plateau(Plateau tab, int nombre) {
   bool case_libre = false;
   while(not case_libre) {
      int x = random_int(0,3);
      int y = random_int(0,3);
      if(tab[x][y] == 0) {
         tab[x][y] = nombre;
         case_libre = true;
      }
   }
   return tab;
}
