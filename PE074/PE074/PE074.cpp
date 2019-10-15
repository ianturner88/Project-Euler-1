#include <iostream>
#include <vector>

/*determine every starting number chain length*/
void Factorial_Values_of_Numbers_less_than_Ten(std::vector <int>& digit_factorial_chains, int upperlimit);
/*sum the starting number into its digits' factorials*/
int Numbers_Digits_Factorial_Sum(int starting_number, std::vector <int> digit_factorial_chains);
/*determine the starting number's resulting chain length*/
void Chain_Length(std::vector <int> digit_factorial_chains, bool starting_numbers_chain_lengths_known[],
	int starting_number);

enum
{
	UPPERLIMIT = 1000000
};

int main(void)
{
	int upperlimit = 10, starting_number = 567, starting_number_sum = 0, digit, chain_length_counter;
	std::vector<int> digit_factorial_chains;
	std::vector<std::vector<int>> chain_results;
	std::vector<int> temp;
	bool starting_numbers_chain_lengths_known[100000] = { false };
	int starting_numbers_chain_lengths[100000] = {0};
	
	Factorial_Values_of_Numbers_less_than_Ten(digit_factorial_chains, upperlimit);

	while (starting_number < UPPERLIMIT)
	{
		//driving algorithm
		//increment to the next number
		starting_number++;

		Chain_Length(digit_factorial_chains, starting_numbers_chain_lengths_known, starting_number);

		//identify the next starting number
		starting_number++;
	}

	getchar();
}

void Chain_Length(std::vector <int> digit_factorial_chains, bool starting_numbers_chain_lengths_known[],
	int starting_number)
{
	/*determine every starting number chain length*/
	int factorial_sum, chain_length_counter = 0;
	std::vector<int> temp;

	//identify the factorial sum of the starting number
	factorial_sum = Numbers_Digits_Factorial_Sum(starting_number, digit_factorial_chains);

	while (starting_numbers_chain_lengths_known[factorial_sum] == false)
	{
		/*determines the chain resulting from a given starting point*/
		factorial_sum = Numbers_Digits_Factorial_Sum(factorial_sum, digit_factorial_chains);
		//chain length increased by 1
		chain_length_counter++;
		//the next cog in the chain
		temp.push_back(factorial_sum);
		//the number of 'numbers' into the chain
		temp.push_back(chain_length_counter);
	}
}

int Numbers_Digits_Factorial_Sum(int starting_number, std::vector <int> digit_factorial_chains)
{
	/*sum the starting number into its digits' factorials*/
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

void Factorial_Values_of_Numbers_less_than_Ten(std::vector <int>& digit_factorial_chains, int upperlimit)
{
	/*calculate the factorials of the numbers less than the upperlimit*/
	int digit = 0;
	//set 0! equal to 1
	digit_factorial_chains.push_back(1);

	while (digit < upperlimit)
	{
		/*determine the factorial of every digit*/
		digit++;

		//multiply the previous result with the current digit to get the next factorial
		digit_factorial_chains.push_back(digit_factorial_chains[(digit - 1)] * digit);
	}
}