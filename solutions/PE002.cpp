#include <bits/stdc++.h>
#include <math.h>
using namespace std;

void Fibonacci(bool prime[], int);
void Answer(bool prime[], int n);

int main (void)
{
	long long int n = 1000000;
	
	bool prime[n + 1];
	memset(prime, false, sizeof(prime));
	
	Fibonacci(prime, n);
	Answer(prime, n);
}

void Fibonacci(bool prime[], int n)
{
	long long int Fnext, F1 = 1, F2 = 1;
	int flag = 0;
	
	while (flag == 0)
	{
		if (Fnext % 2 == 0)
		{
			prime[Fnext] = true;
		}
		
		Fnext = F1 + F2;
		F1 = F2;
		F2 = Fnext;
		
		if (Fnext > n || F1 > n || F2 > n)
		{
			flag = 1;
		}
	}
}

void Answer(bool prime[], int n)
{
	long long int sum = 0;
	
	for (long long int p = 0; p < n; p++)
	{
		if (prime[p] == true)
		{
			sum += p;	
		}
	}
	
	cout << sum;
}
