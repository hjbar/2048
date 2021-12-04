#include "2048.hpp"

/** Lance le jeu **/
int main(void)
{

	// Permet de reinitialiser les nombres generes aleatoirement
	srand((unsigned)time(NULL));

	// On s'assure que les fonctions utilisees sont correctes
	test_all();

	// On lance le jeu jusqu'ou l'utilisateur ne veulle plus jouer
	char decision;
	bool arret_partie = false;
	while(not arret_partie)
	{
		jeu();
		decision = ' ';
		// On demande si le l'utilisateur veut rejouer ou non
		while(not(decision == 'g' or decision == 'q'))
		{
			cout << endl << "Entrer 'g' pour rejouer, entrer 'q' pour quitter le jeu" << endl;
			cin >> decision;
		}
		if(decision == 'q')
		{
			arret_partie = true;
		}
	}
	nouveau_ecran();
	cout << endl << "Merci d'avoir joué ! A bientot :)" << endl;

	return 0;
}
