#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <fmt/core.h>

using namespace std;

typedef vector<vector<int>> Plateau;


/** Fonction qui tranforme le plateau de jeu en chaine de cracteres
 * @param t un Plateau qui correspond au plateau de jeu
 * @return os.str() qui correspond au plateau de jeu sous forme de chaine de caracteres
 **/
string plateau_to_string(Plateau t);


/** Fonction qui affiche le plateau de jeu
 * @param plateau une chaine de caracteres correspondant au plateau de jeu
 **/
void affiche_plateau(string plateau);
