#include<iostream>
#include<string>
#include <time.h>
using namespace std;

void Time(clock_t total_time);
void MSB(string &current_sum, string &previous_n_factorial, string &n_factorial, int &carry,
	int &current_sum_length);

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
			example: 9! * 10 = 10 !*/
			
			//add most significant digits of both strings
			MSB(current_sum, previous_n_factorial, n_factorial, carry, current_sum_length);


		}
	}
	
	//output program's execution time
	Time(total_time);
	//system pause
	getchar();
}

void LSB(string &current_sum, int number_x_length, int current_sum_length,
	string &PE013_answer, int &carry)
{
	/*add MSB of the larger string to PE013_answer*/

	//the MSB digits that need to be added to PE013_answer
	for (int i = number_x_length; i < current_sum_length; i++)
	{
		//test
		i;
		int check = (current_sum[i] - '0');
		carry;

		//sum remaining digits
		int sum = (current_sum[i] - '0') + carry;
		//store sum in answer
		PE013_answer.push_back((sum % 10) + '0');

		//check if sum exceeds 9
		carry = sum / 10;
	}
}

void MSB(string &current_sum, string &previous_n_factorial, string &n_factorial, int &carry, 
	int &current_sum_length)
{
	/*add the LSB of the 2 strings*/

	//reset carry variable
	carry = 0;

	for (int i = 0; i < current_sum_length; i++)
	{
		/*loop cycle through the full length of the smaller string*/

		//sum of the index i value of the 2 strings
		int sum = ((current_sum[i] - '0') + (previous_n_factorial[i] - '0') + carry);
		//store the resulting sum in the variable PE013_answer
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