#include <vector>

#include "PE081_enum.h"

std::vector<int> Top_Triangle(int pe081_array[][5], int triangle_layer_counter)
{
	/* partitions the top half of the array into a triangle
	(see documentation for a more rigorous explanation) */

	std::vector<int> top_triangle_layer;
	int number, row, column = 0;

	for (int counter = triangle_layer_counter; counter >= 0; counter--)
	{
		/*identify the number to be placed in the triangle vector*/

		//row coordinate
		row = counter;
		//identify the number
		number = pe081_array[row][column];
		//column coordinate
		column++;

		//store the number in the top half triangle vector
		top_triangle_layer.push_back(number);
	}

	//returns one layer of the upper-half triangle
	return top_triangle_layer;
}

std::vector<int> Bottom_Triangle(int pe081_array[][5], int column_counter, int row_stopper)
{
	/* partitions the bottom half of the array into a triangle
	(see documentation for a more rigorous explanation) */

	std::vector<int> bottom_triangle_layer;
	int number, row = NxN - 1;

	for (int row_counter = NxN - 1; row_counter >= row_stopper; row_counter--)
	{
		//identify the number
		number = pe081_array[row][column_counter];
		//store the number in the new layer
		bottom_triangle_layer.push_back(number);
		//move up one row
		row--;
		//move one column to the right
		column_counter++;
	}

	return bottom_triangle_layer;
}