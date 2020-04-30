#pragma once

int Minimal_Path_Sum(PE082_Matrix pe081_matrix[NxN][NxN]);
void Downward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int row, int column);
void Rightward_Path(PE082_Matrix pe081_matrix[NxN][NxN], int row, int column);
std::vector<int> Cheapest_Path(PE082_Matrix pe081_matrix[NxN][NxN], int row, int column);