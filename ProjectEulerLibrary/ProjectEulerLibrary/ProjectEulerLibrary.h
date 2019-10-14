#pragma once
#include <time.h>
#include <vector>

namespace Euler
{
	//stores the factorials of all digits below a given upperlimit
	void Digit_Factorial_Chains(std::vector <int>& digit_factorial_chains, int upperlimit);
	//checks if a character is a digit or not
	void Is_Digit(int ASCII_value);

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
}