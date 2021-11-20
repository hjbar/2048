#pragma once

#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Plateau;
enum Direction { Left, Right, Top, Bottom };

bool valide_direction(string c);
Direction string_to_direction(string charactere);
Plateau deplacement(Direction d, Plateau tab);
