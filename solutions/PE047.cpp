#include <bits/stdc++.h>
using namespace std;

int main (void)
{
	int n = 1000000;
	bool prime [n];
	memset(prime, true, sizeof(prime));

	for (int p = 0; p <= n; p++)
	{
		for (i = p; i < n; i += p)
		{
			prime[i] == false;
		}
	}
	
	int count = 0;
	int a = 0;
	
	for (p = 2; count < 2; p++)
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
	
	cout << count; 
}
