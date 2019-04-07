#include <iostream>
#include <vector>

#include "ProjectEulerLibrary.h"

namespace Euler 
{
	void Digit_Factorial_Chains(int n, std::vector<int> &digit_factorial_chains)
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
}