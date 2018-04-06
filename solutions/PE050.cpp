#include <bits/stdc++.h>
using namespace std;

int main (void)
{
	int n = 1000000;
	bool prime[n];
	memset(prime, true, sizeof(prime));
	
	long long int sum = 0;
	int answersum = 1;
	
	int count = 0;
	int answercount = 1;
	
	// we find all multiples of primes below n
	for(int p = 2; p*p <= n; p++)
	{
		for(int i = 2*p; i <= n; i += p)
			{
				prime[i] = false;
			}
	}
	
	// we initialize a starting point and count consecutive primes until n
	for(int c = 2; c <= n; c++)
	{
		// if the suggested starting point is prime, we start adding consecutive primes
		if (prime[c] == true)
		{
			//we initialize the sum and count to be 0 for each new starting point
			sum = 0;
			count = 0;
				
			for (int b = c; b <= n && sum < n; b++)
			{
				//if the next number to be added to the set of consecutive primes is prime, we increase the count and update the sum
				if (prime[b] == true)
				{
					sum += b;
					count++;
				}
				
				// if the sum of consecutive primes is prime, we update answers for both the count and sum - so long as the new count and sum are greater than the previous count and sum
				if (sum < n && prime[sum] == true && prime[b] == true && count > answercount)
				{
					answersum = sum;
					answercount = count;
				}
			}
		}
	}
	// the program is done!
	cout << answersum << ": " << answercount;
}
