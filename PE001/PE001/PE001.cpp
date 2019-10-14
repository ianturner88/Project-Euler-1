#include <iostream>
#include <time.h>
using namespace std;

int Upperlimit();
int multiples(int variable, int upperlimit);
int answer(int three, int five, int fifteen);

int main(void)
{
	int three = 0, five = 0, fifteen = 0;

	//only multiples of 3, 5, & 15 below the variable upperlimit are considered
	int upperlimit = Upperlimit();

	//multiples of 3
	three = multiples(3, upperlimit);
	//multiples of 5
	five = multiples(5, upperlimit);
	//multiples of 15
	fifteen = multiples(15, upperlimit);

	cout << answer(three, five, fifteen) << endl;

	//system pause
	getchar();
}

int Upperlimit()
{
	/* Asks the user for the upperlimit */

	int upperlimit;

	cout << "Enter the upperlimit:" << endl;
	cin >> upperlimit;

	return upperlimit;
}

int multiples(int variable, int upperlimit)
{
	/* Calculates the sum of the multiples
	of 3, 5, & 15 below the given upperlimit */

	int sum = 0;

	for (int multiple = 0; multiple < upperlimit; multiple += variable)
	{
		sum += multiple;
	}

	return sum;
}

int answer(int three, int five, int fifteen)
{
	/* Sets the value of the function
	to the answer */

	return three + five - fifteen;
}