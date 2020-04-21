#include <iostream>

#include "PE081.h"

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

			int test = pe081_matrix[row][column].element_value;

			//right-ward sum
			temp_sum = pe081_matrix[row][column].current_minimual_sum +
				pe081_matrix[row][(column + 1)].element_value;
			if ((temp_sum < pe081_matrix[row][(column + 1)].current_minimual_sum) ||
				(pe081_matrix[row][(column + 1)].round == 0))
			{
				//the new sum is cheaper OR the element has not yet been touched
				pe081_matrix[row][(column + 1)].current_minimual_sum = temp_sum;
			}
			// indicates the element has alread been travesered at least once
			pe081_matrix[row][(column + 1)].round++;

			// downward sum
			temp_sum = pe081_matrix[row][column].current_minimual_sum +
				pe081_matrix[(row + 1)][(column)].element_value;
			if ((temp_sum < pe081_matrix[(row + 1)][column].current_minimual_sum) ||
				(pe081_matrix[(row + 1)][column].round == 0))
			{
				//the new sum is cheaper OR the element has not yet been touched
				pe081_matrix[(row + 1)][column].current_minimual_sum = temp_sum;
			}
			// indicates the element has alread been travesered at least once
			pe081_matrix[row][(column + 1)].round++;
		}

		column = 0;
	}

	/* the cheapest path from the top left corner
	of the matrix to bottom right corner of the matrix */
	return pe081_matrix[(NxN - 1)][(NxN - 1)].current_minimual_sum;
}

//the right-ward sum
void Rightward_Path(PE081_Matrix pe081_matrix[NxN][NxN], int row, int column)
{
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

void Leftward_Path(PE081_Matrix pe081_matrix[NxN][NxN], int row, int column)
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
	pe081_matrix[row][(column + 1)].round++;

}