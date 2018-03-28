//https://projecteuler.net/problem=387

#include <bits/stdc++.h>
using namespace std;

// initialize the function generating primes
void Harshad(int n);

int main (void)
{
	// we test the code for the case of Harshad numbers below 10000 where the sum of the strong, right truncatable Harshad primes is 90619
	long long int n = 200;
	
	Harshad(n);
}

void Harshad(int n)
{
	long long int digitsum = 0;
	long long int testcase;
	long long int flag;
	long long int remainder;
	long long int HarshadPrime;
	
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));
	
	// in this for loop, we identify all the prime numbers
	for(long long int p = 2; p*p <= n; p++)
	{
		for(long long int i = 2*p; i <= n; i += p)
		{
			prime[i] = false;
		}
	}
	
	int o = 7;
	// in this for loop, we take all the known prime numbers and begin identifying strong, right truncatable Harshad primes
	for (long long int p = 101; p <= n; p++)
	{
		flag = 0;
		
		//if the integer is prime, we truncate the rightmost digit & set the flag to 1
		if (prime[p] == true)
		{
			testcase = p / 10;
			flag = 1;
		}
		
		// if the flag is up, we sum up the digits
		if (flag == 1)
		{
			digitsum = 0;
			
			while(testcase > 0)
			{
				remainder = testcase % 10;
				testcase = testcase / 10;
				digitsum += remainder;
			}
		}
		
		testcase = p / 10;
		
		// if the flag is up, we divide the once right truncated prime by the value of its digits
		if (flag == 1)
		{
			HarshadPrime = testcase / digitsum;
		}
		
		// here, we see if the HarshadPrime is truly a prime
		if (prime[HarshadPrime] == true && flag == 1)
		{
			digitsum += HarshadPrime;
		}
	}
	
	cout << digitsum;
}
