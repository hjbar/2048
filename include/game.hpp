#pragma once

#include <iostream>
#include <vector>
#include <optional>
#include <cstring>

#include "affichage.hpp"
#include "deplacement.hpp"
#include "plateau.hpp"
#include "score.hpp"

using namespace std;

typedef vector<vector<int>> Plateau;


/** Fonction qui simule une partie de 2048 **/
void jeu(void);
