#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main (void)
{
	int n = 1000000;
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));
	
	for(long long int p = 2; p*p <= n; p++)
	{
		for(long long int i = 2*p; i <= n; i += p)
		{
			prime[i] = false;
		}
	}
	
	int flag = 1;
	int Goldbach = 7;
	int square, p, check;
	
	while (flag == 1)
	{
		Goldbach += 5557;
		check = 0;
		
		if (prime[Goldbach] == false)
		{
			while (check != Goldbach && flag != 0 && check < Goldbach)
			{
				for (square = 1; square < Goldbach && flag != 0 && check < Goldbach; square++)
				{	
					square = 2 * pow(square, 2);
				
					for (p = 2; p < Goldbach && flag != 0 && check < Goldbach; p++)
					{
						if(prime[p] == true)
						{
						check = p + square;
						}
						
						if (check == Goldbach)
						{
							flag = 1;
						}
					}
				}	
			}
		}
	}
	
	cout << p;
}
