#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <fmt/core.h>

using namespace std;

typedef vector<vector<int>> Plateau;

string plateau_to_string(Plateau t);
void affiche_plateau(string plateau);
