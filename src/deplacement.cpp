#include "deplacement.hpp"


char getch(void) {
   char buf = 0;
   struct termios old = {};
   if (tcgetattr(0, &old) < 0){
      perror("tcsetattr()");
   }
   old.c_lflag &= ~ICANON;
   old.c_lflag &= ~ECHO;
   old.c_cc[VMIN] = 1;
   old.c_cc[VTIME] = 0;
   if (tcsetattr(0, TCSANOW, &old) < 0){
      perror("tcsetattr ICANON");
   }
   if (read(0, &buf, 1) < 0){
      perror ("read()");
   }
   old.c_lflag |= ICANON;
   old.c_lflag |= ECHO;
   if (tcsetattr(0, TCSADRAIN, &old) < 0){
      perror ("tcsetattr ~ICANON");
   }
   return (buf);
}


char recupere_commande(void) {
   char a = getch();

   if(a == 'h' or a == 'b' or a == 'g' or a == 'd' or a =='q') {
      return a;
   }

   if(a != '') {
      // renvoyer 'n' ici permet de demander qu'un seul charactere si ce qu'il a ete entre n'est pas une fleche
      return 'n';
   }

   char b = getch();
   char c = getch();


   if(a == '' and b == '[') {
      // correspond a la fleche du haut
      if(c == 'A') {
         return 'h';
      // correspond a la fleche du bas
      } else if(c == 'B') {
         return 'b';
      // correspond a la fleche de droite
      } else if(c == 'C') {
         return 'd';
      // correspond a la fleche de gauche
      } else if (c == 'D') {
         return 'g';
      }
   }
   // renvoyer 'n' si le charactere n'est pas valide permet d'initialiser dir.value() à None et donc de refaire un tour de boucle
   return 'n';
}


optional<Direction> char_to_direction(const char charactere) {
   if(charactere == 'd') {
      return Right;
   } else if(charactere == 'g') {
      return Left;
   } else if(charactere == 'b') {
      return Bottom;
   } else if (charactere == 'h'){
      return Top;
   } else {
      return {};
   }
}


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
