#pragma once

#include<vector>

#include "PE081_enum.h"

std::vector<int> Top_Triangle(int pe081_array[][5], int triangle_layer_counter);
std::vector<int> Bottom_Triangle(int pe081_array[][5], int column_counter, int row_stopper);