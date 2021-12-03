#pragma once

#include <fmt/core.h>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <vector>

using namespace std;

typedef vector<vector<int>> Plateau;

#define WHITE "\033[0;97m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define PURPLE "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET_COLOR "\033[0m"

/** Fonction qui rafraichit l'ecran **/
void reset_screen(void);

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

/** Fonction qui tranforme le plateau de jeu en chaine de cracteres avec de la couleur
 * @param t un Plateau qui correspond au plateau de jeu
 * @return os.str() qui correspond au plateau de jeu sous forme de chaine de caracteres avec de la couleur
 **/
string plateau_to_string_avec_couleur(Plateau t);

/** Fonction qui affiche le plateau de jeu
 * @param plateau une chaine de caracteres correspondant au plateau de jeu
 **/
void affiche_plateau(string plateau);
