#include<iostream>
using namespace std;

bool Is_Prime(bool prime[], int upperlimit);
int Division(bool prime[], int big_number, int testcase);

int main(void)
{
	const long long int big_number = 600851475143;
	const long long int upperlimit = big_number / 2;
	
	bool prime[upperlimit];
	memset(prime, true, sizeof(prime));

	Is_Prime(prime, upperlimit);
	Division(prime, big_number, upperlimit);

	cout << Division(prime, big_number, upperlimit);
}

bool Is_Prime(bool prime[], int upperlimit)
{
	for (int multiple = 1; multiple <= upperlimit; multiple++)
	{
		for (multiple; multiple <= upperlimit; multiple += multiple)
		{
			prime[multiple] = false;
		}
	}

	return prime;
}

int Division(bool prime[], int big_number, int testcase)
{
	int flag = 0;
	testcase = testcase + 1;
	
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

	return testcase;
}