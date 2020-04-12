// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Clean_Input.h"
#include "enum.h"

int main() {
	std::string input_line;
	std::ifstream input_file("PE081.txt");
	std::vector<int> input_row;
	int row_counter = 0;
	std::vector<std::vector<int>> pe081_matrix;
	int pe081_array[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];

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


	return 0;
}