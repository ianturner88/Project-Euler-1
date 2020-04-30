#include <vector>
#include <string>

#include "PE082.h"
#include "Clean_Input.h"

void Construct_Object_Array(std::vector<std::string> pe082_matrix_string, PE082_Matrix pe082_matrix[NxN][NxN])
{
	/* Convert the string matrix to an integer matrix */
	std::string input_line, number_string;
	char character;
	int number_counter = 0, row = 0, column = 0;

	for (int i = 0; i < pe082_matrix_string.size(); i++)
	{
		// extract the input lines to identify/convert the numbers from strings to integers
		input_line = pe082_matrix_string[i];

		for (int j = 0; (j <= input_line.size()) && (number_counter <= NxN); j++)
		{
			//identify the individual numbers separated by commas on every line
			character = input_line[j];

			if ((character == ',') || (character == '\0'))
			{
				//store the numbers in the integer array
				pe082_matrix[row][column].set_Indice(String_to_Int(number_string));
				//initalize the cheapest path for every starting point in the integer array
				pe082_matrix[row][column].set_Cheapest_Sum(String_to_Int(number_string));
				//reset the string where the numbers are re-constructed
				number_string.clear();
				//move to the next int holding slot
				column++;
				//ensures the max size of the array is not exceeded
				number_counter++;
			}
			else
			{
				//add the ones or tens digit to the number
				number_string += input_line[j];
			}
		}
		//move down to the next row
		row++;
		//reset the counters to the left position of the array
		column = 0;
		number_counter = 0;
	}
}

int String_to_Int(std::string input)
{
	/* converts a string-number to an integer-number */

	char digit;
	int number = 0, counter = input.size() - 1;

	for (int i = 0; i < input.size(); i++)
	{
		//extract each digit of the number and convert to an int individually
		digit = input[i];
		//place digit according to power of 10
		number += ((digit - '0') * pow(10, counter));
		//shift towards 0 to power counter
		counter--;
	}

	return number;
}