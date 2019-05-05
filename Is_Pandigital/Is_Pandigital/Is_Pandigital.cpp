#include <iostream>
bool Is_Pandigital(int input_number);
int Numbers_Length(int input_number);

int main(void)
{
	int input_number = 54321;

	std::cout << Is_Pandigital(input_number) << std::endl;

	getchar();
}

int Numbers_Length(int input_number)
{
	/*determines a number's length*/
	int digit, numbers_length = 0;

	while (input_number > 0)
	{
		//shave off the LSB digit 'shaved off'
		digit = input_number % 10;
		//truncate the variable by deleting the LSB digit
		input_number /= 10;
		//the length of the input number
		numbers_length++;
	}

	return numbers_length;
}

bool Is_Pandigital(int input_number)
{
	/*determines if a number is pandigital*/
	int numbers_length = Numbers_Length(input_number);
	bool pandigital_check[9] = { false }, is_pandigital = true;
	int digit;

	if (numbers_length > 9)
	{
		/*a pandigital number may only have the digits 1 through 9 ->
		a pandigital number's length is capped at 9 digits*/
		is_pandigital = false;
		//the number is not pandigital
		return is_pandigital;
	}

	while (input_number > 0)
	{
		/*identify the numbers that exist in the number*/
		//identify the LSB digit
		digit = input_number % 10;
		//truncate the number by removing the LSB digit
		input_number /= 10;
		if (pandigital_check[digit] == true)
		{
			//the digit occurs twice in the number --> number != pandigital
			is_pandigital = false;
		}

		//'slice' off the LSB digit and mark has existing in the numer
		pandigital_check[digit] = true;
	}

	for (int i = 0; i < numbers_length; i++)
	{
		/*check if all digits below the number's length exist in the number*/
		if (pandigital_check[i] == false)
		{
			//a digit below the number's total length did not occur
			is_pandigital = false;
		}
	}

	return is_pandigital;
}