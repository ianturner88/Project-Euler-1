//https://projecteuler.net/problem=387

#include <bits/stdc++.h>
using namespace std;

// initialize the function generating primes
void Harshad(int n);

int main (void)
{
	// we test the code for the case of Harshad numbers below 10000 where the sum of the strong, right truncatable Harshad primes is 90619
	long long int n = 10000;
	
	Harshad(n);
}

void Harshad(int n)
{
	long long int digitsum = 0;
	long long int testcase;
	long long int flag;
	long long int HarshadPrime;
	long long int dummytestcase;
	int sum = 0;
	int a;
	
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
	
	// in this for loop, we take all the known prime numbers and begin identifying strong, right truncatable Harshad primes
	for (long long int p = 2011; p <= n; p++)
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
			while(testcase > 1 && flag == 1)
			{
				dummytestcase = testcase;
				
				digitsum = 0;
				
				while (dummytestcase > 0)
				{
					digitsum += dummytestcase % 10;
					dummytestcase = dummytestcase / 10;
				}
				
				flag = 0;
				
				if (testcase % digitsum == 0)
				{
					a = testcase / digitsum;
					
					if (prime[a] == true)
					{
						flag = 1;
					}
				}
				
				testcase = testcase / 10;
			}
		}
		
		testcase = p / 10;
		
		if (testcase == 0 || digitsum == 0)
		{
			flag = 0;
		}
		
		// if the flag is up, we divide the once right truncated prime by the value of its digits
		if (flag == 1 && testcase % digitsum == 0)
		{
			HarshadPrime = testcase / digitsum;
		}
		
		else
		{
			flag = 0;
		}
		
		// here, we see if the HarshadPrime is truly a prime
		if (prime[HarshadPrime] == true && flag == 1)
		{
			sum += p;
		}
	}
	
	cout << sum;
}
