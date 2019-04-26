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
}