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
	std::vector<int> input_row, top_triangle, bottom_triangle;
	std::vector<std::vector<int>> pe081_matrix;
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

	Top_Triangle(pe081_array);

	return 0;
}