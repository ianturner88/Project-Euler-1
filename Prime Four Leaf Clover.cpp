/* 
Consider the first three prime numbers: 2, 3, and 5. If we mutliply
3 with 5, we get 15, which is not prime. Yet, if we subtract 2 from 15, 
we get 13, which is prime.

This case is the only one where when one multiplies two primes together
and subtracts a third results in a prime. This is because, when two odd-
numbered primes are multiplied together, the result is odd, and by 
subtracting an third odd-numbered prime, the result will be even.

Now, let's consider the 4 consecutive primes 5, 7, 11, and 13.

If we mutliply 11 and 13 together, we get 143. If now we subtract
5 and 7 from 143, we get 131 - which is prime.

Let us call 5, 7, 11, and 13 a prime four-leaf clover.

How many prime four-leaf clover are there under 1 000?

Note: Some sets of four may contain some but not all of the 
same elements as other sets. 

*/

#include <bits/stdc++.h>
using namespace std;

int main (void)
{
	long long int n = 1000000;
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));
	
	for(long long int p = 2; p*p <= n; p++)
	{
		for(long long int i = 2*p; i <= n; i += p)
		{
			prime[i] = false;
		}
	}
	
	int w = 2, x = 3, y = 5, z;
	int flag = 0;
	int check;
	int count = 0;
	int sum = 0;
	
	for (int p = 6; p < 1000; p++)
	{	
		z = p;
		
		if (prime[z] == true)
		{
			check = z * y - x - w;
			
			if (prime[check] == true && check < n)
			{
				count++;
				sum = check;
				cout << count << ": " << w << " " << x << " " << y << " " << z << endl;
			}
			
			w = x;
			x = y;
			y = z;
		}
	}
	cout << "Count: " << count << endl;	
}
