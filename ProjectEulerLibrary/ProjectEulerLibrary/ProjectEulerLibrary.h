#pragma once
#include <time.h>
#include <vector>
#include <string>

namespace Euler
{
	//checks if a character is a digit or not
	void Is_Digit(int ASCII_value);
	//stores the factorials of all digits below a given upperlimit
	void Digit_Factorial_Chains(std::vector <int>& digit_factorial_chains, int upperlimit);

	//converts a char to an int
	int Char_to_Int(char character);
	//converts a string into an int
	int String_to_Int(std::string input);
	//determines the number of digits in a given number
	int Numbers_Length(int input_number);
	
	//reverses a string
	std::string Reverse_String(std::string input);
	
	//returns true if a character is a digit
	bool Is_Digit(char digit_char);

	//starts and stops the clock
	void Time(clock_t time_total);

	//generates the factorial values of numbers passed in
	std::vector<int> Single_Digit_Factorial_Values(int upperlimit);
}