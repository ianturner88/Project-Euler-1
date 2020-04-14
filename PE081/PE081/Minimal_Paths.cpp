#include <vector>

#include "PE081_enum.h"

int Minimal_Path_Middle_Points(std::vector<std::vector<int>> input_triangle, int column)
{
	/* determines the minimal path for a specified starting path */

	//the starting point for a new minimal path route
	int starting_number = input_triangle[(NxN - 1)][column],
		left_sum = starting_number, right_sum = starting_number,
		row = NxN - 2, row_size_counter = 0;
	std::vector<std::vector<int>> minimal_path;
	std::vector<int> temp;

	for (row; row > 0; row--)
	{
		row_size_counter++;
		for (int i = 0; i < row_size_counter; i++)
		{
			//left sum
			left_sum += input_triangle[row][column - 1];
			temp.push_back(left_sum);
			temp.push_back(column - 1);
			minimal_path.push_back(temp);
			temp.clear();

			//test
			int test = input_triangle[row][column - 1];
			int test0 = column - 1;

			//right sum
			right_sum += input_triangle[row][column];
			temp.push_back(right_sum);
			temp.push_back(column);
			minimal_path.push_back(temp);

			//test
			int test1 = input_triangle[row][column];
			int test2 = column;
			int test3 = 0;

			column--;
			temp.clear();
		}
	}

	//return the minimal path
	return left_sum = (left_sum < right_sum) ? left_sum : right_sum;
}

int Minimal_Path_Left_EndPoint(std::vector<std::vector<int>> input_triangle, int row)
{
	/* determines the minimal path for the left side of the triangle */

	//the starting point for a new minimal path route
	int left_sum = 0, column = 0;

	for (int i = row; i >= 0; i--)
	{
		left_sum += input_triangle[i][column];
	}

	return left_sum;
}

int Minimal_Path_Right_EndPoint(std::vector<std::vector<int>> input_triangle)
{
	/* determines the minimal path for the right side of the triangle */

	int row = (NxN - 1), column = (NxN - 1), right_sum = 0;

	for (int i = row; i >= 0; i--)
	{
		//test
		int test = input_triangle[i][i];

		right_sum += input_triangle[i][i];
	}

	return right_sum;
}