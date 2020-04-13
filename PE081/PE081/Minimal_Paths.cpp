#include <vector>

#include "PE081_enum.h"

int Minimal_Path_MidPoints(std::vector<std::vector<int>> input_triangle, int row, int column)
{
	/* determines the minimal path for a specified starting path */

	//the starting point for a new minimal path route
	int starting_number = input_triangle[row][column];
	int left_sum = starting_number, right_sum = starting_number;

	for (int i = row; i > 0; i--)
	{
		left_sum += input_triangle[row - 1][column - 1];
		right_sum += input_triangle[row - 1][column];
	}

	return 0;
}

int Minimal_Path_Left_EndPoint(std::vector<std::vector<int>> input_triangle, int row)
{
	/* determines the minimal path for a specified starting path */

	//the starting point for a new minimal path route
	int left_sum = 0, column = 0;
	int starting_number = input_triangle[row][column];

	for (int i = row; i >= 0; i--)
	{
		//test
		int test = input_triangle[i][column];

		left_sum += input_triangle[i][column];
	}

	return left_sum;
}