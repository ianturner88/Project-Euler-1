#pragma once

#include <vector>

enum PE082 {
	NxN = 5
};

class PE082_Matrix
{
public:
	// the value of the matrix at the given point
	int element_value;
	// the value of the shortest path to the given point
	int cheapest_sum = 0;
	/* indicates if the shortest path to that point has yet to investigated ->
	since the cheapest sum is initialized to 0, this variable is needed to indicate
	that 0 not the cheapest path*/
	bool is_untouched = true;
	// contains the cheapest path from the right-side to the left-side of the matrix
	std::vector<int> cheapest_path;

	// sets the value of the matrix at a given point
	void set_Indice(int input_number) { element_value = input_number; }
	// sets initializes the cheapest path with every possible starting point
	void set_Cheapest_Sum(int input_number) { cheapest_sum = input_number; }
	// returns the value of the matrix at a given point
	int get_Indice() { return element_value; }
};

//outputs the shortest path across the matrix
void Print_Shortest_Path(PE082_Matrix pe081_matrix[NxN][NxN]);