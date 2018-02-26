#include <iostream>
#include <cmath>
using namespace std;

int main (void)
{
	double number = 0;
	int decreasing, increasing;
	double bouncycount = 0;
	double percentagecheck = 0;
	int a, b;
	int dummynumber;
	int count;
	int power;

	while (percentagecheck != .99)
	{
		decreasing = 1;
		increasing = 1;
		number++;
		count = 0;

		dummynumber = number;

		while (dummynumber > 0)
		{
			dummynumber = dummynumber / 10;
			count++;
		}

		dummynumber = number;
		power = 0;

		// decreasing number (66420)
		while (dummynumber > 10 && decreasing == 1)
		{
			a = dummynumber % 10;
			
			dummynumber = dummynumber / 10;
			
			b = dummynumber % 10;
			b = b % 10;
			
			decreasing = 0;

			if (a < b || b == a)
			{
				decreasing = 1;
			}
		}

		dummynumber = number;

		// increasing number (134468)
		while (dummynumber > 10 && increasing == 1 && count > 1)
		{
			a = dummynumber / pow(10, count - 1);
			a = a % 10;
			
			b = dummynumber / pow (10, count - 2);
			b = b % 10;
			
			count--;
			
			increasing = 0;
			
			if (b > a || b == a)
			{
				increasing = 1;
			}
		}

		if (increasing != 1 && decreasing != 1)
		{
			bouncycount++;
		}

		percentagecheck = bouncycount / number;
	}

	cout << number << endl;
	cout << percentagecheck << endl;
}

