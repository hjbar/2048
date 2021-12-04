#pragma once

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Plateau;

/** Une fonction qui ajoute 1 au nombre de quatre actuel si le nombre aleatoire qui va etre ajoute au plateau vaut 4
 * @param nb_quatre un entier correspondant au nombre de quatre actuel
 * @param nb_alea un entier correspondant au nombre aleatoire qui va etre ajouter au plateau
 * @return nb_quatre un entier correspondant un nombre de quatre actualise en consequence
 * Fonction ecrite par Hugo
 * Niveau de confince : 2/2 car testee
 **/
int calcul_nombre_quatre(int nb_quatre, int nb_alea);

/** Fonction qui calcule les points donnés par un nombre
 * @param nombre un entier correspondant a la valeur d'une case d'un plateau de jeu
 * @return le nombre de points obtenus pour une case d'un plateau de jeu
 * Fonction ecrite par Hugo
 * Niveau de confiance : 2/2 car testee
 **/
int score_nombre(int nombre);

/** Fonction qui renvoie les points du plateau en fonction du nombre de 4 generes aleatoirement
 * @param tab un plateau de jeu
 * @param nombre_de_quatre un entier correspond un nombre de 4 apparue de maniere aleatoire
 * @return le nombre de points du plateau de jeu
 * Fonction ecrite par Hugo
 * Niveau de confiance : 2/2 car tesee
 **/
int score_plateau(Plateau tab, int nombre_de_quatre);

/** Fonction qui teste si le plateau de jeu est plein
 * @param tab un plateau de jeu
 * @return un bool valant, true si le plateau est plein, false sinon
 * Fonction ecrite par Hugo
 * Niveau de confiance : 2/2 car testee
 **/
bool plateau_est_plein(Plateau tab);

/** Fonction qui teste si la partie est terminee, c'est-a-dire si aucun coup n'est possible
 * @param tab un plateau de jeu
 * @return un bool valant, true si la partie est terminee, false sinon
 * Fonction ecrite par Hugo
 * Niveau de confiance : 2/2 car testee
 **/
bool fin_de_partie(Plateau tab);
