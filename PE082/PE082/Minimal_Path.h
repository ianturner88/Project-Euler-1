#pragma once

enum Paths {
	DOWNWARD = 0, UPWARD = 1, RIGHTWARD = 2
};

std::vector<int> Minimal_Path(PE082_Matrix pe082_matrix[NxN][NxN]);

void Rightward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column, int row);
void Upward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column, int row);
void Downward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column, int row);
void Identify_Cheapest_Path(std::vector<std::vector<int>> paths, PE082_Matrix pe082_matrix[NxN][NxN],
	int row, int column);