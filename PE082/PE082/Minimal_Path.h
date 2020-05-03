#pragma once

enum Paths {
	DOWNWARD = 0, UPWARD = 1, RIGHTWARD = 2
};

std::vector<int> Minimal_Path(PE082_Matrix pe082_matrix[NxN][NxN]);

std::vector<int> Rightward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column, int row);
std::vector<int> Upward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column, int row);
std::vector<int> Downward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column, int row);
void Set_Cheapest_Path(std::vector<std::vector<int>> paths, PE082_Matrix pe082_matrix[NxN][NxN],
	int row, int column);

bool Sort_Vector(const std::vector<int>& v1, const std::vector<int>& v2);