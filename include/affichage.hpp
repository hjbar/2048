#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <assert.h>
#include <fmt/core.h>

using namespace std;

typedef vector<vector<int>> Plateau;

string plateau_to_string(Plateau t);
void affiche_plateau(string plateau);