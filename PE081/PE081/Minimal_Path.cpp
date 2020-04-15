#include <vector>

#include "PE081.h"

int Minimal_Path(int pe081_matrix[][NxN])
{
	/* returns the minimal path to traversing the matrix from the top left to the bottom right corners.

	The algorithm starts in the top left corner of the array. The minimal path to a particular point
	is stored in the vector. */

	std::vector<std::vector<int>> minimal_path;
	std::vector<int> temp;
	int row = 0, column = 0, downward_sum, rightward_sum, starting_point, row_temp;

	//initialize the vector to the top left corner of the array
	temp.push_back(pe081_matrix[row][column]);
	minimal_path.push_back(temp);
	temp.clear();

	for (int diagonal_counter = 0; diagonal_counter < (NxN * 2 + 1); diagonal_counter++)
	{
		//reset to the left-most column
		column = 0;
		row_temp = row;

		for (int i = 0; i <= diagonal_counter; i++)
		{
			starting_point = minimal_path[0][i];

			//the downward traversing option
			downward_sum = starting_point + pe081_matrix[row_temp + 1][column];
			temp.push_back(downward_sum);
			//the leftward traversing option
			rightward_sum = starting_point + pe081_matrix[row_temp][column + 1];
			temp.push_back(rightward_sum);

			//store the results
			minimal_path.push_back(temp);

			//update to identify the next starting point number
			row_temp--;
			column++;
		}

		//erase the previous shortest path
		minimal_path.erase(minimal_path.begin()+0);

		//move down one row
		row++;
	}

	return 0;
}