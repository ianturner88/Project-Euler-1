#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>

#include "PE082.h"
#include "Clean_Input.h"
#include "Minimal_Path.h"

int main()
{
	std::string input_line;
	std::ifstream input_file("test.txt");
	std::vector<std::string> pe082_matrix_string;
	PE082_Matrix pe082_matrix[NxN][NxN];
	clock_t timeStamp = clock();

	if (input_file.is_open())
	{
		//read in the file
		while (getline(input_file, input_line))
		{
			pe082_matrix_string.push_back(input_line);
		}
		input_file.close();
	}
	// the file did not exist
	else std::cout << "Unable to open file";

	Construct_Object_Array(pe082_matrix_string, pe082_matrix);

	Minimal_Path_Sum(pe082_matrix);

	std::cout << "Total executon time: " << (float)timeStamp / CLOCKS_PER_SEC << " seconds." << std::endl << std::endl;

	getchar();

	return 0;
}