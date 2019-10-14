#include <iostream>
#include <vector>

int Digit_Sum(int n_digit_number);
void Unique_Sums(std::vector<int> unique_sums, int digit_sum);
void Clean_Vector_Contents(std::vector<int> sums);



int main(void)
{
	int two_digit_number = 0, tens, counter = 0, sum;
	std::vector<int> unique_sums;

	std::cout << "number: " << " counter: " << " digit's sum: " << std::endl;

	for (int i = 0; i < 10; i++)
	{
		//set ten's spot
		tens = (i * 10);

		for (int i = 0; i < 10; i++)
		{
			//set the one's spot
			two_digit_number = (tens + i);
			//sum the number's digits
			sum = Digit_Sum(two_digit_number);

			std::cout << two_digit_number << "        " << counter << "         " << sum << std::endl;

			//store the unique digit sum results in a vector
			
			if (unique_sums.back() != sum)
			{
				Unique_Sums(unique_sums, sum);
			}
			
			//identify the index spot
			counter++;
		}
	}

	std::cout << "Output Vector: " << std::endl;

	for (int i = 0; i < unique_sums.size(); i++)
	{
		std::cout << unique_sums[i] << std::endl;
	}

	//system pause
	getchar();
}

void Clean_Vector_Contents(std::vector<int> sums)
{
	std::cout << std::endl << std::endl;

	std::cout << "Unique Numbers Produced: " << std::endl;

	for (int i = 1; i < sums.size(); i++)
	{
		//output one of every type in the vector
		if (sums[i - 1] != sums[i])
		{
			std::cout << sums[i - 1] << std::endl;
		}
	}
}

void Unique_Sums(std::vector<int> unique_sums, int digit_sum)
{
	bool is_match = false;

	for (int i = 0; (i < unique_sums.size()) && (is_match == false); i++)
	{
		//(condition) ? true-clause : false-clause
		(digit_sum == unique_sums[i]) ? (is_match = true) : (is_match = false);
	}

	if (is_match == false)
	{
		unique_sums.push_back(digit_sum);
	}
}

int Digit_Sum(int n_digit_number)
{
	/*return the numerical sum of the digit*/
	int sum = 0, holding_box;

	while (n_digit_number > 0)
	{
		//shave off the last digit of the number
		holding_box = n_digit_number % 10;
		//eliminate the ones spot from the number
		n_digit_number /= 10;
		//sum the digits the number
		sum += holding_box;
	}

	return sum;
}