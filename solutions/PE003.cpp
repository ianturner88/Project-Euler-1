#include<iostream>
using namespace std;

void Is_Prime(bool prime[], int &testcase, const int &parray);
void Division(bool prime[], long long  int &big_number, const int &parray, int &testcase);

int main(void)
{
	long long int big_number = 600851475143;
	const int parray = 300000;
	int testcase;

	bool prime[parray];
	memset(prime, true, sizeof(prime));

	Is_Prime(prime, testcase, parray);
	Division(prime, big_number, parray, testcase);

	cout << testcase << endl;

	system("pause");
}

void Is_Prime(bool prime[], int &testcase, const int &parray)
{
	/*A seive that identifies primes*/
	
	long long int p, i;

	for (p = 2; p <= parray; p++)
	{
		for (i = 2 * p; i <= parray; i += p)
		{
			prime[i] = false;
		}
	}
}

void Division(bool prime[], long long  int &big_number, const int &parray, int &testcase)
{
	/*Finds which prime divides into the given number*/
	
	int flag = 0;
	testcase = parray;

	while (flag == 0)
	{
		testcase--;

		if (prime[testcase] == true)
		{
			if (big_number % testcase == 0)
			{
				flag = 1;
			}
		}
	}
}
