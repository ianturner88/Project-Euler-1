#include <bits/stdc++.h>
using namespace std;

void Eratosthenes(int n);

int main (void)
{
	long long int n = 1000000;
	
	cout << "The primes below " << n << " are: ";
	
	Eratosthenes(n);
}

void Eratosthenes(int n)
{
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));
	
	for(long long int p = 2; p*p <= n; p++)
	{
		for(long long int i = 2*p; i <= n; i += p)
		{
			prime[i] = false;
		}
	}
	
	for(long long int p = 2; p <= n; p++)
	{
		if (prime[p] == true)
		{
			cout << p << endl;
		}
	}
}
