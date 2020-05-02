#include <iostream>
#include <vector>

#include "PE082.h"
#include "Minimal_Path.h"

int Minimal_Path_Sum(PE082_Matrix pe082_matrix[NxN][NxN])
{
	/* Determines the minimal path starting from the top left corner of the matrix
	to bottom right corner of the matrix */
	int column = 0, temp_sum;

	Rightward_Path(pe082_matrix, column);

	// main algorithm starts in column 1
	column = 1;

	for (int row = 0; row < (NxN - 1); row++)
	{
		// algorithm always starts in the top left corner
		row = 0;

		Downward_Path(pe082_matrix, column);
		Upward_Path(pe082_matrix, column);
		Rightward_Path(pe082_matrix, column);
	}

	/* the cheapest path from the top left corner
	of the matrix to bottom right corner of the matrix */
	return pe082_matrix[(NxN - 1)][(NxN - 1)].downward_sum;
}

void Rightward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column)
{
	for (int row = 0; row < NxN; row++)
	{
		/* start the minimal path search by finding the right-ward path of
		every point in column 0 */
		pe082_matrix[row][(column + 1)].rightward_path.push_back(pe082_matrix[row][column].element_value);
		pe082_matrix[row][(column + 1)].rightward_sum = pe082_matrix[row][column].element_value
			+ pe082_matrix[row][(column + 1)].element_value;

		//test
		std::vector<int> test = pe082_matrix[row][(column + 1)].rightward_path;
		int test0 = 0;
	}
}

void Upward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column)
{
	for (int row = (NxN - 1); row > 1; row--)
	{
		// upward path
		pe082_matrix[(row - 1)][column].downward_path.push_back(pe082_matrix[row][column].element_value);
		pe082_matrix[(row - 1)][column].downward_sum = pe082_matrix[row][column].element_value
			+ pe082_matrix[(row + 1)][column].element_value;

		//test
		std::vector<int> test = pe082_matrix[(row + 1)][column].downward_path;
		int test0 = 0;
	}
}

void Downward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column)
{
	for (int row = 0; row < (NxN - 2); row++)
	{
		// downward path
		pe082_matrix[(row + 1)][column].downward_path.push_back(pe082_matrix[row][column].element_value);
		pe082_matrix[(row + 1)][column].downward_sum = pe082_matrix[row][column].element_value
			+ pe082_matrix[(row + 1)][column].element_value;

		//test
		std::vector<int> test = pe082_matrix[(row + 1)][column].downward_path;
		int test0 = 0;
	}
}

std::vector<int> Cheapest_Path(PE082_Matrix pe082_matrix[NxN][NxN], int row, int column)
{
	/*identifies to shortest path to a given point */
	std::vector<std::vector<int>> cheapest_path;
	std::vector<int> path;

	path.push_back(pe082_matrix[row][column].downward_sum);
	path.push_back(DOWNWARDS);
	cheapest_path.push_back(path);
	path.clear();

	path.push_back(pe082_matrix[row][column].upward_sum);
	path.push_back(UPWARDS);
	cheapest_path.push_back(path);
	path.clear();

	path.push_back(pe082_matrix[row][column].rightward_sum);
	path.push_back(RIGHT);
	cheapest_path.push_back(path);
	path.clear();


	return path;
}
