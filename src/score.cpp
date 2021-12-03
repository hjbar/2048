#include "score.hpp"

int calcul_nombre_quatre(int nb_quatre, int nb_alea)
{
	if(nb_alea == 4)
	{
		return nb_quatre + 1;
	}
	else
	{
		return nb_quatre;
	}
}

int score_nombre(int nombre)
{
	int score = 0;
	// Si nombre vaut 32, pour creer ce nombre on a obtenu les points de 32*1 + 16*2 + 8*4 + 4*8, d'ou la creation de la variable coefficient
	int coefficient = 1;
	// Le nombre 2 etant obligatoirement generer par le jeu, on ne peut pas en obtenir de points
	while(nombre > 2)
	{
		score = score + (nombre * coefficient);
		nombre = (nombre / 2);
		coefficient = (coefficient * 2);
	}
	return score;
}

int score_plateau(Plateau tab, int nombre_de_quatre)
{
	int score = 0;
	for(vector<int> ligne : tab)
	{
		for(int nombre : ligne)
		{
			score = score + score_nombre(nombre);
		}
	}
	// Les nombres 4 generes par le jeu ne rapporte pas de points, il faut donc les retirer de score
	return score - (4 * nombre_de_quatre);
}

bool plateau_est_plein(Plateau tab)
{
	for(vector<int> ligne : tab)
	{
		for(int nombre : ligne)
		{
			if(nombre == 0)
			{
				return false;
			}
		}
	}
	return true;
}

bool fin_de_partie(Plateau tab)
{

	bool tab_est_plein = plateau_est_plein(tab);
	if(not tab_est_plein)
	{
		return false;
	}

	for(int i = 0; i <= 3; i++)
	{
		for(int j = 0; j <= 2; j++)
		{
			if(tab[i][j] == tab[i][j + 1])
			{
				return false;
			}
		}
	}

	for(int n = 0; n <= 2; n++)
	{
		for(int k = 0; k <= 3; k++)
		{
			if(tab[n][k] == tab[n + 1][k])
			{
				return false;
			}
		}
	}

	return true;
}
