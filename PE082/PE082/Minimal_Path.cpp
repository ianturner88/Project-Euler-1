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
	std::vector<std::vector<int>> approaches;

	for (int column = 0; column < (NxN - 1); column++)
	{
		// reset to the top most row
		row = 0;
		approaches.clear();

		// identify the cheapest approach to indicies in the top row
		approaches.push_back(Rightward_Path(pe082_matrix, column, row));
		approaches.push_back(Upward_Path(pe082_matrix, column, row));
		Set_Cheapest_Path(approaches, pe082_matrix, row, (column + 1));

		for (row = 1; row < (NxN - 1); row++)
		{
			// reset
			approaches.clear();

			// identify the cheapest approach to indicies in the non-outter edge rows
			// the downward approach
			approaches.push_back(Downward_Path(pe082_matrix, column, row));
			// the rightward approach
			approaches.push_back(Rightward_Path(pe082_matrix, column, row));
			// the upward approach
			approaches.push_back(Upward_Path(pe082_matrix, column, row));
			// identify the cheapest path
			Set_Cheapest_Path(approaches, pe082_matrix, row, (column + 1));
		}

		// reset
		approaches.clear();

		// identify the cheapest approach to indicies in the bottom row
		approaches.push_back(Downward_Path(pe082_matrix, column, row));
		approaches.push_back(Rightward_Path(pe082_matrix, column, row));
		Set_Cheapest_Path(approaches, pe082_matrix, row, (column + 1));
	}

	pe082_matrix[0][(NxN - 1)].cheapest_sum;

	return pe082_matrix[0][(NxN - 1)].cheapest_path;
}

void Set_Cheapest_Path(std::vector<std::vector<int>> paths, PE082_Matrix pe082_matrix[NxN][NxN],
	int row, int column)
{
	/* Identify the shortest point to a given index in the matrix.
	The vector paths contains all the valid approaches to a given
	index. */

	// sort the vector to identify the cheapest path
	std::sort(paths.begin(), paths.end(), Sort_Vector);
	// the shortest direction to approach the index from
	int shortest_path = paths[0][1];

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

bool Sort_Vector(const std::vector<int>& v1, const std::vector<int>& v2)
{
	/* sort the rows on basis of column 0, the column containing the
	cost acquired to reach a particular point */
	return v1[0] < v2[0];
}

std::vector<int> Rightward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column, int row)
{
	/* start the minimal path search by finding the right-ward path of
	every point in column 0 */

	std::vector<int> rightward_cost;

	// store the value which one traversed to arrive at the current point
	pe082_matrix[row][(column + 1)].rightward_path.push_back(pe082_matrix[row][column].element_value);
	// store the current element 
	pe082_matrix[row][(column + 1)].rightward_path.push_back(pe082_matrix[row][(column + 1)].element_value);

	// sum the cost of the rightward path 
	pe082_matrix[row][(column + 1)].rightward_sum = pe082_matrix[row][column].cheapest_sum;

	rightward_cost.push_back(pe082_matrix[row][(column + 1)].rightward_sum);
	rightward_cost.push_back(RIGHTWARD);

	return rightward_cost;
}

std::vector<int> Upward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column, int row)
{
	std::vector<int> upward_cost;

	// construct upward path
	pe082_matrix[row][(column + 1)].upward_path.push_back(pe082_matrix[(row + 1)][column].element_value);
	pe082_matrix[row][(column + 1)].upward_path.push_back(pe082_matrix[(row + 1)][(column + 1)].element_value);
	pe082_matrix[row][(column + 1)].upward_path.push_back(pe082_matrix[row][(column + 1)].element_value);

	// upward path sum
	pe082_matrix[row][(column + 1)].upward_sum = pe082_matrix[(row + 1)][column].cheapest_sum +
		pe082_matrix[(row + 1)][(column + 1)].element_value;

	upward_cost.push_back(pe082_matrix[row][(column + 1)].upward_sum);
	upward_cost.push_back(UPWARD);

	return upward_cost;
}

std::vector<int> Downward_Path(PE082_Matrix pe082_matrix[NxN][NxN], int column, int row)
{
	std::vector<int> downward_cost;

	// construct downward path
	pe082_matrix[row][(column + 1)].downward_path.push_back(pe082_matrix[(row - 1)][column].element_value);
	pe082_matrix[row][(column + 1)].downward_path.push_back(pe082_matrix[(row - 1)][(column + 1)].element_value);
	pe082_matrix[row][(column + 1)].downward_path.push_back(pe082_matrix[row][(column + 1)].element_value);

	// calculate upward path sum
	pe082_matrix[row][(column + 1)].downward_sum = pe082_matrix[(row - 1)][column].cheapest_sum +
		pe082_matrix[(row - 1)][(column + 1)].element_value;

	downward_cost.push_back(pe082_matrix[row][(column + 1)].downward_sum);
	downward_cost.push_back(DOWNWARD);

	return downward_cost;
}
