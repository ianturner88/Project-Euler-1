#include <iostream>
#include <vector>
#include <time.h>

#include "ProjectEulerLibrary.h"

namespace Euler
{
	std::vector<int> Single_Digit_Factorial_Values(int upperlimit)
	{
		/*calculate the factorials of the numbers less than the upperlimit*/
		int digit = 0;
		//set 0! equal to 1
		std::vector<int> digit_factorials;
		digit_factorials.push_back(1);

		while (digit < upperlimit)
		{
			/*determine the factorial of every digit*/
			digit++;

			//multiply the previous result with the current digit to get the next factorial
			digit_factorials.push_back(digit_factorials[(digit - 1)] * digit);
		}

		return digit_factorials;
	}

	void Digit_Factorial_Chains(std::vector <int>& digit_factorial_chains, int upperlimit)
	{
		/*calculate the factorials of the numbers less than the upperlimit*/
		int digit = 0;
		//set 0! equal to 1
		digit_factorial_chains.push_back(1);

		while (digit <= upperlimit)
		{
			/*determine the factorial of every digit*/
			digit++;

			//multiply the previous result with the current digit to get the next factorial
			digit_factorial_chains.push_back(digit_factorial_chains[(digit - 1)] * digit);
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

	void Time(clock_t time_total)
	{
		//outputs execution time to point where called
		time_total = (clock() - time_total) / (double)CLOCKS_PER_SEC;
		std::cout << "time stamp (seconds): " << time_total << std::endl;
	}

	int Numbers_Length(int input_number)
	{
		/*determines a number's length*/
		int digit, numbers_length = 0;

		while (input_number > 0)
		{
			//shave off the LSB digit 'shaved off'
			digit = input_number % 10;
			//truncate the variable by deleting the LSB digit
			input_number /= 10;
			//the length of the input number
			numbers_length++;
		}

		return numbers_length;
	}
}