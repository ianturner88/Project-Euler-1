#pragma once

#include <vector>

enum PE081 {
	NxN = 80
};

class PE081_Matrix
{
public:
	int element_value;
	int cheapest_sum = 0;
	int round = 0;
	std::vector<int> cheapest_path;

	void set_Indice(int input_number) { element_value = input_number; }
	int get_Indice() { return element_value; }
};

void Print_Shortest_Path(PE081_Matrix pe081_matrix[NxN][NxN]);