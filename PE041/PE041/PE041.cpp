#include <vector>
#include <iostream>

std::vector<int> SieveOfEratosthenes();

int main(void) {
	const long long int upperlimit = 9999999;
	bool prime[upperlimit] = { 0 };
	std::vector<int> prime_sieve;
	int prime_number;

	for (int i = 2; i * i <= upperlimit; i++)
	{
		if (prime[i] == false)
		{
			for (int multiple = i * i; multiple <= upperlimit; multiple += i)
			{
				prime[multiple] = true;
			}
		}
	}

	for (int i = 0; i <= upperlimit; i++)
	{
		if (prime[i] == false)
		{
			prime_number = i;
			prime_sieve.push_back(prime_number);
		}
	}

	for (int i = 2; i < prime_sieve.size(); i++)
	{
		std::cout << prime_sieve[i] << std::endl;
	}

	getchar();
}
