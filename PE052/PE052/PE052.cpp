#include<iostream>
#include <vector>
#include <array>
using namespace std;

void parse_six_digit_number(int six_digit_number, int number_counter, int zero_through_nine[]);
void store_fingerprint(int number_counter, int zero_through_nine[], vector<string> &fingerprint);

int main(void)
{
	int six_digit_number = 122555, number_counter = 0, zero_through_nine[10] = { 0 };
	vector<string> fingerprint;

	while (six_digit_number < 1000000)
	{
		parse_six_digit_number(six_digit_number, number_counter, zero_through_nine);
		store_fingerprint(number_counter, zero_through_nine, fingerprint);
	}
}

void store_fingerprint(int number_counter, int zero_through_nine[], vector<string> &fingerprint)
{
	/*create & store all individual numbers' fingerprints*/
	
	string fingerprint_to_store = "";

	for (int i = 0; i < sizeof(zero_through_nine); i++)
	{
		// final output will be in form abcdefghij (a = 0, ... j = 9)
		fingerprint_to_store += zero_through_nine[i];
	}

	//store fingerprint
	fingerprint[number_counter] = fingerprint_to_store;
}

void parse_six_digit_number(int six_digit_number, int number_counter, int zero_through_nine[])
{
	/*create a fingprint for every number that is 6 digits long*/
	
	int least_significant_digit;
	zero_through_nine[10] = { 0 };
	
	while (six_digit_number > 0)
	{
		/*parse each given number*/
		
		//identify right-most digit
		least_significant_digit = six_digit_number % 10;
		//downsize number by one digit
		six_digit_number /= 10;

		//tally up the given number's fingerprint
		zero_through_nine[least_significant_digit] += 1;
	}
}