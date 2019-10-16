#include <iostream>
#include <vector>

/*determine every starting number chain length*/
void Factorial_Values_of_Numbers_less_than_Ten(std::vector <int>& digit_factorial_chains, int upperlimit);
/*sum the starting number into its digits' factorials*/
int Numbers_Digits_Factorial_Sum(int starting_number, std::vector <int> digit_factorial_chains);
/*determine the starting number's resulting chain length*/
void Chain_Length(std::vector <int> digit_factorial_chains, int starting_number,
	std::vector<std::vector<int>> known_chain_length_results);
/*return the location of the target*/
int TwoD_Vector_BinarySearch(std::vector <std::vector <int>> example, int column_to_search, int target);

enum
{
	UPPERLIMIT = 1000000
};

int main(void)
{
	int upperlimit = 10, starting_number = 68, starting_number_sum = 0, digit, chain_length_counter;
	std::vector<int> digit_factorial_chains;
	std::vector<std::vector<int>> known_chain_length_results;
	std::vector<int> temp;
	
	Factorial_Values_of_Numbers_less_than_Ten(digit_factorial_chains, upperlimit);

	while (starting_number < UPPERLIMIT)
	{
		//driving algorithm
		//increment to the next number
		starting_number++;

		Chain_Length(digit_factorial_chains, starting_number, known_chain_length_results);

		//identify the next starting number
		starting_number++;
	}

	getchar();
}

void Chain_Length(std::vector <int> digit_factorial_chains,	int starting_number, 
	std::vector<std::vector<int>> known_chain_length_results)
{
	/*determine every starting number chain length*/
	int factorial_sum, chain_length_counter = 0;
	std::vector<int> temp;
	std::vector<std::vector<int>> current_chain_length_vector;

	//identify the factorial sum of the starting number
	factorial_sum = Numbers_Digits_Factorial_Sum(starting_number, digit_factorial_chains);

	while ((TwoD_Vector_BinarySearch(current_chain_length_vector, 0, factorial_sum) != -1) &&
		(TwoD_Vector_BinarySearch(known_chain_length_results, 0, factorial_sum)) != -1)
	{
		/*determines the chain resulting from a given starting point*/
		factorial_sum = Numbers_Digits_Factorial_Sum(factorial_sum, digit_factorial_chains);
		//chain length increased by 1
		chain_length_counter++;
		//the next cog in the chain
		temp.push_back(factorial_sum);
		//the number of 'numbers' into the chain
		temp.push_back(chain_length_counter);
		//the number is stored first in the 2D vector, then the number's chain length
		current_chain_length_vector.push_back(temp);
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

int TwoD_Vector_BinarySearch(std::vector <std::vector <int>> example, int column_to_search, int target)
{
	/*return the location of the target*/

	int upper_bound = (example.size() - 1), midpoint, lower_bound = 0;

	while (lower_bound <= upper_bound)
	{
		//the binary search algorithm

		//update midpoint
		midpoint = (lower_bound + upper_bound) / 2;

		if (example[midpoint][0] == target)
			//the target is located in the middle
			return midpoint;

		else if (example[midpoint][0] < target)
			//the target is to the right of the middle
			lower_bound = midpoint + 1;

		else
			//the target is to the left of the middle
			upper_bound = midpoint - 1;
	}

	//the element is not present in the array
	return -1;
}