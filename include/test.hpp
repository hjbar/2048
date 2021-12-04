#pragma once

#include "affichage.hpp"
#include "deplacement.hpp"
#include "partie.hpp"
#include "plateau.hpp"
#include "score.hpp"

#include <algorithm>
#include <assert.h>

using namespace std;

/** Lance une serie de test sur la fonction couleur_nombre
 * Fonction ecrite par Hugo
 * Niveau de confiance : 1/2 car non testee
 **/
void test_couleur_nombre(void);

/** Fonction qui verifie si deux strings sont egales et les affiches si elles ne sont pas egales
 * @param got la chaine de caractere renvoyee par plateau_to_string
 * @param expected la chaine de caractere que l'on attend
 * Fonction ecrite par Hugo
 * Niveau de confiance : 1/2 car non testee
 **/
void test_string_equal(string got, string expected);

/** Lance une serie de test sur la fonction plateau_to_string
 * Fonction ecrite par Hugo
 * Niveau de confiance : 1/2 car non testee
 **/
void test_plateau_to_string(void);

/** Lance une serie de test sur la fonction genere_nombre
 * Fonction ecrite par Hugo
 * Niveau de confiance : 1/2 car non testee
 **/
void test_genere_nombre(void);

/** Lance une serie de test sur la fonction init_plateau
 * Fonction ecrite par Hugo
 * Niveau de confiance : 1/2 car non testee
 **/
void test_init_plateau(void);

/** Lance une serie de test sur la fonction ajoute_nombre_plateau
 * Fonction ecrite par Hugo
 * Niveau de confiance : 1/2 car non testee
 **/
void test_ajoute_nombre_plateau(void);

/** Lance une serie de test sur la fonction score_nombre
 * Fonction ecrite par Hugo
 * Niveau de confiance : 1/2 car non testee
 **/
void test_score_nombre(void);

/** Lance une serie de test sur la fonction score_plateau
 * Fonction ecrite par Hugo
 * Niveau de confiance : 1/2 car non testee
 **/
void test_score_plateau(void);

/** Lance une serie de test sur la fonction plateau_est_plein
 * Fonction ecrite par Hugo
 * Niveau de confiance : 1/2 car non testee
 **/
void test_plateau_est_plein(void);

/** Lance une serie de test sur la fonction fin_de_partie
 * Fonction ecrite par Hugo
 * Niveau de confiance : 1/2 car non testee
 **/
void test_fin_de_partie(void);

/** Lance une serie de test sur la fonction char_to_direction
 * Fonction ecrite par Hugo
 * Niveau de confiance : 1/2 car non testee
 **/
void test_char_to_direction(void);

/** Lance une serie de test sur la fonction decalage_nombre
 * Fonction ecrite par Hugo
 * Niveau de confiance : 1/2 car non testee
 **/
void test_decalage_nombre(void);

/** Lance une serie de test sur la fonction deplacement
 * Fonction ecrite par Hugo
 * Niveau de confiance : 1/2 car non testee
 **/
void test_deplacement(void);

/** Lance une serie de test sur la fonction calcul_nombre_de_quatre
 * Fonction ecrite par Hugo
 * Niveau de confiance : 1/2 car non testee
 **/
void test_calcul_nombre_quatre(void);

/** Lance une serie de test sur la fonction deplacement_possible
 * Fonction ecrite par Hugo
 * Niveau de confiance : 1/2 car non testee
 **/
void test_deplacement_possible(void);

/** Fonction qui lance le test de toutes les fonctions test
 * Fonction ecrite par Hugo
 * Niveau de confiance : 1/2 car non testee
 **/
void test_all(void);
