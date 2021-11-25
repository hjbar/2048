#pragma once

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Plateau;


/** Fonction renvoyant un flottant aleatoire qui sert à faire fonctionner la fonction random_int
 * @return ((float) rnd / (float) RAND_MAX) un nombre flottant aleatoire
 **/
float random_float(void);


/** Fonction renvoyant un nombre entier aleatoire compris entre deux bornes incluses
 * @param min un entier représentant le minimum du nombre aléatoire généré
 * @param max un entier représentant le maximum du nombre aléatoire généré
 * @return un entier aléatoire n tel que min <= n <= max
 **/
int random_int(const int min, const int max);


/** Fonction qui genere un nombre aléatoirement entre 2 avec 90% de chance et 4 avec 10% de chance
 * @return 2 ou 4 en respectant les probabilites
 **/
int genere_nombre(void);


/** Fonction qui initialise un nouveau plateau de jeu comportant deja un nombre
 * @param nombre un nombre entier valant soit 2, soit 4
 * @return tab le pleateau de jeu initialise
 **/
Plateau init_plateau(const int nombre);


/** Fonction qui ajoute un nomdre dans la plateau de jeu
 * @param tab un Plateau de jeu non plein
 * @param nombre un nombre entier valant soit 2, soit 4
 * @return tab le plateau de jeu avec un nombre ajoute
 **/
Plateau ajoute_nombre_plateau(Plateau tab, int nombre);
