#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <fmt/core.h>
#include <string>

using namespace std;

typedef vector<vector<int>> Plateau;

#define white "\033[0;97m"
#define red "\033[0;31m"
#define green "\033[0;32m"
#define yellow "\033[0;33m"
#define blue "\033[0;34m"
#define purple "\033[0;35m"
#define cyan "\033[0;36m"
#define reset "\033[0m"


/** Fonction qui renvoie la chaine de caracteres permettant d'afficher les nombres en couleur dans la console
 * @param nombre un nombre entier que l'on veut afficher dans une certaine couleur
 * @return une string correspond a la bonne couleur associee au nombre en parametre
 **/
string couleur_nombre(int nombre);


/** Fonction qui tranforme le plateau de jeu en chaine de cracteres
 * @param t un Plateau qui correspond au plateau de jeu
 * @return os.str() qui correspond au plateau de jeu sous forme de chaine de caracteres
 **/
string plateau_to_string(Plateau t);


/** Fonction qui affiche le plateau de jeu
 * @param plateau une chaine de caracteres correspondant au plateau de jeu
 **/
void affiche_plateau(string plateau);
