#include <iostream>
#include <vector>

#include "PE074.h"
#include "ProjectEulerLibrary.h"

int main(void)
{
	std::vector <int> digit_factorial_chains;
	int upperlimit = 10;

	int upperlimit = 10;

	Euler::Digit_Factorial_Chains(digit_factorial_chains, upperlimit);

	//Digit_Factorial_Chains(digit_factorial_chains, upperlimit);

	for (int i = 0; i < upperlimit; i++)
	{
		std::cout << digit_factorial_chains[i] << std::endl;
	}

	getchar();
}