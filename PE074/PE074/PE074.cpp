#include <iostream>
#include <vector>

#include "ProjectEulerLibrary.h"
#include "PE074.h"

enum PE074
{
	UPPERLIMIT = 1000000
};

int main(void)
{
	std::vector<int> digit_factorial_chains;
	int digit_factorial_upper_limit = 10, numbers_factorial_sum[100000] = { 0 }, number = 145,
		numbers_digits_factorial_sum;
	bool state_machine[100000] = { false };

	//calculate the factorials of 1 to 9
	Euler::Digit_Factorial_Chains(digit_factorial_upper_limit, digit_factorial_chains);

	while (number < UPPERLIMIT)
	{
		//find the sum of every number's digits' factorials
		numbers_digits_factorial_sum = Numbers_Digit_Factorial_Sum(digit_factorial_chains, number);
		//memoization
		numbers_factorial_sum[number] = numbers_digits_factorial_sum;
	}

	getchar();
}

int Numbers_Digit_Factorial_Sum(std::vector<int> digit_factorial_chains, int number)
{
	/*find the sum of the factorial of the numbers digits*/
	
	int digit, digit_factorial_sum = 0, number;

	while (number > 0)
	{
		//identify nth digit of number
		digit = number % 10;
		//shrink number
		number /= 10;
		//sum of the digit's factorial 
		digit_factorial_sum += digit_factorial_chains[digit - 1];
	}

	return digit_factorial_sum;
}