#include<iostream>
#include<cstring>
using namespace std;

void Eratosthenes(const int &upperlimit, bool prime[]);
void Answer(long long int &sum, bool prime[], const int &upperlimit);

int main()
{
	const int upperlimit = 2000001;
	long long int sum = 2;

	bool prime[upperlimit];
	memset(prime, true, sizeof(prime));

	Eratosthenes(upperlimit, prime);
	Answer(sum, prime, upperlimit);

	cout << "Sum is " << sum << endl;

	return 0;
}

void Eratosthenes(const int &upperlimit, bool prime[])
{
	/*Identify all prime numbers*/

	for (long long int p = 2; p <= upperlimit; p++)
	{
		for (long long int i = 2 * p; i <= upperlimit; i += p)
		{
			prime[i] = false;
		}
	}
}

void Answer(long long int &sum, bool prime[], const int &upperlimit)
{
	/*Add all prime numbers to 'sum'*/

	int n = 3;

	while (n < upperlimit)
	{
		if (prime[n] == true)
		{
			sum += n;
		}

		n += 2;
	}
}