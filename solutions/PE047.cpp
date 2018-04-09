#include <bits/stdc++.h>
using namespace std;

int main (void)
{
	int n = 1000000;
	bool prime [n];
	memset(prime, true, sizeof(prime));
	int i = 2;

	for (long long int p = 2; p * p <= n; p++)
	{
		for (long long int i = 2 * p; i <= n; i += p)
		{
			prime[i] == false;
		}
	}
	
	int count = 0;
	int a = 0;
	
	for (int p = 2; count < 2 && p < n; p++)
	{
		if (prime[p] == true && a > 1 && a % p == 0)
		{
			while (a % p == 0)
			{
				a = a / p;
			}
			
			count++;
		}
	}
	
	cout << a; 
}
