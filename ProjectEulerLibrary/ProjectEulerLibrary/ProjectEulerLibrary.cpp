#include <iostream>
#include <vector>

#include "ProjectEulerLibrary.h"

namespace Euler
{
	void Digit_Factorial_Chains(int n, std::vector<int>& digit_factorial_chains)
	{
		/*Calculates the factorials up to the digit n*/

		int digit_factorial_sum = 1;

		for (int i = 1; i < n; i++)
		{
			//(i-1)'s sum multipled with i for i's digit factorial 
			digit_factorial_sum *= i;

			//store the result 
			digit_factorial_chains.push_back(digit_factorial_sum);
		}
	}

	bool Is_Digit(char digit_char)
	{
		/*Determines if a given input is a digit between 0 and 9*/

		int digit_value;
		bool is_digit = false;

		/*sets the variable digit_value equal to the ASCII value
		of the char passed into the function*/
		digit_value = (int)digit_char;

		if ((digit_value >= 48) && (digit_value <= 58))
		{
			//the char passed in as an ASCII value between 0 and 9
			is_digit = true;
		}

		return is_digit;
	}

	int String_to_Int(std::string input)
	{
		/*converts a string to an integer*/
		int input_length = input.length(), counter = 0, number = 0, digit_value;
		char character;
		//reverse the string
		std::string number_string = Reverse_String(input);

		for (int i = 0; i < input_length; i++)
		{
			//cycle through the enter line
			character = number_string[i];
			//return the character's/digit's value
			digit_value = Char_to_Int(character);
			//the digit multiplied by a base of 10
			number += digit_value * pow(10, counter);
			//increment to the next base of 10
			counter++;
		}

		//the number is converted from string to int
		return number;
	}

	std::string Reverse_String(std::string input)
	{
		/*reverses the string*/
		reverse(input.begin(), input.end());

		return input;
	}

	int Char_to_Int(char character)
	{
		/*returns a character's ascii value*/
		int ASCII_value = (int)character - '0';
		//check if digit is between 0 and 9
		Is_Digit(ASCII_value);

		return ASCII_value;
	}

	void Is_Digit(int ASCII_value)
	{
		/*determines if char is not 0, 9 or any
		digit in between*/

		if ((ASCII_value < 0) || (ASCII_value > 9))
		{
			std::cout << "The character does not have an ASCII value between 0 (48) and 9 (57)";
		}
	}
}