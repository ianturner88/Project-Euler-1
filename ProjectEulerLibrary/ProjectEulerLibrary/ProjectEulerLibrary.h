#pragma once
#include <time.h>

namespace Euler
{
	void Digit_Factorial_Chains(int n, std::vector<int>& digit_factorial_chains);
	void Is_Digit(int ASCII_value);

	int Char_to_Int(char character);
	int String_to_Int(std::string input);
	int Numbers_Length(int input_number);
	
	std::string Reverse_String(std::string input);
	
	bool Is_Digit(char digit_char);

	void Time(clock_t time_total);
}