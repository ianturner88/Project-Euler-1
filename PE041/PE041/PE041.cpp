#include <vector>
#include <iostream>

std::vector<int> SieveOfEratosthenes();
std::vector<int> prime_sieve;
const long long int upperlimit = 7654321;
bool prime[upperlimit] = { 0 };
unsigned long long int prime_number;

int main(void) {

	std::vector<int> prime_numbers = SieveOfEratosthenes();

	std::cout << "Toronto";

	getchar();
}

bool is_pandigital(int input_number)
{
	/*determines if a number is pandigital*/

	return 0;
}


std::vector<int> SieveOfEratosthenes()
{
	/*returns a vector of all prime numbers less than the specified upperlimit*/
	for (int i = 2; i * i <= upperlimit; i++)
	{
		if (prime[i] == false)
		//the number is prime
		{
			for (unsigned long long int multiple = i * i; multiple <= upperlimit; multiple += i)
			{
				//mark all subsequent multiples as non-prime
				prime[multiple] = true;
			}
		}
	}

	for (unsigned long long int i = 0; i <= upperlimit; i++)
	{
		if (prime[i] == false)
		//extract all prime numbers into a new vector
		{
			prime_number = i;
			prime_sieve.push_back(prime_number);
		}
	}

	return prime_sieve;
}