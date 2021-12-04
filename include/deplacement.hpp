#pragma once

#include <iostream>
#include <optional>
#include <termios.h>
#include <unistd.h>
#include <vector>

using namespace std;

typedef vector<vector<int>> Plateau;
enum Direction
{
	Left,
	Right,
	Top,
	Bottom
};

/** Fonction qui permet de recuperer un charactere au clavier sans avoir besoin d'appuyer sur "entree"
 * @return buf un char qu'on recupere avec le clavier sans appuyer sur "entree"
 * Fonction ecrite par Faucon Momot sur le forum de QA Stack (https://qastack.fr/programming/421860/capture-characters-from-standard-input-without-waiting-for-enter-to-be-pressed)
 * Niveau de confiance : 1/2 car non testee
 **/
/**
char getch(void);
**/

/** Fonction qui permet de recuprer un charactere et le convertir en sa commande associee
 * @return un char qui correspond a une direction ou une commande si l'entre est valide, sinon il renvoie un char permettant de relancer un tour de boucle au moment d'appeler cette fonction
 * Fonction ecrite par Hugo et Francisco
 * Niveau de confiance : 1/2 car non testee
 **/
/**
char recupere_commande(void);
**/

/** Fonction qui transforme un caractere en Direction s'il correspond a une direction valide
 * @param charactere un caractere
 * @return une Direction entre Right / Left / Bottom / Top si charactere, l'équivalent de None sinon
 * Fonction ecrite par Hugo
 * Niveau de confiance : 2/2 car testee
 **/
optional<Direction> char_to_direction(const char charactere);

/** Fonction qui decale les nombres du plateau dans une direction precise sans les additionner
 * @param d une Direction valant Right, Left, Top ou Bottom
 * @param tab un plateau de jeu
 * @return le plateau de jeu modifie en consequence
 * Fonction ecrite par Hugo
 * Niveau de confiance : 2/2 car testee
 **/
Plateau decalage_nombre(Direction d, Plateau tab);

/** Une fonction qui simule un deplacement de jeu dans une direction precise
 * @param d une Direction valant Right, Left, Top ou Bottom
 * @param tab un plateau de jeu
 * @return le pleateau de jeu modifie en consequence
 * Fonction ecrite par Hugo
 * Niveau de confiance : 2/2 car testee
 **/
Plateau deplacement(Direction d, Plateau tab);

/** Fonction qui teste si le deplacement dans une direction donnee est autorisee par les regles du jeu
 * @param d une Direction valant Left, Right, Top, Bottom
 * @param tab un Plateau de jeu
 * @return true si le deplacement dans une direction est possible, false sinon
 * Fonction ecrite par Hugo
 * Niveau de confiance : 2/2 car testee
 **/
bool deplacement_possible(Direction d, Plateau tab);
