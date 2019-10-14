#pragma once
#include <time.h>
#include <vector>

namespace Euler
{
	void Digit_Factorial_Chains(std::vector <int>& digit_factorial_chains, int upperlimit);
	void Is_Digit(int ASCII_value);

	int Char_to_Int(char character);
	int String_to_Int(std::string input);
	int Numbers_Length(int input_number);
	
	std::string Reverse_String(std::string input);
	
	bool Is_Digit(char digit_char);

	void Time(clock_t time_total);
}