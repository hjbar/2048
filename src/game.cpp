#include "game.hpp"

void jeu() {
  int nb_quatre = 0;
  int new_nombre = genere_nombre();
  if(new_nombre == 4) {nb_quatre += 1;}
  Plateau tab = init_plateau(new_nombre);
  new_nombre = genere_nombre();
  if(new_nombre == 4) {nb_quatre += 1;}
  tab = ajoute_nombre_plateau(tab, new_nombre);
  affiche_plateau(plateau_to_string(tab));
  while(not fin_de_partie(tab)) {
     cout << "Entrer commande : " << endl;
     string commande;
     cin >> commande;
     bool valide_commande = valide_direction(commande);
     while(not valide_commande) {
        cout << "Entrer commande : " << endl;
        commande = "";
        cin >> commande;
        cout << commande << endl;
        valide_commande = valide_direction(commande);
     }
     Direction d = string_to_direction(commande);
     tab = deplacement(d, tab);
     affiche_plateau(plateau_to_string(tab));
     if(not plateau_est_plein(tab)) {
        new_nombre = genere_nombre();
        if(new_nombre == 4) {nb_quatre += 1;}
        tab = ajoute_nombre_plateau(tab, new_nombre);
     }
    if (cin == "quit"){
        cout << "fin de partie" << endl
          quit()
    }
  }
  affiche_plateau(plateau_to_string(tab));
  cout << "Fin de partie" << endl;
  cout << "Votre score est de : " << score_plateau(tab, nb_quatre) << endl;
}
