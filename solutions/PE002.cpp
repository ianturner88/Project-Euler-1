#include <bits/stdc++.h>
#include <math.h>
using namespace std;

void Fibonacci(bool prime[], int);
void Answer(bool prime[], int n);

int main (void)
{
	long long int n = 100;
	
	bool prime[n + 1];
	memset(prime, false, sizeof(prime));
	
	Fibonacci(prime, n);
	Answer(prime, n);
}

void Fibonacci(bool prime[], int n)
{
	int Fnext, F1 = 1, F2 = 1;
	
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
}

void Answer(bool prime[], int n)
{
	int sum = 0;
	
	for (int p = 0; p < n; p++)
	{
		if (prime[p] == true)
		{
			sum += p;	
		}
	}
	
	cout << sum;
}
