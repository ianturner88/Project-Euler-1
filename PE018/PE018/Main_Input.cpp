#include <iostream>
#include <string>

#include "Functions_Input.h"
#include "ProjectEulerLibrary/ProjectEulerLibrary.h"

int Clean_Input(std::vector<int> pyramid, int& row_counter, std::string input_line_x)
{
	std::string output;
	int number_int;

	output = Remove_Whitespace(input_line_x);
	number_int = Euler::String_to_Int(output);
	std::cout << output;

	row_counter++;

	return 0;
}