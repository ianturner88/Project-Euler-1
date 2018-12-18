#include <iostream>
#include <math.h>

using namespace std;

int main(void)
{
	int primecount = 0, sum = 0;
	int big = 7, little, prime, sqrtbig, primeflag;
	int sqrtprimeleft, flagprimeleft, sizecount, doggedleft;
	int sqrtright, sqrtprimeright, flagprimeright, subtraction, doggedright;

	while (primecount < 11)
	{
		big++;
		sqrtbig = sqrt(big);
		little = 1;
		primeflag = 1;
		prime = 0;
		flagprimeleft = 0;
		flagprimeright = 0;
		doggedleft = 23;

		while (little < sqrtbig)
		{
			little++;

			if (big % little == 0)
			{
				primeflag = 0;
			}
		}

		if (primeflag == 1)
		{
			prime = big;
		}

		little = 1;

		while (primeflag == 1 && prime > 1 && doggedleft != 0)
		{
			prime = prime / 10;
			sqrtprimeright = sqrt(prime);
			little = 1;

			if (prime == 2 || prime == 3 || prime == 5 || prime == 7)
			{
				flagprimeright = 1;
			}

			if (doggedleft == 0)
			{
				flagprimeright = 0;
			}

			while (little < sqrtprimeright && sqrtprimeright != 1)
			{
				little++;

				if (prime % little == 0)
				{
					flagprimeright = 0;
					doggedleft = 0;
				}
			}
		}

		if (sqrtprimeright == 1)
		{
			flagprimeright = 0;
		}

		if (flagprimeright == 1)
		{
			prime = big;
		}

		sizecount = 0;

		while (flagprimeright == 1 && prime > 0)
		{
			prime = prime / 10;
			sizecount++;
		}

		little = 1;
		flagprimeleft = 1;
		prime = big;
		doggedright = 37;

		while (flagprimeright == 1 && prime > 1 && doggedright != 0)
		{
			sizecount--;
			subtraction = prime / pow(10, sizecount);
			prime = prime - subtraction * pow(10, sizecount);
			sqrtprimeleft = sqrt(prime);

			if (prime == 1)
			{
				flagprimeleft = 0;
			}

			little = 1;

			while (little < sqrtprimeleft)
			{
				little++;

				if (prime % little == 0)
				{
					flagprimeleft = 0;
					doggedright = 0;
				}
			}
		}

		if (flagprimeright == 1 && flagprimeleft == 1 && primeflag == 1)
		{
			primecount++;
			sum += big;
		}
	}

	cout << sum;
}