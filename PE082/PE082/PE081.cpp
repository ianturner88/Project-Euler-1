#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "PE081.h"
#include "Clean_Input.h"

int main()
{
	std::string input_line;
	std::ifstream input_file("PE081.txt");
	std::vector<std::string> pe081_matrix_string;
	PE081_Matrix PE081Object_array[NxN][NxN];

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

	Construct_Object_Array(pe081_matrix_string, PE081Object_array);

	for (int i = 0; i < NxN; i++)
	{
		for (int j = 0; j < NxN; j++)
		{
			std::cout << PE081Object_array[i][j].indices_value << " ";
		}

		std::cout << std::endl;
	}

	getchar();

	return 0;
}