#include<iostream>
using namespace std;

int main(void)
{
	int number = 0;
	int divisor = 0;
	int sum = 0;
	int upperlimit = 0;
	int test = 0;
	int answer = 0;

	while (number < 1000000)
	{
		number++;
		divisor = 1;
		sum = 0;
		upperlimit = number / 2;

		while (divisor <= upperlimit)
		{
			if (number % divisor == 0)
			{
				sum += divisor;
			}
			divisor++;
		}

		test = sum;
		divisor = 1;
		upperlimit = sum / 2;
		sum = 0;

		while (divisor <= upperlimit)
		{
			if (test % divisor == 0)
			{
				sum += divisor;
			}
			divisor++;
		}

		if (sum == number && test != number)
		{
			answer += (number + test) / 2;
		}
	}
	cout << answer;
}