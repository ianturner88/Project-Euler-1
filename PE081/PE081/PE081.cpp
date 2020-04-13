// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Clean_Input.h"
#include "PE081_enum.h"
#include "Triangles.h"

int main() {
	std::string input_line;
	std::ifstream input_file("test.txt");
	std::vector<int> input_row, triangle_layer;
	std::vector<std::vector<int>> pe081_matrix, top_triangle, bottom_triangle;
	int pe081_array[NxN][NxN], triangle_layer_counter = NxN, 
		bottom_triangle_column_counter, row_stopper = NxN - 1;

	if (input_file.is_open())
	{
		//read in the file
		while (getline(input_file, input_line))
		{
			input_row = Tokenize_String(input_line);
			pe081_matrix.push_back(input_row);
		}
		input_file.close();

		PE081_Matrix(pe081_array, pe081_matrix);
	}
	// the file did not exist
	else std::cout << "Unable to open file";

	while (triangle_layer_counter > 0)
	{
		//identify the left most corner to start constructing the next triangle layer
		triangle_layer_counter--;
		//construct a layer of the top triangle (see documentation)
		triangle_layer = Top_Triangle(pe081_array, triangle_layer_counter);
		//build the top triangle
		top_triangle.push_back(triangle_layer);
	}

	//invert the triangle so the base is on the bottom
	std::reverse(top_triangle.begin(), top_triangle.end());

	//reset triangle counter
	bottom_triangle_column_counter = NxN;

	while (bottom_triangle_column_counter > 0)
	{
		//identify the left most corner (column) to start constructing the next triangle layer
		bottom_triangle_column_counter--;
		//construct a layer of the bottom triangle (see documentation)
		triangle_layer = Bottom_Triangle(pe081_array, bottom_triangle_column_counter, row_stopper);
		//build the bottom triangle
		bottom_triangle.push_back(triangle_layer);
		//the right cutoff for the new layer
		row_stopper--;
	}


	return 0;
}