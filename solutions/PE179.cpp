#include <iostream>
#include <cmath>
using namespace std;

int main (void)
{
	int n = 0;
	int divisor;
	int dc, pdc = 0;
	float nsqrt;
	int pc = 0;
	
	while (n < 5)
	{
		n++;
		
		nsqrt = pow(n, 0.5);
		
		divisor = 2;
		
		dc = 2;
		
		// checks the number of divisors of n
		while (divisor < nsqrt )
		{
			
			if (n % divisor == 0)
			{
				dc += 2;
			}
			
			divisor++;
		}
		
		//for numbers like 9, this code double counts the case of 3, so 1 is subtracted. 
		if (divisor == nsqrt)
		{
			dc--;
		}
		
		// checks if n & n + 1 have the same number of divisors
		if (dc == pdc)
		{
			pc++;
			cout << n << endl;
		}
		
		// stores the previous number's number of divisors!
		pdc = dc;
	}
	
	cout << pc;
}
