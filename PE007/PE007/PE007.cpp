#include<iostream>
using namespace std;

void Is_Prime(bool prime[], const int &upperlimit);
void Answer(bool prime[], int &i);

int main(void)
{
	/*Initialize the upperlimit; the testcase, n; the boolean array*/

	const long long int upperlimit = 200000;
	int answer = 0;
	int i = 1;

	bool prime[upperlimit];
	memset(prime, true, sizeof(prime));

	/*Identify all primes below 1 000 000*/
	Is_Prime(prime, upperlimit);
	Answer(prime, i);

	cout << i - 2 << endl;

	system("pause");
}

void Is_Prime(bool prime[], const int &upperlimit)
{
	/*Identify all primes below 1 000 000*/

	for (int p = 2; p <= upperlimit; p++)
	{
		for (int i = 2 * p; i <= upperlimit; i += p)
		{
			prime[i] = false;
		}
	}
}
//test
void Answer(bool prime[], int &i)
{
	int count = 0;

	while (count < 10001)
	{
		if (prime[i] == true)
		{
			count++;
		}

		i += 2;
	}
}