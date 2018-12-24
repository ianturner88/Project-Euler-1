#include <iostream>
#include <time.h>
using namespace std;

int Upperlimit();
int multiples(int variable, int upperlimit);
int answer(int three, int five, int fifteen);
void Program_Execution_Time(clock_t total_time);

int main(void)
{
	int three = 0, five = 0, fifteen = 0;
	clock_t total_time;

	//only multiples of 3, 5, & 15 below the variable upperlimit are considered
	int upperlimit = Upperlimit();

	//start clock
	total_time = clock();

	//multiples of 3
	three = multiples(3, upperlimit);
	//multiples of 5
	five = multiples(5, upperlimit);
	//multiples of 15
	fifteen = multiples(15, upperlimit);

	cout << answer(three, five, fifteen) << endl;

	//output program's execution time
	Program_Execution_Time(total_time);

	//system pause
	getchar();
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

void Program_Execution_Time(clock_t total_time)
{
	//calculate total execution time
	total_time = clock() - total_time;
	//output program's execution time
	cout << "program's execution took: " << total_time << endl;
}