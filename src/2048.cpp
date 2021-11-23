#include "2048.hpp"

/**
void jeu() {
   int nb_quatre = 0;
   int new_nombre = genere_nombre();
   if(new_nombre == 4) {nb_quatre += 1;}
   Plateau tab = init_plateau(new_nombre);
   affiche_plateau(plateau_to_string(tab));
   new_nombre = genere_nombre();
   if(new_nombre == 4) {nb_quatre += 1;}
   tab = ajoute_nombre_plateau(tab, new_nombre);
   while(not fin_de_partie(tab)) {
      cout << "Entrer commande : " << endl;
      string commande;
      cin >> commande;
      bool valide_commande = valide_direction(commande);
      while(not valide_commande) {
         cout << "Entrer commande : " << endl;
         commande = "";
         cin >> commande;
         valide_commande = valide_direction(commande);
      }
      Direction d = string_to_direction(commande);
      tab = deplacement(d, tab);
      if(not plateau_est_plein(tab)) {
         new_nombre = genere_nombre();
         if(new_nombre == 4) {nb_quatre += 1;}
         tab = ajoute_nombre_plateau(tab, new_nombre);
      }
   }
   cout << "Fin de partie" << endl;
   cout << "Votre score est de : " << score_plateau(tab, nb_quatre);
}
**/

int main(void) {

   srand((unsigned) time(NULL));

   test_all();

   bool arret_partie = false;
   while(not arret_partie) {
      jeu();
      string decision;
      cout << "Entrer 'game' pour rejouer, entrer 'quit' pour quitter le jeu" << endl;
      cin >> decision;
      if(decision == "quit") {
         arret_partie = true;
      }
   }
   cout << "Merci d'avoir joué ! A bientot" << endl;

   return 0;
}
