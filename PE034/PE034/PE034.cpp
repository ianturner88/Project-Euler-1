#include<iostream>
using namespace std;

void Factorials(const int &n, int factorial_sum[]);
void Digit_Factorials_Sum(int &testcase, int factorial_sum[], int &sum);

int main(void)
{
	const int n = 10;
	int testcase = 2;
	int upperlimit = 2540160;
	int sum = 0;

	int factorial_sum[n];

	std::fill_n(factorial_sum, n, 1); // set all the values of the array equal to 1

	Factorials(n, factorial_sum);

	while (testcase < upperlimit)
	{
		testcase++;
		Digit_Factorials_Sum(testcase, factorial_sum, sum);
	}

	cout << sum << endl;

	system("pause");
}

void Factorials(const int &n, int factorial_sum[])
{
	/*Calculates and stores the values of the factorials
	of 1 through 9*/

	for (int i = 1; i < n; i++)
	{
		int remainder = i;

		while (remainder > 0)
		{
			factorial_sum[i] *= remainder;

			remainder--;
		}
	}
}

void Digit_Factorials_Sum(int &testcase, int factorial_sum[], int &sum)
{
	/*Check if the sum of the given number's digits'
	factorial is equal to the number itself*/

	int  number = testcase;
	int remainder;
	int remainder_digit_factorial_sum = 0;

	while (number > 0)
	{
		remainder = number % 10;
		remainder_digit_factorial_sum += factorial_sum[remainder];

		number /= 10;
	}

	if (remainder_digit_factorial_sum == testcase)
	{
		sum += testcase;
	}
}