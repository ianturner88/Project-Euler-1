#include <iostream>
#include <vector>
#include <algorithm>

void Factorial_Values_of_Numbers_less_than_Ten(std::vector <int>& digit_factorial_chains, int upperlimit);
int Numbers_Digits_Factorial_Sum(int starting_number, std::vector <int> digit_factorial_chains);
int TwoD_Vector_BinarySearch(std::vector <std::vector <int>> example, int column_to_search, int target);
bool Sort_Column(const std::vector<int>& v1, const std::vector<int>& v2);
void Update_the_Bank_Vault(std::vector <int> temporary_storage_chain_lengths,
	std::vector <std::vector <int>>& the_bank_vault);

enum
{
	UPPERLIMIT = 1000000
};

int main(void)
{
	std::vector<int> digit_factorial_chains, temp; 
	std::vector<std::vector<int>> the_bank_vault, temporary_storage_chain_lengths;
	int starting_number = 68, digit_factorial_sum, chain_length_counter = 0;
	bool is_match = true;
	
	Factorial_Values_of_Numbers_less_than_Ten(digit_factorial_chains, 10);

	while (starting_number < UPPERLIMIT)
	{
		//identify the next starting point
		starting_number++;

		//resets
		chain_length_counter = 1;
		is_match = false;
		digit_factorial_sum = starting_number;
		temp.clear();

		//store the results of the first starting number
		temp.push_back(digit_factorial_sum);
		temp.push_back(chain_length_counter);
		temporary_storage_chain_lengths.push_back(temp);

		while (is_match == false)
		{
			//reset
			temp.clear();
			//chain length increased by 1
			chain_length_counter++;

			//identify the next digit factorial sum in the chain
			digit_factorial_sum = Numbers_Digits_Factorial_Sum(digit_factorial_sum, digit_factorial_chains);

			//check if 'digit_factorial_sum' is in the master list 
			is_match = TwoD_Vector_BinarySearch(the_bank_vault, 0, digit_factorial_sum);
			if (is_match != true)
			{
				//check if 'digit_factorial_sum' is in the temporary list 
				is_match = TwoD_Vector_BinarySearch(temporary_storage_chain_lengths, 0, digit_factorial_sum);
			}
			
			//the next cog in the chain
			temp.push_back(digit_factorial_sum);
			//the number of 'numbers' into the chain
			temp.push_back(chain_length_counter);
			//the number is stored first in the 2D vector, then the number's chain length
			temporary_storage_chain_lengths.push_back(temp);	
		}		
	}
}

void Update_the_Bank_Vault(std::vector <int> temporary_storage_chain_lengths, 
	std::vector <std::vector <int>>& the_bank_vault)
{
	/*shift the contents of the digit_factorial_chains to the_bank_vault*/
	std::vector<int> temp;

	for (int i = 0; i < temporary_storage_chain_lengths.size(); i++)
	{
		temp.push_back(temporary_storage_chain_lengths[i]);
		the_bank_vault.push_back(temp);
	}

	//sort the vector
	sort(the_bank_vault.begin(), the_bank_vault.end(), Sort_Column);
}

bool Sort_Column(const std::vector<int>& v1, const std::vector<int>& v2)
{
	return v1[0] < v2[0];
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

int TwoD_Vector_BinarySearch(std::vector <std::vector <int>> chain_lengths, int column_to_search, int target)
{
	/*return the location of the target*/

	if (chain_lengths.size() == 0)
	{
		//early exit
		return 0;
	}

	//sort the vector
	sort(chain_lengths.begin(), chain_lengths.end(), Sort_Column);

	int upper_bound = (chain_lengths.size() - 1), midpoint, lower_bound = 0;

	while (lower_bound <= upper_bound)
	{
		//the binary search algorithm

		//update midpoint
		midpoint = (lower_bound + upper_bound) / 2;

		if (chain_lengths[midpoint][0] == target)
			//the target is located in the middle
			return true;

		else if (chain_lengths[midpoint][0] < target)
			//the target is to the right of the middle
			lower_bound = midpoint + 1;

		else
			//the target is to the left of the middle
			upper_bound = midpoint - 1;
	}

	//the element is not present in the array
	return false;
}