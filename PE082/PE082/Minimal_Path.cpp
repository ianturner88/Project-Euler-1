#include <iostream>

#include "PE081.h"
#include "Minimal_Path.h"

int Minimal_Path_Sum(PE081_Matrix pe081_matrix[NxN][NxN])
{
	/* Determines the minimal path starting from the top left corner of the matrix
	to bottom right corner of the matrix */
	int row = 0, column = 0, temp_sum;

	for (row; row < (NxN - 1); row++)
	{
		for (column; column < (NxN - 1); column++)
		{
			// start in the top left corner of the matrix
			//right-ward sum
			Rightward_Path(pe081_matrix, row, column);
			// downward sum
			Downward_Path(pe081_matrix, row, column);
		}
		// downward sum
		Downward_Path(pe081_matrix, row, column);

		column = 0;
	}

	for (int i = 0; i < (NxN - 1); i++)
	{
		Rightward_Path(pe081_matrix, row, column);
		column++;
	}

	/* the cheapest path from the top left corner
	of the matrix to bottom right corner of the matrix */
	return pe081_matrix[(NxN - 1)][(NxN - 1)].current_minimual_sum;
}

//the right-ward sum
void Rightward_Path(PE081_Matrix pe081_matrix[NxN][NxN], int row, int column)
{
	int test0 = pe081_matrix[row][(column + 1)].element_value;

	//right-ward sum
	int	temp_sum = pe081_matrix[row][column].current_minimual_sum +
		pe081_matrix[row][(column + 1)].element_value;
	if ((temp_sum < pe081_matrix[row][(column + 1)].current_minimual_sum) ||
		(pe081_matrix[row][(column + 1)].round == 0))
	{
		//the new sum is cheaper OR the element has not yet been touched
		pe081_matrix[row][(column + 1)].current_minimual_sum = temp_sum;
	}
	// indicates the element has alread been travesered at least once
	pe081_matrix[row][(column + 1)].round++;
}

void Downward_Path(PE081_Matrix pe081_matrix[NxN][NxN], int row, int column)
{
	// downward sum
	int temp_sum = pe081_matrix[row][column].current_minimual_sum +
		pe081_matrix[(row + 1)][(column)].element_value;
	if ((temp_sum < pe081_matrix[(row + 1)][column].current_minimual_sum) ||
		(pe081_matrix[(row + 1)][column].round == 0))
	{
		//the new sum is cheaper OR the element has not yet been touched
		pe081_matrix[(row + 1)][column].current_minimual_sum = temp_sum;
	}
	// indicates the element has alread been travesered at least once
	pe081_matrix[(row + 1)][(column)].round++;

}