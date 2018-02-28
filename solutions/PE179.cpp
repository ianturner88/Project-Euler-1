#include <iostream>
#include <cmath>
using namespace std;

int main (void)
{
	long long int n = 0;
	long long int p1;
	long long int p2;
	long long int divisor;
	long long int dc1, dc2;
	long long int sum = 0;
	//10000000
	while (n < 10000000)
	{
		n++;
		
		p1 = n;
		
		p2 = n;
		p2++;
		
		divisor = 0;
		
		dc1 = 0;
		
		while (divisor < p1/2)
		{
			divisor++;
			
			if (p1 % divisor == 0)
			{
				dc1++;
			}
		}
		
		divisor = 0;
		
		dc2 = 0;
		
		while (divisor < p2/2) 
		{
			divisor++;
			
			if (p2 % divisor == 0)
			{
				dc2++;
			}
		}
		
		if (dc1 == dc2)
		{
			sum++;
		}
		
		if (n % 10000 == 0)
		{
			cout << "sum: " << sum << "  " << "number: " << n << endl;	
		}
		
	}
	cout << sum;
}
