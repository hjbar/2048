#pragma once

#include <iostream>
#include <vector>
#include <optional>
#include <cstring>
#include <string>
#include <string.h>
#include <unistd.h>
#include <termios.h>

#include "affichage.hpp"
#include "deplacement.hpp"
#include "plateau.hpp"
#include "score.hpp"

using namespace std;

typedef vector<vector<int>> Plateau;

char getch();

char commande_cheate();

/** Fonction qui simule une partie de 2048 **/
void jeu(void);
