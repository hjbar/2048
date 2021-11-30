#include "game.hpp"


char getch() {
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


char commande_cheate() {
   char a = getch();

   if(a == 'h' or a == 'b' or a == 'g' or a == 'd' or a =='q') {
      return a;
   }

   if(a != '') {
      return 'n';
   }

   char b = getch();
   char c = getch();


   if(a == '' and b == '[') {
      if(c == 'A') {
         return 'h';
      } else if(c == 'B') {
         return 'b';
      } else if(c == 'C') {
         return 'd';
      } else if (c == 'D') {
         return 'g';
      }
   }
   return 'n';
}


void jeu(void) {
  // Initalisation du Plateau de jeu
  int nb_quatre = 0;
  int new_nombre = genere_nombre();
  nb_quatre = calcul_nombre_quatre(nb_quatre, new_nombre);
  Plateau tab = init_plateau(new_nombre);
  new_nombre = genere_nombre();
  nb_quatre = calcul_nombre_quatre(nb_quatre, new_nombre);
  tab = ajoute_nombre_plateau(tab, new_nombre);
  cout << endl;
  affiche_plateau(plateau_to_string_avec_couleur(tab));

  // Debut de la partie
  while(not fin_de_partie(tab)) {

     // On va demander d'entrer une commande et verifier qu'elle est correcte
     char commande;
     string commande_en_string;
     optional<Direction> dir = nullopt;
     while(not dir.has_value()) {
        cout << endl << "Entrer commande (h, b, g, d, q): " << endl;

        /**
        commande_en_string = getch();
        if (commande_en_string == "[A"){
           commande = 'h';
        } else {
           commande = commande_en_string.at(0);
        }
        **/

        commande = commande_cheate();

        dir = char_to_direction(commande);

        if(commande == 'q') {
           cout << endl << "Vous venez de quitter la partie en cours" << endl;
           cout << "Votre score etait de : " << score_plateau(tab, nb_quatre) << endl;
           return;
        }

        if(dir.has_value() and not deplacement_possible(dir.value(), tab)) {
           dir = char_to_direction('n');
           cout << endl << "Mouvement impossible" << endl;
        }
     }

     // La commande est valide donc on un joue un coup
     tab = deplacement(dir.value(), tab);

     // On verifie si le plateau n'est pas plein afin de savoir si on peut ajouter un nouveau nombre
     if(not plateau_est_plein(tab)) {
        new_nombre = genere_nombre();
        nb_quatre = calcul_nombre_quatre(nb_quatre, new_nombre);
        tab = ajoute_nombre_plateau(tab, new_nombre);
     }

     // On affiche le score et le plateau actualise avec le nouveau coup
     cout << endl << "Score : " << score_plateau(tab, nb_quatre) << endl;
     affiche_plateau(plateau_to_string_avec_couleur(tab));
  }
  // La partie est finie, on affiche le score
  cout << endl << "Fin de partie" << endl;
  cout << "Vous avez atteind le score de : " << score_plateau(tab, nb_quatre) << endl;
}
