#pragma once

#include "affichage.hpp"
#include "deplacement.hpp"
#include "plateau.hpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <assert.h>
#include <cstdlib>

using namespace std;


void assert_string_equal(string got, string expected);
void test_plateau_to_string();
void test_genere_nombre();
void test_init_plateau();
void test_ajoute_nombre_plateau();
void test_all();
