#include <iostream>
#include <vector>

bool Is_Pandigital(int input_number);
int Numbers_Length(int input_number, bool is_pandigital[]);

int main(void)
{
	int input_number = 1;
	std::cout << Is_Pandigital(input_number) << std::endl;

	getchar();
}

bool Is_Pandigital(int input_number)
{
	/*determines if a number is pandigital*/
	bool is_number_pandigital = true;

	if (input_number > 987654321)
	{
		/*the largest pandigital number is 987654321*/
		//the function's return value is to false
		is_number_pandigital = false;
		//the function is exited
		return is_number_pandigital;
	}

	//all possible digit's the number may contain are initialized to false
	bool is_pandigital[10] = { false };
	//used to identify when digits occur more than once or ' 0 '
	int test_count = 0;

	/*determines the number's length and marks every 'sliced off' as true*/
	int input_numbers_length = Numbers_Length(input_number, is_pandigital);

	for (int i = 1; (i <= input_numbers_length) && (is_number_pandigital == true); i++)
	{	
		/*check if all digit spots below the number's length are accounted for*/
		if (is_pandigital[i] != true)
		{
			is_number_pandigital = false;
		}
		//keep track of the number of digits in the number
		test_count++;
	}

	if (test_count != input_numbers_length)
	{
		/*test to account for 0's and digits occuring more than once*/
		is_number_pandigital = false;
	}

	return is_number_pandigital;
}

int Numbers_Length(int input_number, bool is_pandigital[])
{
	/*determines a number's length*/
	int digit = 0, numbers_length = 0;

	while (input_number > 0)
	{
		//shave off the LSB digit 'shaved off'
		digit = input_number % 10;
		//truncate the variable by deleting the LSB digit
		input_number /= 10;
		//the length of the input number
		numbers_length++;
		//mark the digit has existing
		is_pandigital[digit] = true;
	}

	return numbers_length;
}