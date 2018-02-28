#include <iostream>
#include <cmath>
using namespace std;

int main (void)
{
	int n = 8;
	int divisor;
	int dc, previousdc = 0;
	int nsqrt;
	int pc = 0;
	
	while (n < pow(10, 7))
	{
		n++;
		
		nsqrt = pow(n, 0.5);
		
		divisor = 1;
		
		dc = 2;
		
		// checks the number of divisors of n
		while (divisor < nsqrt )
		{
			divisor++;
			
			if (n % divisor == 0)
			{
				dc += 2;
			}
		}
		
		//for numbers like 9, this code double counts the case of 3, so 1 is subtracted. 
		if (divisor == nsqrt)
		{
			dc--;
		}
		
		// checks if n & n + 1 have the same number of divisors
		if (dc == previousdc)
		{
			pc++;
		}
		
		// stores the previous number's number of divisors!
		previousdc = dc;
	}
	
	cout << pc;
}
