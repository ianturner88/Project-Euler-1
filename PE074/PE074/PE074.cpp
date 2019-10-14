#include <iostream>
#include <vector>

void Digit_Factorial_Chains(std::vector <int>& digit_factorial_chains, int upperlimit);
int Digits_Factorial_Sum(int starting_number, std::vector <int> digit_factorial_chains);

enum
{
	UPPERLIMIT = 1000000
};

int main(void)
{
	std::vector <int> digit_factorial_chains;
	int upperlimit = 10, starting_number = 0, starting_number_sum = 0, digit, starting_numbers_chain_lengths[1000000],
		factorial_sum, chain_length_counter, std::vector<std::vector<int>> chain_results;
	bool starting_numbers_chain_lengths_known[1000000];
	
	Digit_Factorial_Chains(digit_factorial_chains, upperlimit);

	while (starting_number < UPPERLIMIT)
	{
		//driving algorithm

		//increment to the next number
		starting_number++;
		//reset counter
		chain_length_counter = 0;
		//identify the factorial sum of the starting number
		factorial_sum = Digits_Factorial_Sum(starting_number, digit_factorial_chains);

		while (starting_numbers_chain_lengths_known[factorial_sum] == false)
		{
			/*determines the chain resulting from a given starting point*/
			factorial_sum = Digits_Factorial_Sum(factorial_sum, digit_factorial_chains);
			//chain length increased by 1
			chain_length_counter++;



		}


		Digits_Factorial_Sum(934, digit_factorial_chains);

		//identify the next starting number
		starting_number++;
	}

	getchar();
}

int Digits_Factorial_Sum(int starting_number, std::vector <int> digit_factorial_chains)
{
	//sum the starting number into its digits' factorials
	int digit, factorial_sum = 0;
	
	while (starting_number > 0)
	{
		//slice the starting number into its individual digits 
		digit = starting_number % 10;
		//shrink the starting number
		starting_number = starting_number / 10;
		//the sum of the starting number's digits' factorials
		factorial_sum += digit_factorial_chains[digit];
	}

	//the factorial sum of the number's digits
	return factorial_sum;
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