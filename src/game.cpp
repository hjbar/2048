#include "game.hpp"


bool commande_est_valide(string commande) {
   return ((commande == "quit") or (commande == "game"));
}


void jeu() {
  int nb_quatre = 0;
  int new_nombre = genere_nombre();
  nb_quatre = calcul_nombre_quatre(nb_quatre, new_nombre);

  Plateau tab = init_plateau(new_nombre);
  new_nombre = genere_nombre();
  nb_quatre = calcul_nombre_quatre(nb_quatre, new_nombre);
  tab = ajoute_nombre_plateau(tab, new_nombre);
  cout << endl;
  affiche_plateau(plateau_to_string(tab));

  while(not fin_de_partie(tab)) {

     string commande = "_";
     while(not valide_direction(commande)) {
        cout << endl << "Entrer commande : " << endl;
        commande = "";
        cin >> commande;

        if(commande == "quit") {
           cout << endl << "Vous venez de quitter la partie en cours" << endl;
           cout << "Votre score etait de : " << score_plateau(tab, nb_quatre) << endl;
           return;
        }

        if(not deplacement_possible(string_to_direction(commande), tab)) {
           cout << endl << "Mouvement impossible" << endl;
           commande = "";
        }
     }

     Direction d = string_to_direction(commande);
     tab = deplacement(d, tab);

     if(not plateau_est_plein(tab)) {
        new_nombre = genere_nombre();
        nb_quatre = calcul_nombre_quatre(nb_quatre, new_nombre);
        tab = ajoute_nombre_plateau(tab, new_nombre);
     }

     cout << endl << "Score : " << score_plateau(tab, nb_quatre) << endl;
     affiche_plateau(plateau_to_string(tab));
  }

  cout << endl << "Fin de partie" << endl;
  cout << "Vous avez atteind le score de : " << score_plateau(tab, nb_quatre) << endl;
}
