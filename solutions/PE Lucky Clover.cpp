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
	
	for (int p = 6; count != 38; p++)
	{	
		z = p;
		
		if (prime[z] == true)
		{
			check = z * y - x - w;
			
			if (prime[check] == true)
			{
				count++;
				sum = check;
				cout << w << " " << x << " " << y << " " << z << endl;
			}
			
			w = x;
			x = y;
			y = z;
		}
	}
	cout << "Sum: " << check << endl;	
}
