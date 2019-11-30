#include <iostream>
#include <time.h>

int multipleSum(int upperLimit, int multiple);
int requestUpperLimit(void);
void PrintTest(int test);

int main(void)
{
	int upperLimit = requestUpperLimit();
	int three, five, fifteen;
	clock_t total_time = clock();

	three = multipleSum(upperLimit, 3);
	five = multipleSum(upperLimit, 5);
	fifteen = multipleSum(upperLimit, 15);

	PrintTest(30);

	total_time = clock() - total_time;

	std::cout << "Execution Time: " << total_time << std::endl;

	std::cout << three + five - fifteen;
}

void PrintTest(int test)
{
	for (int i = 0; i < test; i++)
	{
		std::cout << i << std::endl;
	}
}

int multipleSum(int upperLimit, int multiple) 
{
	/* sums all multiples of given number */
	int sum = 0;

	for (int i = 0; i < upperLimit; i+=multiple) {
		sum += i;
	}

	return sum; 
}

int requestUpperLimit(void) 
{
	int upperLimit;
	std::cout << "Bud, what is the upper limit?" << std::endl;
	std::cin >> upperLimit;
	return upperLimit;
}