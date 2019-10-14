#include <iostream>
#include <vector>

#include "PE074.h"

int main(void)
{
	std::vector <int>  digit_factorial_chains;

	int upperlimit = 10;

	Digit_Factorial_Chains(digit_factorial_chains, upperlimit);

	for (int i = 0; i < upperlimit; i++)
	{
		std::cout << digit_factorial_chains[i] << std::endl;
	}

	getchar();
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