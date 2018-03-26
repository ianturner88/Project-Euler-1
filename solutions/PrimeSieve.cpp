#include <bits/stdc++.h>
using namespace std;

//the name of the function
void EratosthenesSieve(int n)
{
	//we create a boolean array
	bool prime[n + 1];
	
	//we initialize the values of the array: which array, array's value, which element's of the array
	//all values of the array are initally deemed prime
	memset(prime, true, sizeof(prime));
	
	//we set the loop to identify multiples of a given prime
	for (int p = 2; p*p <= n; p++)
	{
		if(prime[p] == true)
		{
			//here the multiples of p are set to false
			for (int i = 2*p; i <= n; i +=p)
			{
				prime[i] = false;
			}
		}
	}
	
	//keep track of which prime has what count value
	int count = 0;
	
	//we set p = 2, so that we skip over the values of 0, 1 which are set to true
	for (int p = 2; p <= n; p++)
	{
		if(prime[p] == true)
		{
			count++;
			cout << "Prime # " << count << " is: " << p << endl;
		}
	}
	
}

int main (void)
{
	int n = 1000;
	
	cout << "The primes under " << n << " are: " << endl;
	
	EratosthenesSieve(n);
}
