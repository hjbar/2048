#pragma once

#include <iostream>
#include <vector>

#include "affichage.hpp"
#include "deplacement.hpp"
#include "plateau.hpp"
#include "score.hpp"

using namespace std;

typedef vector<vector<int>> Plateau;


/** Fonction qui verifie si la commande de fin de partie est egale a game ou quit
 * @param commande une chaine de caractere
 * @return true si commande = game ou quit, false sinon
 **/
bool commande_est_valide(string commande);
void jeu();
