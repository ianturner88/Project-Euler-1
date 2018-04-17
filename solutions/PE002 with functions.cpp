#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main (void)
{
	long long int n = 100;
	long long int sum = 0;
	long long int F1 = 1;
	long long int F2 = 1;
	long long int Fnext;
	long long int p;
	
	bool prime[n + 1];
	memset(prime, false, sizeof(prime));
	
	Fnext = 0;
	
	while (F1 < n)
	{
		Fnext = F1 + F2;
		F1 = F2;
		F2 = Fnext;
		
		if (Fnext % 2 == 0)
		{
			prime[Fnext] = true;
		}
	}
	
	for (p = 0; p < n; p++)
	{
		if (prime[p] == true)
		{
			sum += p;	
		}
	}
	
	cout << sum;
}
