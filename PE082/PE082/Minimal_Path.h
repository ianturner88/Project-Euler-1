#pragma once

#include "PE081.h"

int Minimal_Path_Sum(PE081_Matrix pe081_matrix[NxN][NxN]);
void Rightward_Path(PE081_Matrix pe081_matrix[NxN][NxN], int row, int column);
void Downward_Path(PE081_Matrix pe081_matrix[NxN][NxN], int row, int column);