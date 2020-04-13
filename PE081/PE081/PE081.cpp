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
	int pe081_array[NxN][NxN], triangle_layer_counter = NxN;

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

	//std::vector<int> Top_Triangle(int pe081_array[][5], int layer_starting_point)

	while (triangle_layer_counter > 0)
	{
		//identify the left most corner to start constructing the next triangle layer
		triangle_layer_counter--;
		//construct a layer of the top triangle (see documentation)
		triangle_layer = Top_Triangle(pe081_array, triangle_layer_counter);
		//build the top triangle
		top_triangle.push_back(triangle_layer);
	}

	std::reverse(top_triangle.begin(), top_triangle.end());
	int test = 0;

	return 0;
}