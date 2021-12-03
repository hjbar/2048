#include "game.hpp"

void jeu(void)
{
	// Refresh de l'ecran
	reset_screen();

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
	while(not fin_de_partie(tab))
	{

		// On va demander d'entrer une commande et verifier qu'elle est correcte
		char commande;
		optional<Direction> dir = nullopt;
		while(not dir.has_value())
		{
			cout << endl
				 << "Entrer commande (h, b, g, d, q ou utiliser les flèches du clavier): " << endl;

			commande = recupere_commande();

			dir = char_to_direction(commande);

			if(commande == 'q')
			{
				cout << endl << "Vous venez de quitter la partie en cours" << endl;
				cout << "Votre score etait de : " << score_plateau(tab, nb_quatre) << endl;
				return;
			}

			if(dir.has_value() and not deplacement_possible(dir.value(), tab))
			{
				// char_to_direction renvoie None car 'n' n'est pas une direction valide
				dir = char_to_direction('n');
				cout << endl << "Mouvement impossible" << endl;
			}
		}

		// La commande est valide donc on un joue un coup
		tab = deplacement(dir.value(), tab);

		// On verifie si le plateau n'est pas plein afin de savoir si on peut ajouter un nouveau nombre
		if(not plateau_est_plein(tab))
		{
			new_nombre = genere_nombre();
			nb_quatre = calcul_nombre_quatre(nb_quatre, new_nombre);
			tab = ajoute_nombre_plateau(tab, new_nombre);
		}

		// On affiche le score et le plateau actualise avec le nouveau coup
		reset_screen();
		cout << endl << "Score : " << score_plateau(tab, nb_quatre) << endl;
		affiche_plateau(plateau_to_string_avec_couleur(tab));
	}
	// La partie est finie, on affiche le score
	cout << endl << "Fin de partie" << endl;
	cout << "Vous avez atteind le score de : " << score_plateau(tab, nb_quatre) << endl;
}
