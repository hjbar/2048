#include "plateau.hpp"

float alea_float(void)
{
	const int rnd = rand();
	return ((float)rnd / (float)RAND_MAX);
}

int alea_int(const int min, const int max)
{
	return (int)((float)min + ((float)(max - min + 1) * alea_float()));
}

int genere_nombre(void)
{
	return alea_int(1, 10) == 10 ? 4 : 2;
}

Plateau init_plateau(const int nombre)
{
	Plateau tab = Plateau(4);
	for(int i = 0; i < 4; i++)
	{
		tab[i] = vector<int>(4);
		for(int j = 0; j < 4; j++)
		{
			tab[i][j] = 0;
		}
	}
	int x = alea_int(0, 3);
	int y = alea_int(0, 3);
	tab[x][y] = nombre;
	return tab;
}

Plateau ajoute_nombre_plateau(Plateau tab, int nombre)
{
	bool case_libre = false;
	while(not case_libre)
	{
		int x = alea_int(0, 3);
		int y = alea_int(0, 3);
		if(tab[x][y] == 0)
		{
			tab[x][y] = nombre;
			case_libre = true;
		}
	}
	return tab;
}
