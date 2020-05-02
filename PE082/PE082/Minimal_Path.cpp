#include <iostream>
#include <vector>
#include <algorithm>

#include "PE082.h"
#include "Minimal_Path.h"

int Minimal_Path_Sum(PE082_Matrix pe082_matrix[NxN][NxN])
{
	/* Determines the minimal path starting from the top left corner of the matrix
	to bottom right corner of the matrix */

	Rightward_Path(pe082_matrix, 0);

	for (int row = 0; row < NxN; row++)
	{
		Update_Shortest_Path(pe082_matrix, 2, row, 1);
	}

	for (int column = 1; column < NxN; column++)
	{
		// algorithm always starts in the top left corner
		Downward_Path(pe082_matrix, column);
		Upward_Path(pe082_matrix, column);
		Rightward_Path(pe082_matrix, column);
	}

	/* the cheapest path from the top left corner
	of the matrix to bottom right corner of the matrix */
	return pe082_matrix[0][0].cheapest_sum;
}

void Rightward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column)
{
	for (int row = 0; row < NxN; row++)
	{
		/* start the minimal path search by finding the right-ward path of
		every point in column 0 */

		// store the value which one traversed to arrive at the current point
		pe082_matrix[row][(column + 1)].rightward_path.push_back(pe082_matrix[row][column].element_value);
		// store the current element 
		pe082_matrix[row][(column + 1)].rightward_path.push_back(pe082_matrix[row][(column + 1)].element_value);

		// sum the cost of the rightward path 
		pe082_matrix[row][(column + 1)].rightward_sum = pe082_matrix[row][column].element_value
			+ pe082_matrix[row][(column + 1)].element_value;

		//test
		std::vector<int> test = pe082_matrix[row][(column + 1)].rightward_path;
		int test0 = pe082_matrix[row][(column + 1)].rightward_sum;
		test0 = 9;
	}
}

void Upward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column)
{
	for (int row = (NxN - 1); row > 0; row--)
	{
		// upward path
		pe082_matrix[row][column].upward_path.push_back(pe082_matrix[(row - 1)][column].element_value);
		pe082_matrix[row][column].upward_sum = pe082_matrix[(row - 1)][column].element_value
			+ pe082_matrix[row][column].cheapest_sum;

		//test
		std::vector<int> test = pe082_matrix[row][column].upward_path;
		int test0 = pe082_matrix[row][column].upward_sum;
		test0 = 9;
	}
}

void Downward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column)
{
	for (int row = 0; row < (NxN - 1); row++)
	{
		// downward path
		pe082_matrix[row][column].downward_path.push_back(pe082_matrix[(row + 1)][column].element_value);
		pe082_matrix[row][column].downward_sum = pe082_matrix[row][column].cheapest_sum
			+ pe082_matrix[(row + 1)][column].element_value;

		//test
		std::vector<int> test = pe082_matrix[row][column].downward_path;
		int test0 = pe082_matrix[row][column].downward_sum;
		test0 = 4;
	}
}

int Identify_Cheapest_Path(PE082_Matrix pe082_matrix[NxN][NxN], int row, int column)
{
	/*identifies to shortest path to a given point */
	std::vector<std::vector<int>> cheapest_path;
	std::vector<int> path;

	// the downward path option
	path.push_back(pe082_matrix[row][column].downward_sum);
	path.push_back(DOWNWARD);
	cheapest_path.push_back(path);
	path.clear();

	// the upward path option
	path.push_back(pe082_matrix[row][column].upward_sum);
	path.push_back(UPWARD);
	cheapest_path.push_back(path);
	path.clear();

	// the rightward path option
	path.push_back(pe082_matrix[row][column].rightward_sum);
	path.push_back(RIGHT);
	cheapest_path.push_back(path);
	path.clear();

	// identify the shortest to the given point
	sort(cheapest_path[0].begin(), cheapest_path[0].end());
	// notes the incoming direction that gives the shortest path to the given point
	cheapest_path[0][1];

	// the cheapest path towards the rightside of the matrix
	return cheapest_path[0][1];
}

void Update_Shortest_Path(PE082_Matrix pe082_matrix[NxN][NxN], int shortest_path, int row, int column)
{
	/* Updates the index's shortest path attribute */

	switch (shortest_path)
	{
	case DOWNWARD:
		// update the cheapest path/sum to be the values in the downward direction
		pe082_matrix[row][column].cheapest_path = pe082_matrix[row][column].downward_path;
		pe082_matrix[row][column].cheapest_sum = pe082_matrix[row][column].downward_sum;
		break;

	case UPWARD:
		// update the cheapest path/sum to be the values in the upward direction
		pe082_matrix[row][column].cheapest_path = pe082_matrix[row][column].upward_path;
		pe082_matrix[row][column].cheapest_sum = pe082_matrix[row][column].upward_sum;
		break;

	case RIGHT:
		// update the cheapest path/sum to be the values in the rightward direction
		pe082_matrix[row][column].cheapest_path = pe082_matrix[row][column].rightward_path;
		pe082_matrix[row][column].cheapest_sum = pe082_matrix[row][column].rightward_sum;
		break;
	}

	Reset_Paths(pe082_matrix, row, column);
}

void Reset_Paths(PE082_Matrix pe082_matrix[NxN][NxN], int row, int column)
{
	/* Reset all paths to the new cheapest route */

	pe082_matrix[row][column].downward_path = pe082_matrix[row][column].cheapest_path;
	pe082_matrix[row][column].upward_path = pe082_matrix[row][column].cheapest_path;
	pe082_matrix[row][column].rightward_path = pe082_matrix[row][column].cheapest_path;

	pe082_matrix[row][column].downward_sum = pe082_matrix[row][column].cheapest_sum;
	pe082_matrix[row][column].upward_sum = pe082_matrix[row][column].cheapest_sum;
	pe082_matrix[row][column].rightward_sum = pe082_matrix[row][column].cheapest_sum;
}
