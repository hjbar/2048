#include <iostream>
#include <vector>
#include <assert.h>
#include <cstdlib>

using namespace std;

typedef vector<vector<int>> Plateau;

int aleaint(int a, int b);
int genere_nombre();
Plateau init_plateau(int nombre);
Plateau ajoute_nombre_plateau(Plateau tab, int nombre);
