#include <iostream>
#include <vector>

void Is_Prime(std::vector<bool> prime, const long long int upperlimit);
void Answer(std::vector<bool> prime, long long int &i);

int main(void)
{
	/*Initialize the upperlimit; the testcase, n; the boolean array*/

	const long long int upperlimit = 200000;
	long long int answer = 0;
	long long int i = 1;

	//	vector<string> fingerprint;
	std::vector<bool> prime = {false};
	
	/*Identify all primes below 1 000 000*/
	Is_Prime(prime, upperlimit);
	Answer(prime, i);

	std::cout << i - 2 << std::endl;

	getchar();
}

void Is_Prime(std::vector<bool> prime, const long long int upperlimit)
{
	/*Identify all primes below 1 000 000*/

	for (long long int p = 2; p < upperlimit; p++)
	{
		for (long long int i = 2 * p; i < upperlimit; i += p)
		{
			prime[i] = false;
		}
	}
}
//test
void Answer(std::vector<bool> prime, long long int &i)
{
	long long int count = 0;

	while (count < 10001)
	{
		if (prime[i] == true)
		{
			count++;
		}

		i += 2;
	}
}