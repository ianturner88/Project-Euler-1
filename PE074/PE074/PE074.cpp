#include <iostream>
#include <vector>

#include "ProjectEulerLibrary.h"

int main(void)
{
	std::cout << "Ian" << std::endl;

	std::vector<int> digit_factorial_chains;
	int n = 9;

	Euler::Digit_Factorial_Chains(n, digit_factorial_chains);

	for (int i = 1; i < n; i++)
	{
		int test = digit_factorial_chains[i];
		
		std::cout << digit_factorial_chains[i- 1] << std::endl;
	}

	getchar();
}