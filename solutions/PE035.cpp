/* 
RTF:
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.
There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.
How many circular primes are there below one million?
*/

#include<iostream>
using namespace std;

void Is_Prime(bool prime[], const int &upperlimit);
void Is_Circular(bool prime[], const int &upperlimit, int &n, int &answer);

int main(void)
{
	/*Initialize the upperlimit; the testcase, n; the boolean array*/
	
	const int upperlimit = 1000000;
	int n = 1;
	int answer = 0;

	bool prime[upperlimit];
	memset(prime, true, sizeof(prime));

	/*Identify all primes below 1 000 000*/
	Is_Prime(prime, upperlimit);

	/*if n is prime, the algorithm in the function Is_Circular
	checks if the prime is also circularily prime*/
	while (n < upperlimit)
	{
		n += 2;
		
		if (prime[n] == true)
		{
			Is_Circular(prime, upperlimit, n, answer);
		}
	}

	cout << answer + 1 << endl;

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

void Is_Circular(bool prime[], const int &upperlimit, int &n, int &answer)
{
	/*Check if the initial prime is also circularily prime*/
	
	int test_number = n;
	int count = 0;
	int flag = 1;
	int remainder;
	int exponent = count;

	/*Determine the number's length*/
	while (test_number > 0)
	{
		test_number = test_number / 10;
		count++;
	}

	test_number = n;
	exponent = count - 1;
	
	if (count > 1)
	{
		count--;
	}

	/*Check if the prime is circularily prime*/
	while (count > 0 && flag == 1)
	{
		remainder = test_number % 10;
		test_number = test_number / 10;
		test_number = test_number + remainder * pow(10, exponent);

		if (prime[test_number] == false)
		{
			flag = 0;
		}

		count--;

		if (count == 0 && flag != 0)
		{
			answer++;
		}
	}
}