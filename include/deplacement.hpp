#pragma once

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Plateau;
enum Direction { Left, Right, Top, Bottom };

bool valide_direction(string c);
Direction string_to_direction(string charactere);

/** Fonction qui teste si le deplacement dans une direction donnee est autorisee par les regles du jeu
 * @param d une Direction entre Left, Right, Top, Bottom
 * @param tab une Plateau de jeu
 * @return true si le deplacement dans une direction en possible, false sinon
 **/
bool deplacement_possible(Direction d, Plateau tab);

Plateau decalage_nombre(Direction d, Plateau tab);
Plateau deplacement(Direction d, Plateau tab);
