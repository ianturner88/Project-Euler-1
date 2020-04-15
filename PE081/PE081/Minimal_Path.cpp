#include <vector>

#include "PE081.h"

int Minimal_Path(int pe081_matrix[][NxN])
{
	/* returns the minimal path to traversing the matrix
	from the top left to the bottom right corners.

	The algorithm starts in the top left corner of the array.
	The minimal path to a particular point is stored in the
	vector. */

	std::vector<int> minimal_path;
	int row = 1, column = 0, left_sum, right_sum, starting_point, row_temp;

	//initialize the vector to the top left corner of the array
	minimal_path.push_back(pe081_matrix[row][column]);

	for (int diagonal_counter = 1; diagonal_counter < (NxN * 2 + 1); diagonal_counter++)
	{
		//reset to the left-most column
		column = 0;
		row_temp = row;

		for (int i = 0; i <= diagonal_counter; i++)
		{
			starting_point = pe081_matrix[row_temp][column];
			row_temp--;
			column++;

			minimal_path.push_back(starting_point);
		}

		//move down one row
		row++;
	}

	return 0;
}