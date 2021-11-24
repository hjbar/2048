#include "deplacement.hpp"


/** Fonction qui verifie si la direction choisie est valide
 * @param c une chaine de caractere
 * @return true si valide, false sinon
 **/
bool valide_direction(string c) {
   return ( (c == "d") or (c == "g") or (c == "b") or (c == "h") );
}


/** Fonction qui transforme la chaine de caracteres en Direction
 * @param charactere une chaine de caracteres valant d, g, b ou h
 * @return une Direction entre Right / Left / Bottom / Top
 **/
Direction string_to_direction(string charactere) {
   if(charactere == "d") {
      return Right;
   } else if(charactere == "g") {
      return Left;
   } else if(charactere == "b") {
      return Bottom;
   } else {
      return Top;
   }
}


/** Fonction qui decale les nombres sont les additionner
 * @param d une Direction valant Right, Left, Top ou Bottom
 * @param tab un plateau de jeu
 * @return tab modifie
 ***/
Plateau decalage_nombre(Direction d, Plateau tab) {
   if (d == Right) {
      for(int i = 0 ; i < 4 ; i++) {
         for(int _ = 0 ; _ < 3 ; _++) {
            for(int j = 3 ; j > 0 ; j = j - 1) {
               if(tab[i][j] == 0 and tab[i][j-1] != 0) {
                  tab[i][j] = tab[i][j-1];
                  tab[i][j-1] = 0;
               }
            }
         }
      }
   }
   if (d == Left) {
      for(int i = 0 ; i < 4 ; i++) {
         for(int _ = 0 ; _ < 3 ; _++) {
            for(int j = 0 ; j < 3 ; j++) {
               if(tab[i][j] == 0 and tab[i][j+1] != 0) {
                  tab[i][j] = tab[i][j+1];
                  tab[i][j+1] = 0;
               }
            }
         }
      }
   }
   if (d == Bottom) {
      for(int j = 0 ; j < 4 ; j++) {
         for(int _ = 0 ; _ < 3 ; _++) {
            for(int i = 3 ; i > 0 ; i = i - 1) {
               if(tab[i][j] == 0 and tab[i-1][j] != 0) {
                  tab[i][j] = tab[i-1][j];
                  tab[i-1][j] = 0;
               }
            }
         }
      }
   }
   if (d == Top) {
      for(int j = 0 ; j < 4 ; j++) {
         for(int _ = 0 ; _ < 3 ; _++) {
            for(int i = 0 ; i < 3 ; i++) {
               if(tab[i][j] == 0 and tab[i+1][j] != 0) {
                  tab[i][j] = tab[i+1][j];
                  tab[i+1][j] = 0;
               }
            }
         }
      }
   }
   return tab;
}


/** Deplacement une fonction qui simule un deplacement de jeu
 * @param d une Direction valant Right, Left, Top ou Bottom
 * @param tab un plateau de jeu
 * @return tab modifie
 **/
Plateau deplacement(Direction d, Plateau tab) {
   if (d == Right) {
      tab = decalage_nombre(d, tab);
      for(int k = 0 ; k < 4 ; k++) {
         for(int n = 3 ; n > 0 ; n = n - 1) {
            if(tab[k][n] == tab[k][n-1]) {
               tab[k][n] = tab[k][n] + tab[k][n-1];
               tab[k][n-1] = 0;
            }
         }
      }
      tab = decalage_nombre(d, tab);
   }
   if (d == Left) {
      tab = decalage_nombre(d, tab);
      for(int k = 0 ; k < 4 ; k++) {
         for(int n = 0 ; n < 3 ; n++) {
            if(tab[k][n] == tab[k][n+1]) {
               tab[k][n] = tab[k][n] + tab[k][n+1];
               tab[k][n+1] = 0;
            }
         }
      }
      tab = decalage_nombre(d, tab);
   }
   if (d == Bottom) {
      tab = decalage_nombre(d, tab);
      for(int k = 3 ; k > 0 ; k = k - 1) {
         for(int n = 0 ; n < 4 ; n++) {
            if(tab[k][n] == tab[k-1][n]) {
               tab[k][n] = tab[k][n] + tab[k-1][n];
               tab[k-1][n] = 0;
            }
         }
      }
      tab = decalage_nombre(d, tab);
   }
   if (d == Top) {
      tab = decalage_nombre(d , tab);
      for(int k = 0 ; k < 3 ; k++) {
         for(int n = 0 ; n < 4 ; n++) {
            if(tab[k][n] == tab[k+1][n]) {
               tab[k][n] = tab[k][n] + tab[k+1][n];
               tab[k+1][n] = 0;
            }
         }
      }
      tab = decalage_nombre(d, tab);
   }
   return tab;
}


bool deplacement_possible(Direction d, Plateau tab) {
   return not(tab == deplacement(d, tab));
}
