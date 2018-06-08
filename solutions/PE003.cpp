#include<iostream>
using namespace std;

void Is_Prime(bool prime[], long long int &testcase);
void Division(bool prime[], long long  int &big_number, long long int &testcase);

int main(void)
{
	long long int big_number = 600851475143;
	long long int testcase = big_number / 2;
	
	bool prime[300425737571];
	memset(prime, true, sizeof(prime));

	Is_Prime(prime, testcase);
	Division(prime, big_number, testcase);

	cout << testcase << endl;

	system("pause");
}

void Is_Prime(bool prime[], long long int &testcase)
{
	long long int p, i;
	
	for (p = 2; p <= testcase; p++)
	{
		for (i = 2 * p; i <= testcase; i += p)
		{
			prime[i] = false;
		}
	}
}

void Division(bool prime[], long long int &big_number, long long int &testcase)
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
}