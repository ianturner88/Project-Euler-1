#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main(void)
{
	int n = 1000000;
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));

	for (long long int p = 2; p*p <= n; p++)
	{
		for (long long int i = 2 * p; i <= n; i += p)
		{
			prime[i] = false;
		}
	}

	int flag = 1;
	int square, squaredummy, p, check, Goldbach = 7;


	for (Goldbach; flag == 1; Goldbach += 2)
	{
		if (prime[Goldbach] == false)
		{
			flag = 0;

			for (square = 1; square < Goldbach && flag != 1; square++)
			{
				squaredummy = 2 * pow(square, 2);

				for (p = 2; p < Goldbach && flag != 1; p++)
				{

					if (prime[p] == true)
					{
						check = p + squaredummy;

						if (check == Goldbach)
						{
							flag = 1;
						}
					}
				}
			}
		}
	}

	cout << Goldbach - 2;
}