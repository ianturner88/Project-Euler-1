#include <iostream>
#include <vector>

#include "PE082.h"
#include "Minimal_Path.h"

int Minimal_Path_Sum(PE082_Matrix pe082_matrix[NxN][NxN])
{
	/* Determines the minimal path starting from the top left corner of the matrix
	to bottom right corner of the matrix */
	int row = 0, column = 0, temp_sum;

	for (row; row < NxN; row++)
	{
		/* start the minimal path search by finding the right-ward path of
		every point in column 0 */
		Rightward_Path(pe082_matrix, row, column);
	}

	// main algorithm starts in column 1
	column = 1;

	for (int i = 0; i < (NxN - 1); i++)
	{
		// algorithm always starts in the top left corner
		row = 0;

		for (int j = row; j < (NxN - 2); j++)
		{
			Downward_Path(pe082_matrix, row, column);
		}

		for (int j = (NxN - 1); j > 1; j--)
		{
			Upward_Path(pe082_matrix, row, column);
		}

		for (int j = row; j < (NxN - 1); j++)
		{
			Rightward_Path(pe082_matrix, row, column);
		}
	}

	/* the cheapest path from the top left corner
	of the matrix to bottom right corner of the matrix */
	return pe082_matrix[(NxN - 1)][(NxN - 1)].cheapest_sum;
}

void Upward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int row, int column)
{
	//calculates the sum in the right-ward direction
	int	temp_sum = pe082_matrix[row][column].cheapest_sum +
		pe082_matrix[(row + 1)][column].element_value;

	if ((temp_sum < pe082_matrix[row][column].cheapest_sum) ||
		(pe082_matrix[row][(column + 1)].is_untouched == true))
	{
		//the new sum is cheaper OR the element has not yet been touched
		pe082_matrix[row][column].cheapest_sum = temp_sum;
		//stores the cheapest path to the current element
		pe082_matrix[row][column].cheapest_path = Cheapest_Path(pe082_matrix, row, column);
	}

	// indicates the element has alread been travesered at least once
	pe082_matrix[row][column].is_untouched = true;
}

void Downward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int row, int column)
{
	//calculates the sum in the right-ward direction
	int	temp_sum = pe082_matrix[row][column].cheapest_sum +
		pe082_matrix[(row + 1)][column].element_value;

	if ((temp_sum < pe082_matrix[row][column].cheapest_sum) ||
		(pe082_matrix[row][(column + 1)].is_untouched == true))
	{
		//the new sum is cheaper OR the element has not yet been touched
		pe082_matrix[row][column].cheapest_sum = temp_sum;
		//stores the cheapest path to the current element
		pe082_matrix[row][column].cheapest_path = Cheapest_Path(pe082_matrix, row, column);
	}

	// indicates the element has alread been travesered at least once
	pe082_matrix[row][column].is_untouched = true;
}

void Rightward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int row, int column)
{
	//calculates the sum in the right-ward direction
	int	temp_sum = pe082_matrix[row][column].cheapest_sum +
		pe082_matrix[row][(column + 1)].element_value;

	if ((temp_sum < pe082_matrix[row][column].cheapest_sum) ||
		(pe082_matrix[row][(column + 1)].is_untouched == true))
	{
		//the new sum is cheaper OR the element has not yet been touched
		pe082_matrix[row][column].cheapest_sum = temp_sum;
		//stores the cheapest path to the current element
		pe082_matrix[row][column].cheapest_path = Cheapest_Path(pe082_matrix, row, column);
	}

	// indicates the element has alread been travesered at least once
	pe082_matrix[row][column].is_untouched = true;
}

std::vector<int> Cheapest_Path(PE082_Matrix pe082_matrix[NxN][NxN], int row, int column)
{
	/* returns a vector containing the cheapest path across the matrix */

	//fetches the shortest existing shortest path
	std::vector<int> cheapest_path = pe082_matrix[row][column].cheapest_path;
	//adds the next element to the shortest path
	cheapest_path.push_back(pe082_matrix[row][column].element_value);
	return cheapest_path;
}