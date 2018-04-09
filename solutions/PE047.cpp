#include <bits/stdc++.h>
using namespace std;

int main (void)
{
	int n = 1000000;
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));
	
	for(long long int p = 2; p*p <= n; p++)
	{
		for(long long int i = 2*p; i <= n; i += p)
		{
			prime[i] = false;
		}
	}
	
	int count = 0;
	int limit = 3;
	int a, y, z;
	
	for (z = 3; count < limit; z++)
	{
		y = 2;
		a = z;
		
		for (y = 2; y <= z/2; y++)
		{
			if (prime[y] == true && a > 1)
			{
				count++;
				
				a = z;
				
				while (a % y == 0)
				{
					a = a / y;
				}
			}
		}
	}
	
	cout << z; 
}
