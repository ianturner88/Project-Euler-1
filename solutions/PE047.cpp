#include <bits/stdc++.h>
#include <math.h>
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
	int limit = 2;
	int a, b = 0, w, y, z;
	int homestretch = 0;
	
	for (z = 0; homestretch < limit; z++)
	{
		y = 2;
		a = z;
		count = 0;
		w = z / 2;
		b = 0;
		
		for (y = 2; y <= w && a != 1; y++)
		{
			if (prime[y] == true && a % y == 0 && a > 1)
			{
				count++;
				
				while (a % y == 0)
				{
					a = a / y;
				}
				
				if ((count == limit && homestretch == 0) || (homestretch > 0 && count == limit && b == (z - 1)))
				{
					homestretch++;
					b = z;
				}
				
				if (homestretch == 1 && b != (z - 1))
				{
					homestretch = 0;
				}
			}
		}
	}
	
	cout << z << endl; 
}
