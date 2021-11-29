#pragma once

#include "affichage.hpp"
#include "deplacement.hpp"
#include "plateau.hpp"
#include "score.hpp"
#include "game.hpp"

#include <assert.h>
#include <algorithm>

using namespace std;


/** Lance une serie de test sur la fonction couleur_nombre **/
void test_couleur_nombre(void);


/** Fonction qui verifie si deux strings sont egales et les affiches si elles ne sont pas egales
 * @param got la chaine de caractere renvoyee par plateau_to_string
 * @param expected la chaine de caractere que l'on attend
 **/
void assert_string_equal(string got, string expected);


/** Lance une serie de test sur la fonction plateau_to_string **/
void test_plateau_to_string(void);


/** Lance une serie de test sur la fonction genere_nombre **/
void test_genere_nombre(void);


/** Lance une serie de test sur la fonction init_plateau **/
void test_init_plateau(void);


/** Lance une serie de test sur la fonction ajoute_nombre_plateau **/
void test_ajoute_nombre_plateau(void);


/** Lance une serie de test sur la fonction score_nombre **/
void test_score_nombre(void);


/** Lance une serie de test sur la fonction score_plateau **/
void test_score_plateau(void);


/** Lance une serie de test sur la fonction plateau_est_plein **/
void test_plateau_est_plein(void);


/** Lance une serie de test sur la fonction fin_de_partie **/
void test_fin_de_partie(void);


/** Lance une serie de test sur la fonction char_to_direction **/
void test_char_to_direction(void);


/** Lance une serie de test sur la fonction decalage_nombre **/
void test_decalage_nombre(void);


/** Lance une serie de test sur la fonction deplacement **/
void test_deplacement(void);


/** Lance une serie de test sur la fonction calcul_nombre_de_quatre **/
void test_calcul_nombre_quatre(void);


/** Lance une serie de test sur la fonction deplacement_possible **/
void test_deplacement_possible(void);


/** Fonction qui lance le test de toutes les fonctions test **/
void test_all(void);
