#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "PE081.h"
#include "Clean_Input.h"
#include "Minimal_Path.h"

int main()
{
	std::string input_line;
	std::ifstream input_file("test.txt");
	std::vector<std::string> pe081_matrix_string;
	PE081_Matrix pe081_matrix[NxN][NxN];

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

	Construct_Object_Array(pe081_matrix_string, pe081_matrix);

	//initialize the first element's minimal path
	pe081_matrix[0][0].current_minimual_sum = pe081_matrix[0][0].element_value;

	Minimal_Path_Sum(pe081_matrix);

	getchar();

	return 0;
}

void print(PE081_Matrix pe081_matrix[NxN][NxN])
{
	for (int i = 0; i < NxN; i++)
	{
		for (int j = 0; j < NxN; j++)
		{
			std::cout << pe081_matrix[i][j].element_value << " ";
		}

		std::cout << std::endl;
	}
}