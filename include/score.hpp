#pragma once

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Plateau;


/** Une fonction qui ajoute 1 au nombre de quatre actuel si le nombre aleatoire qui va etre ajoute au plateau vaut 4
 * @param nb_quatre un entier correspondant au nombre de quatre actuel
 * @param nb_alea un entier correspondant au nombre aleatoire qui va etre ajouter au plateau
 * @return nb_quatre un entier correspondant un nombre de quatre actualise
 **/
int calcul_nombre_quatre(int nb_quatre, int nb_alea);

int score_nombre(int nombre);
int score_plateau(Plateau tab, int nombre_de_quatre);
bool plateau_est_plein(Plateau tab);
bool fin_de_partie(Plateau tab);
