#include <bits/stdc++.h>
using namespace std;

int main (void)
{
	int n = 1000;
	int a = 0;
	
	int prime[n];
	memset(prime, 1, sizeof(prime));
	
	int sum = 0;
	int count = 0;
	
	int possiblesum = 0;
	
	int possiblecount = 0;
	
	for(int p = 2; p*p <= n; p++)
		for(int i = 2*p; i <= n; i += p)
				prime[i] = 0;
			
	
	for(int c = 2; c <= n; c++)
		if (prime[c])
		{
			sum = 0;
			count = 0;
				
			for (int b = c; b <= n; b++)
			{
			 
				if (prime[b])
				{
					sum += b;
					count++;
				}
					
				if (prime[b] && sum < n && count > possiblecount)
				{
					possiblesum = sum;
					possiblecount = count;
				}
			}
		}
	
	
	cout << possiblesum << ": " << possiblecount;
}
