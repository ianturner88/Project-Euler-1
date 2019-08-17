#include <iostream>
#include <vector>

int Digit_Sum(int n_digit_number);
void Clean_Vector_Contents(std::vector<int> sums);

int main(void)
{
	int two_digit_number = 0, tens, counter = 0, sum;
	std::vector<int> sums;

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

			//store the digit sum results in a vector
			sums.push_back(sum);

			//identify the index spot
			counter++;
		}
	}

	Clean_Vector_Contents(sums);

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