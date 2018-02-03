#include<iostream>
using namespace std;

int main (void)
{
	int sum = 0;
	int iterations; 
	int start;
	int width = 1001;
	int count;
	int n = 0;
	int number = 1;
	int test = 0;
	
	iterations = (width + 1) / 2;
	
	// top right diagonal
	while (n < iterations)
	{
		number = 8 * n + number; 
		n++;
		sum += number;
		test += number;
	}
	
	// bottom left diagonal
	sum += 5;
	number = 5;
	n = 0;
	test = 0;
	while (n < iterations - 2)
	{
		n++;
		number = 8 * n + number + 4;
		sum += number;
		test += number;
	}
	
	// bottom right diagonal
	number = 3;
	n = 0;
	sum += 3;
	test = 0;
	while (n < iterations - 2)
	{
		n++;
		number = 8 * n + number + 2;
		sum += number;
		test += number;
	}
	
	// top left diagonal
	number = 7;
	sum += 7;
	n = 0;
	test = 0;
	while (n < iterations - 2)
	{
		n++;
		number = 8 * n + number + 6;
		sum += number;
		test += number;
	}
	
	cout << sum;
}
