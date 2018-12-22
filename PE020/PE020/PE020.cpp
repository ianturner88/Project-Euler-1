#include<iostream>
#include<string>
#include <time.h>
using namespace std;

void Time(clock_t total_time);
void MSB(string &current_sum, string &previous_n_factorial, string &n_factorial, int &carry,
	int &current_sum_length);
void LSB(string &current_sum, string &previous_n_factorial, int &current_sum_length,
	string &n_factorial, int &carry);
void Carry(string &n_factorial, int carry);
void Reset_Variables(string &n_factorial, int &carry, string &previous_n_factorial);

int main(void)
{
	clock_t total_time;
	int n_factorial_counter = 0, carry = 0, current_sum_length = 0;
	string n_factorial = "", previous_n_factorial = "", current_sum = "";

	//start clock
	total_time = clock();

	while (n_factorial_counter < 11)
	{
		/*driving algorithm to determine n_factorial*/
		
		//increment number whose factorial is being calculated
		n_factorial_counter++;

		for (int i = 0; i < n_factorial_counter; i++)
		{
			/*sums up previous_n_factorial (n+1) times
			example: (9! * 10) = 10! */
			
			//add most significant digits of both strings
			MSB(current_sum, previous_n_factorial, n_factorial, carry, current_sum_length);
			//add least significant digits of current_sum, the larger string
			LSB(current_sum, previous_n_factorial, current_sum_length, n_factorial, carry);
			//add carry, if it exists
			Carry(n_factorial, carry);
			//reset, so cycle may begin again 
			Reset_Variables(n_factorial, carry, previous_n_factorial);
		}
	}
	
	//output program's execution time
	Time(total_time);
	//system pause
	getchar();
}

void Reset_Variables(string &n_factorial, int &carry, string &previous_n_factorial)
{
	/*reset all variables prior to the next cycle's start*/
	
	//number that'll be add together n times
	previous_n_factorial = n_factorial;
	//used to store next resulting sum
	n_factorial = "";
	//clear
	carry = 0;
}

void Carry(string &n_factorial, int carry)
{
	/*add the final hierarchical digit, if the digit exists*/

	if (carry == 1)
	{
		n_factorial.push_back(carry + '0');
	}
}

void LSB(string &current_sum, string &previous_n_factorial, int &current_sum_length,
	string &n_factorial, int &carry)
{
	/*add MSB of the larger string to n_factorial*/

	//establish starting point for for loop
	int int_previous_n_factorial = previous_n_factorial.length();

	//the MSB digits that need to be added to n_factorial
	for (int i = int_previous_n_factorial; i < current_sum_length; i++)
	{
		//sum remaining digits
		int sum = (current_sum[i] - '0') + carry;
		//store sum in answer
		n_factorial.push_back((sum % 10) + '0');

		//check if sum exceeds 9
		carry = sum / 10;
	}
}

void MSB(string &current_sum, string &previous_n_factorial, string &n_factorial, int &carry, 
	int &current_sum_length)
{
	/*add the LSB of the 2 strings*/

	for (int i = 0; i < current_sum_length; i++)
	{
		/*loop cycle through the full length of the smaller string*/

		//sum of the index i value of the 2 strings
		int sum = ((current_sum[i] - '0') + (previous_n_factorial[i] - '0') + carry);
		//store the resulting sum in the variable n_factorial
		n_factorial.push_back((sum % 10) + '0');
		//if the sum exceeds 9, there's a carry
		carry = sum / 10;
	}
}

void Time(clock_t total_time)
{
	//calculate total execution time
	total_time = clock() - total_time;
	//output program's execution time
	cout << "time1: " << total_time << endl;
}