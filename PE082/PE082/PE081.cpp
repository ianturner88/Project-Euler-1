#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "Clean_Input.h"
#include "PE081.h"

int main()
{
	std::string input_line;
	std::ifstream input_file("PE081.txt");
	std::vector<std::string> pe081_matrix_string;
	int pe081_matrix[NxN][NxN];

	if (input_file.is_open())
	{
		//read in the file
		while (getline(input_file, input_line))
		{
			pe081_matrix_string.push_back(input_line);
		}
		input_file.close();
	}
	// the file did not exist
	else std::cout << "Unable to open file";

	PE081_Matrix(pe081_matrix_string, pe081_matrix);

	for (int i = 0; i < NxN; i++)
	{
		for (int j = 0; j < NxN; j++)
		{
			std::cout << pe081_matrix[i][j] << " ";
		}

		std::cout << std::endl;
	}

	return 0;
}