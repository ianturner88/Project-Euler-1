#pragma once

enum Paths {
	DOWNWARD = 0, UPWARD = 1, RIGHT = 2
};

int Minimal_Path_Sum(PE082_Matrix pe081_matrix[NxN][NxN]);

void Rightward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column);
void Upward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column);
void Downward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column);

int Identify_Cheapest_Path(PE082_Matrix pe082_matrix[NxN][NxN], int row, int column);
void Update_Shortest_Path(PE082_Matrix pe082_matrix[NxN][NxN], int shortest_path, int row, int column);
void Reset_Paths(PE082_Matrix pe082_matrix[NxN][NxN], int row, int column);