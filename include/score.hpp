#pragma once

#include <iostream>
#include <vector>

#include "affichage.hpp"
#include "deplacement.hpp"
#include "plateau.hpp"

using namespace std;

typedef vector<vector<int>> Plateau;

int score_nombre(int nombre);
int score_plateau(Plateau tab, int nombre_de_quatre);
bool plateau_est_plein(Plateau tab);
bool fin_de_partie(Plateau tab);
void jeu();
