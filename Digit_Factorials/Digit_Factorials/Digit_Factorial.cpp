#include<iostream>
#include<vector>

std::vector<int> Single_Digit_Factorial_Values(int upperlimit);

int main(void)
{
	std::vector<int> proof_of_concept = Single_Digit_Factorial_Values(10);

	for (int i = 0; i < proof_of_concept.size(); i++)
	{
		std::cout << proof_of_concept[i] << std::endl;
	}

	getchar();
}

std::vector<int> Single_Digit_Factorial_Values(int upperlimit)
{
	/*calculate the factorials of the numbers less than the upperlimit*/
	int digit = 0;
	//set 0! equal to 1
	std::vector<int> digit_factorials;
	digit_factorials.push_back(1);

	while (digit < upperlimit)
	{
		/*determine the factorial of every digit*/
		digit++;

		//multiply the previous result with the current digit to get the next factorial
		digit_factorials.push_back(digit_factorials[(digit - 1)] * digit);
	}

	return digit_factorials;
}