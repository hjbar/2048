#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <assert.h>

using namespace std;

typedef vector<vector<int>> Plateau;

int taille_nombre(int nombre);
string plateau_to_string(Plateau t);
void affiche_plateau(string plateau);
void test_plateau_to_string();
