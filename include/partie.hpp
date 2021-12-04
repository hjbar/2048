#pragma once

#include <iostream>
#include <optional>
#include <vector>

#include "affichage.hpp"
#include "deplacement.hpp"
#include "plateau.hpp"
#include "score.hpp"

using namespace std;

typedef vector<vector<int>> Plateau;

/** Fonction qui simule une partie de 2048
 * Fonction ecrite par Hugo
 * Niveau de confiance 1/2 car non testee
 **/
void jeu(void);
