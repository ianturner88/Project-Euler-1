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
	int flag;
	long long int HarshadPrime;
	long long int dummytestcase;
	int sum = 0;
	int a, i, p, c;
	int remainder;
	
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));
	
	// in this for loop, we make an array that identifies all numbers as either prime or not
	for(long long int p = 2; p*p <= n; p++)
	{
		for(long long int i = 2*p; i <= n; i += p)
		{
			prime[i] = false;
		}
	}
	
	// here we check each slot. If the number is prime, we begin the algorithm required by the question
	for (long long int p = 2011; p <= n; p++)
	{
		flag = 0;
		
		// we check if the number is prime
		if (prime[p] == true)
		{
			// if the number is prime, we hack off the right most digit
			testcase = p / 10;
			flag = 1;
		}
		
		// We need to check if the testcase divided by the sum of its digits is prime 
		if (flag == 1)
		{
			// we set the sum of the digits to zero
			digitsum = 0;
			
			// we tabulate the sum of the digits
			while (testcase > 0)
			{
				digitsum += testcase % 10;
				testcase = testcase / 10;
			}
			
			// if the sum of digits evenly divides into the testcase, we set 'a' equal to the resulting number
			if (testcase % digitsum == 0)
			{
				a = testcase / digitsum;
			}
			
			flag = 0;
			
			// if a is prime, the chase is on!
			if (prime[a] == 1)
			{
				flag = 1;
			}
			
			// we need to see if initial integer p is a Harshad number all the way through. 
			while (flag == 1)
			{
				dummytestcase = testcase;
				digitsum = 0;
				
				while (dummytestcase > 0)
				{
					remainder = dummytestcase % 10;
					digitsum += remainder; 
				}
				
				if (dummytestcase % digitsum == 0)
				{
					flag = 1;
					
					c = dummytestcase / digitsum;
				}
				
				else
				{
					flag = 0;
				}
				
				testcase = testcase / 10;
				
				if (c == 1)
				{
					flag = 0;
				}
			}
		}
	}
}
