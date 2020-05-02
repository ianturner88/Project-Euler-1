#pragma once

enum Paths {
	DOWNWARDS = 0, UPWARDS = 1, RIGHT = 2
};

int Minimal_Path_Sum(PE082_Matrix pe081_matrix[NxN][NxN]);

void Rightward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column);
void Upward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column);
void Downward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column);

std::vector<int> Cheapest_Path(PE082_Matrix pe081_matrix[NxN][NxN], int row, int column);