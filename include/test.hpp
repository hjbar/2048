#pragma once

#include "affichage.hpp"
#include "deplacement.hpp"
#include "plateau.hpp"
#include "score.hpp"

#include <assert.h>


using namespace std;


void assert_string_equal(string got, string expected);
void test_plateau_to_string();
void test_genere_nombre();
void test_init_plateau();
void test_ajoute_nombre_plateau();
void test_score_nombre();
void test_score_plateau();
void test_plateau_est_plein();
void test_fin_de_partie();
void test_valide_direction();
void test_string_to_direction();
void test_decalage_nombre();
void test_deplacement();
void test_all();
