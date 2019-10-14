#include <iostream>
#include <time.h>
#include <vector>

#include "ProjectEulerLibrary.h"

void Is_Prime(bool prime[], const int array_size);
int User_Input_Prime_Number();

int main(void)
{
	std::vector<bool> is_prime;
	
	getchar();
}

void Is_Prime(std::vector<bool>& is_prime, int& time)
{
	/*Produces a list of prime numbers*/

	//request user's desired upperlimit for prime number identification
	User_Input_Prime_Number();
	long long int prime_upperlimit = User_Input_Prime_Number();


}

int User_Input_Prime_Number()
{
	//ask user for the upperlimit for primes to be found

	long long int user_input;

	std::cout << "Up to what number do you want prime numbers to be found?";
	//the user's desired upperlimit
	std::cin >> user_input;

	return user_input;
}


void Is_Prime(bool prime[], const int array_size)
{
	/*A seive that identifies primes*/

	//parameters
	long long int p, i;

	for (p = 2; p <= array_size; p++)
	{
		for (i = 2 * p; i <= array_size; i += p)
		{
			//multiplies of a given number of deemed false
			prime[i] = false;
		}
	}
}