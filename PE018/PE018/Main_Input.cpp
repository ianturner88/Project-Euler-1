#include <iostream>
#include <string>

#include "Functions_Input.h"
#include "ProjectEulerLibrary/ProjectEulerLibrary.h"

int Clean_Input(std::vector <std::vector<int>> pyramid, int& row_counter, std::string input_line_x)
{
	std::string output, two_digit_number;
	int number_int;
	   
	for (int i = 0; i < row_counter; i++)
	{
		/*retrieve the numbers from each row --> every row has the same number of 
		numbers has it's row count + 1 --> example: row 2 has 3 numbers */

		//remove the whitespace infront of the number
		output = Remove_Whitespace(input_line_x);

		for (int i = 0; i < 2; i++)
		{
			/*every number has 2 digits --> example: 02, 14
			retrieve both digits*/

			//concatenates the first 2 digits of output together
			two_digit_number += output[i];
		}

		//converts string_int to int
		number_int = Euler::String_to_Int(two_digit_number);

	}

	//indentifies the new number of numbers to be retrieved
	row_counter++;

	return 0;
}

/*
// declare 2D vector
vector< vector<int> > myVector;
// make new row (arbitrary example)
vector<int> myRow(1,5);
myVector.push_back(myRow);
// add element to row
myVector[0].push_back(1);
*/