#pragma once

#include <iostream>
#include <optional>
#include <vector>

using namespace std;

typedef vector<vector<int>> Plateau;
enum Direction { Left, Right, Top, Bottom };


/** Fonction qui transforme un caractere en Direction s'il correspond a une direction valide
 * @param charactere un caractere
 * @return une Direction entre Right / Left / Bottom / Top si charactere, l'équivalent de None sinon
 **/
optional<Direction> char_to_direction(const char charactere);


/** Fonction qui decale les nombres du plateau dans une direction precise sans les additionner
 * @param d une Direction valant Right, Left, Top ou Bottom
 * @param tab un plateau de jeu
 * @return le plateau de jeu modifie en consequence
 **/
Plateau decalage_nombre(Direction d, Plateau tab);


/** Une fonction qui simule un deplacement de jeu dans une direction precise
 * @param d une Direction valant Right, Left, Top ou Bottom
 * @param tab un plateau de jeu
 * @return le pleateau de jeu modifie en consequence
 **/
Plateau deplacement(Direction d, Plateau tab);


/** Fonction qui teste si le deplacement dans une direction donnee est autorisee par les regles du jeu
 * @param d une Direction valant Left, Right, Top, Bottom
 * @param tab un Plateau de jeu
 * @return true si le deplacement dans une direction est possible, false sinon
 **/
bool deplacement_possible(Direction d, Plateau tab);
