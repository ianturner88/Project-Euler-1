#include <iostream>
#include <math.h>
using namespace std;

void Sequence(int &n, int &i, int &k);
void Storage(int collatz[], int &i, int &k, int &n);

int main()
{
	int n = 1, i = 0, k;
	int collatz[10] = { 0 };

	while (n < 1000000)
	{
		i++;
		n = i;
		n++;
		Sequence(n, i, k);
		Storage(collatz, i, k, n);
	}
}

void Sequence(int &n, int &i, int &k)
{
	/*Calculates sequences for the given starting number
	& breaks if the sequences starts calculating an already
	determined route.*/
	
	k = 1;

	while (n >= i && n != 1)
	{
		k++;
		
		if ((n % 2) == 0)
		{
			n = (n / 2);
		}

		else
		{
			n = 3 * n + 1;
		}
	}
}

void Storage(int collatz[], int &i, int &k, int &n)
{
	/*Every number's collatz sequence count is stored 
	in the arry collatz[]*/

	collatz[i] = collatz[n] + k;
	int test = collatz[i];
}
