#pragma once

#include <vector>

enum PE081 {
	NxN = 80
};

class PE081_Matrix
{
public:
	int indices_value;
	int current_minimual_sum;
	std::vector<int> cheapest_sum;

	void set_Indice(int input_number) { indices_value = input_number; }
	int get_Indice() { return indices_value; }
};
