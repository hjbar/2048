#pragma once

#include <iostream>
#include <vector>
#include <assert.h>

using namespace std;

typedef vector<vector<int>> Plateau;
enum Direction { Left, Right, Top, Bottom };

Plateau deplacement(Direction d, Plateau tab);
