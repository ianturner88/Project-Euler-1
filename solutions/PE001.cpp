#include <iostream>
using namespace std;

int Upperlimit();
int multiples(int variable, int upperlimit);
int answer(int three, int five, int fifteen);

int main(void)
{
	int three = 0;
	int five = 0;
	int fifteen = 0;

	int upperlimit = Upperlimit();

	three = multiples(3, upperlimit);
	five = multiples(5, upperlimit);
	fifteen = multiples(15, upperlimit);

	cout << answer(three, five, fifteen) << endl;

	system("pause");
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