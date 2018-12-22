#include<iostream>
#include<string>
#include <time.h>
#include <vector>
using namespace std;

void Program_Execution_Time(clock_t total_time);
void MSB(string &current_sum, string previous_n_factorial, string &n_factorial, int &carry);
void LSB(string &current_sum, string previous_n_factorial, string &n_factorial, int &carry);
void Carry(string &n_factorial, int carry);
void Reset_Variables(string &n_factorial, int &carry, string &current_sum);
void Reverse(string &previous_n_factorial, string &current_sum);
void Store_N_Factorial_in_Vector(vector<string> &vector_n_factorial, string n_factorial);

int main(void)
{
	clock_t total_time;
	int n_factorial_counter = 4, carry = 0;
	string n_factorial = "5", previous_n_factorial = "24", current_sum = "0";
	vector<string> vector_n_factorial;

	//start clock
	total_time = clock();

	//initialize current_sum & reverse the hard-coded input for previous_n_factorial of 4!
	Reverse(previous_n_factorial, current_sum);


	while (n_factorial_counter < 11)
	{
		/*driving algorithm to determine n_factorial*/
		
		//increment number whose factorial is being calculated
		n_factorial_counter++;

		for (int i = 0; i < (n_factorial_counter - 1); i++)
		{
			/*sums up previous_n_factorial (n+1) times
			example: (9! * 10) = 10! */
			
			//add most significant digits of both strings
			MSB(current_sum, previous_n_factorial, n_factorial, carry);
			//add least significant digits of current_sum, the larger string
			LSB(current_sum, previous_n_factorial, n_factorial, carry);
			//add carry, if it exists
			Carry(n_factorial, carry);
			//reset, so cycle may begin again 
			Reset_Variables(n_factorial, carry, current_sum);
		}

		//store factorials of every number... contents will be outputted at the end
		Store_N_Factorial_in_Vector(vector_n_factorial, n_factorial);
	}
	
	//output program's execution time
	Program_Execution_Time(total_time);
	//system pause
	getchar();
}

void Store_N_Factorial_in_Vector(vector<string> &vector_n_factorial, string n_factorial)
{
	vector_n_factorial.push_back(n_factorial);
}

void Reset_Variables(string &n_factorial, int &carry, string &current_sum)
{
	/*reset all variables prior to the next cycle's start*/

	// current_sum  += previous_n_factorial
	current_sum = n_factorial;
	//empty so that new (previous_n_factorial + current_sum) may be stored
	n_factorial = "";
	//reset
	carry = 0;
}

void Reverse(string &previous_n_factorial, string &current_sum)
{
	/*the code's structure depends on the initial numerical string input being reversed*/

	//reverse first hard-coded previous_n_factorial, 4!
	reverse(previous_n_factorial.begin(), previous_n_factorial.end());
	//current sum is initially blank
	current_sum = previous_n_factorial;
}

void Carry(string &n_factorial, int carry)
{
	/*add the final hierarchical digit, if the digit exists*/

	if (carry == 1)
	{
		n_factorial.push_back(carry + '0');
	}
}

void LSB(string &current_sum, string previous_n_factorial, string &n_factorial, int &carry)
{
	/*add MSB of the larger string to n_factorial*/

	//establish the upperbound for the loop
	int current_sum_length = current_sum.length();
	//establish the loop's starting point
	int previous_n_factorial_length = previous_n_factorial.length();

	//the MSB digits that need to be added to n_factorial
	for (int i = previous_n_factorial_length; i < current_sum_length; i++)
	{
		//sum remaining digits
		int sum = (current_sum[i] - '0') + carry;
		//store sum in answer
		n_factorial.push_back((sum % 10) + '0');

		//check if sum exceeds 9
		carry = sum / 10;
	}
}

void MSB(string &current_sum, string previous_n_factorial, string &n_factorial, int &carry)
{
	/*add the LSB of the 2 strings*/

	//the length of the shorter string to ensure all most significant bits are added
	int previous_n_factorial_length = previous_n_factorial.length();

	for (int i = 0; i < previous_n_factorial_length; i++)
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

void Program_Execution_Time(clock_t total_time)
{
	//calculate total execution time
	total_time = clock() - total_time;
	//output program's execution time
	cout << "program's execution took: " << total_time << endl;
}