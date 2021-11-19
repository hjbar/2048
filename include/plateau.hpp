#pragma once

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Plateau;

float random_float(void);
int random_int(const int min, const int max);
int genere_nombre();
Plateau init_plateau(const int nombre);
Plateau ajoute_nombre_plateau(Plateau tab, int nombre);
