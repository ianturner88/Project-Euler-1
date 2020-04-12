#include <iostream>
#include <vector>
#include <math.h>

#include "Clean_Input.h"
#include "enum.h"

enum Digits {
	ZERO = 48, NINE = 57
};

void PE081_Matrix(int pe081_array[][NUMBER_OF_COLUMNS], std::vector<std::vector<int>> pe081_matrix)
{
	int number;

	for (int i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			number = pe081_matrix[i][j];
			pe081_array[i][j] = number;
		}
	}

	for (int i = 0; i < NUMBER_OF_ROWS; i++)
	{
		for (int j = 0; j < NUMBER_OF_COLUMNS; j++)
		{
			std::cout << pe081_array[i][j] << " ";
		}
		std::cout << std::endl;
	}

	int test0 = 0;
}

std::vector<int> Tokenize_String(std::string input)
{
	/* Extracts the individual numbers and stores them in a vector as int's */
	std::vector<int> matrix_row;
	char comma = ',';
	std::string number;
	int sum;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == comma)
		{
			//the number is successfully re-constructed
			sum = String_to_Int(number);
			//store the number as an int
			matrix_row.push_back(sum);
			//reset for next string
			number.clear();
			//skip the comma
			i++;
		}

		//construct the number
		number += input[i];
	}

	sum = String_to_Int(number);
	matrix_row.push_back(sum);

	return matrix_row;
}

int String_to_Int(std::string input)
{
	/* Converts an input string to an integer */

	int sum = 0, counter = input.size() - 1;
	char digit;

	for (int i = 0; i < input.size(); i++)
	{
		//extract each digit of the number and convert to an int individually
		digit = input[i];
		//check that the digit is between 0 and 9
		Is_Valid_Digit(digit);
		//place digit according to power of 10
		sum += ((digit - '0') * pow(10, counter));
		//shift towards 0 to power counter
		counter--;
	}

	return sum;
}

void Is_Valid_Digit(char digit)
{
	if ((digit < ZERO) || (digit > NINE))
	{
		std::cout << "The input is not a valid numerical number." << std::endl;
	}
}