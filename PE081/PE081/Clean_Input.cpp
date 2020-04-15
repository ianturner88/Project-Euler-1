#include <vector>
#include <string>

#include "PE081.h"
#include "Clean_Input.h"

void PE081_Matrix(std::vector<std::string> pe081_matrix_string, int pe081_matrix[][NxN])
{
	/* Convert the string matrix to an integer matrix */
	std::string input_line, number_string;
	char character;
	int number_counter = 0, row = 0, column = 0;

	for (int i = 0; i < pe081_matrix_string.size(); i++)
	{
		// extract the input lines to identify/convert the numbers from strings to integers
		input_line = pe081_matrix_string[i];

		for (int j = 0; (j <= input_line.size()) && (number_counter <= NxN); j++)
		{
			//identify the individual numbers separated by commas on every line
			character = input_line[j];

			if ((character == ',') || (character == '\0'))
			{
				//test
				int test = String_to_Int(number_string);
				std::string test0 = number_string;
				int test1 = row;
				int test2 = column;

				//store the numbers in the integer array
				pe081_matrix[row][column] = String_to_Int(number_string);
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