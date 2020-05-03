#include <iostream>
#include <vector>
#include <algorithm>

#include "PE082.h"
#include "Minimal_Path.h"

/* Build 2 comparison functions -> 1 for edge (2 comparisons) && 1 for middle (3 comparisons) */
/* Move row outside of path functions -> use pass by value */


std::vector<int> Minimal_Path(PE082_Matrix pe082_matrix[NxN][NxN])
{
	/* Determines the minimal path starting from any point in the left-most column and
	finishing at any point in the right-most column the matrix */

	int row;

	for (int column = 0; column < NxN; column++)
	{
		// reset to the top most row
		row = 0;
		Rightward_Path(pe082_matrix, column, row);
		Upward_Path(pe082_matrix, column, row);	

		for (int counter = 0; counter < NxN; counter++)
		{
			row++;
			Downward_Path(pe082_matrix, column, row);
			Rightward_Path(pe082_matrix, column, row);
			Upward_Path(pe082_matrix, column, row);
			column++;
		}

		row++;
		Downward_Path(pe082_matrix, column, row);
		Rightward_Path(pe082_matrix, column, row);
	}

	return pe082_matrix[0][0].cheapest_path;
}

void Identify_Cheapest_Path(std::vector<std::vector<int>> paths, PE082_Matrix pe082_matrix[NxN][NxN], 
	int row, int column)
{
	/* Identify the shortest point to a given index in the matrix.
	The vector paths contains all the valid approaches to a given
	index. */

	int shortest_path;

	// sort the vector to identify the cheapest path
	std::sort(paths[0].begin(), paths[0].end());
	// the shortest direction to approach the index from
	shortest_path = paths[0][1];

	switch (shortest_path)
	{
		case DOWNWARD:
			// set the cheapest path/sum to the approach from the downward direction
			pe082_matrix[row][column].cheapest_path = pe082_matrix[row][column].downward_path;
			pe082_matrix[row][column].cheapest_sum = pe082_matrix[row][column].downward_sum;
			break;

		case UPWARD:
			// set the cheapest path/sum to the approach from the upward direction
			pe082_matrix[row][column].cheapest_path = pe082_matrix[row][column].upward_path;
			pe082_matrix[row][column].cheapest_sum = pe082_matrix[row][column].upward_sum;
			break;

		case RIGHTWARD:
			// set the cheapest path/sum to the approach from the rightward direction
			pe082_matrix[row][column].cheapest_path = pe082_matrix[row][column].rightward_path;
			pe082_matrix[row][column].cheapest_sum = pe082_matrix[row][column].rightward_sum;
			break;
	}
}

void Rightward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column, int row)
{
	/* start the minimal path search by finding the right-ward path of
	every point in column 0 */

	// store the value which one traversed to arrive at the current point
	pe082_matrix[row][(column + 1)].rightward_path.push_back(pe082_matrix[row][column].element_value);
	// store the current element 
	pe082_matrix[row][(column + 1)].rightward_path.push_back(pe082_matrix[row][(column + 1)].element_value);

	// sum the cost of the rightward path 
	pe082_matrix[row][column].rightward_sum = pe082_matrix[row][column].cheapest_sum
		+ pe082_matrix[row][(column + 1)].element_value;

	//test
	std::vector<int> test = pe082_matrix[row][(column + 1)].rightward_path;
	int test0 = pe082_matrix[row][column].rightward_sum;
	test0 = 9;
}

void Upward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column, int row)
{

	// construct upward path
	pe082_matrix[row][column].upward_path.push_back(pe082_matrix[(row + 1)][column].element_value);
	pe082_matrix[row][column].upward_path.push_back(pe082_matrix[(row + 1)][(column + 1)].element_value);
	pe082_matrix[row][column].upward_path.push_back(pe082_matrix[row][(column + 1)].element_value);

	// upward path sum
	pe082_matrix[row][column].upward_sum = pe082_matrix[(row + 1)][column].cheapest_sum +
		pe082_matrix[(row + 1)][(column + 1)].element_value +
		pe082_matrix[row][(column + 1)].element_value;

	//test
	std::vector<int> test = pe082_matrix[row][column].upward_path;
	int test0 = pe082_matrix[row][column].upward_sum;
	test0 = 9;
}

void Downward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column, int row)
{
	// construct downward path
	pe082_matrix[row][column].downward_path.push_back(pe082_matrix[row][column].element_value);
	pe082_matrix[row][column].downward_path.push_back(pe082_matrix[row][(column + 1)].element_value);
	pe082_matrix[row][column].downward_path.push_back(pe082_matrix[(row + 1)][(column + 1)].element_value);

	// calculate upward path sum
	pe082_matrix[row][column].downward_sum = pe082_matrix[row][column].cheapest_sum +
		pe082_matrix[row][(column + 1)].element_value +
		pe082_matrix[(row + 1)][(column + 1)].element_value;

	//test
	std::vector<int> test = pe082_matrix[row][column].downward_path;
	int test0 = pe082_matrix[row][column].downward_sum;
	test0 = 4;
}
