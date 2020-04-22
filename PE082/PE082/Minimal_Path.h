#pragma once

#include "PE082.h"

int Minimal_Path_Sum(PE082_Matrix pe081_matrix[NxN][NxN]);
void Rightward_Path(PE082_Matrix pe081_matrix[NxN][NxN], int row, int column);
void Downward_Path(PE082_Matrix pe081_matrix[NxN][NxN], int row, int column);
std::vector<int> Cheapest_Path(PE082_Matrix pe081_matrix[NxN][NxN], int row, int column);