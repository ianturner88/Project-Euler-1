#include <iostream>
#include <vector>
#include <algorithm>

#include "PE082.h"
#include "Minimal_Path.h"

std::vector<int> Minimal_Path(PE082_Matrix pe082_matrix[NxN][NxN])
{
	/* Determines the minimal path starting from any point in the left-most column and
	finishing at any point in the right-most column the matrix */

	for (int column = 0; column < NxN; column++)
	{
		Rightward_Path(pe082_matrix, column);
		Upward_Path(pe082_matrix, column);

		for (int counter = 0; counter < NxN; counter++)
		{
			Downward_Path(pe082_matrix, column);
			Rightward_Path(pe082_matrix, column);
			Upward_Path(pe082_matrix, column);
			column++;
		}

		Downward_Path(pe082_matrix, column);
		Rightward_Path(pe082_matrix, column);
	}

	return pe082_matrix[0][0].cheapest_path;
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
		pe082_matrix[row][column].rightward_sum = pe082_matrix[row][column].cheapest_sum
			+ pe082_matrix[row][(column + 1)].element_value;

		//test
		std::vector<int> test = pe082_matrix[row][(column + 1)].rightward_path;
		int test0 = pe082_matrix[row][column].rightward_sum;
		test0 = 9;
	}
}

void Upward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column)
{
	for (int row = 0; row < (NxN - 1); row++)
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
}

void Downward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column)
{
	for (int row = 0; row < (NxN - 1); row++)
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
}
