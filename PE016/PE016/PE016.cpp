#include<string>
#include<iostream>
using namespace std;

void Reset_Variables(string &multiple_two, string &duplicate_multiple_two, string &PE016_power_digit, 
	int &carry);
void Add_2_Duplicate_Strings(string &multiple_two, string &duplicate_multiple_two, 
	string &PE016_power_digit, int &carry);
void Carry(string &PE016_power_digit, int &carry);
void Reverse(string &PE016_power_digit, string &multiple_two);
void Determine_Length_of_String(string &PE016_power_digit, int &PE016_answer_length);
void Identify_Character_to_be_Added(string &PE016_answer_length, int &i, string &digit_to_sum);
void MSB(string &digit_to_sum, string &current_sum, string &PE016_answer, int &carry);
void Add_Remainder_of_Variable_Current_Sum(string &PE013_answer, int &carry, string &current_sum);

int main(void)
{
	string multiple_two = "", duplicate_multiple_two = "", PE016_power_digit = "2",
		digit_to_sum = "", PE016_answer = "", current_sum = "0";
	int exponent = 2, carry = 0, PE016_answer_length;

	//initialize the variables
	Reset_Variables(multiple_two, duplicate_multiple_two, PE016_power_digit, carry);

	while (exponent < 25)
	{
		/*driving algorithm to determine the number whose
		digits are to be summed*/

		//add the two duplicate string together
		Add_2_Duplicate_Strings(multiple_two, duplicate_multiple_two, PE016_power_digit, carry);
		//add carry of previous function, if there's a carry
		Carry(PE016_power_digit, carry);
		//duplicate_multiple_two is set equal to multiple_two
		Reset_Variables(multiple_two, duplicate_multiple_two, PE016_power_digit, carry);

		//one step closer to the upperbound
		exponent++;
	}
	
	//output number whose digits are to be summed
	Reverse(PE016_power_digit, multiple_two);
	//determine length of number whose digits are to be summed
	Determine_Length_of_String(PE016_power_digit, PE016_answer_length);

	for (int i = 0; i < PE016_answer_length; i++)
	{
		/*driving algorithm to sum up the digits required to answer PE016*/

		//picks off next digit to be summed
		Identify_Character_to_be_Added(PE016_power_digit, i, digit_to_sum);
		//add the 0th digit of the current sum with the digit to be added
		MSB(digit_to_sum, current_sum, PE016_answer, carry);
		//add 1st to nth digit of current sum to the final answer
		Add_Remainder_of_Variable_Current_Sum(PE016_answer, carry, current_sum);
	}

	//system pause
	getchar();
}

void Add_Remainder_of_Variable_Current_Sum(string &PE016_answer, int &carry, string &current_sum)
{
	//ensures the current_sum is correctly added to PE013_answer
	int upperbound = current_sum.length();

	for (int i = 1; i < upperbound; i++)
	{
		//value of digit i + carry
		int sum = ((current_sum[i] - '0') + carry);
		//add resulting 0th digit to answer
		PE016_answer.push_back((sum % 10) + '0');
		//if the sum exceeds 9, there's a carry
		carry = sum / 10;
	}
}

void MSB(string &digit_to_sum, string &current_sum, string &PE016_answer, int &carry)
{
	/*add the MSB of both strings*/

	//sum of the 0th index value of the both strings
	int sum = ((digit_to_sum[0] - '0') + (current_sum[0] - '0'));
	//store the resulting sum in the variable PE013_answer
	PE016_answer.push_back((sum % 10) + '0');
	//if the sum exceeds 9, there's a carry
	carry = sum / 10;
}

void Identify_Character_to_be_Added(string &PE016_power_digit, int &i, string &digit_to_sum)
{
	/*identifies the next digit to be summed*/

	digit_to_sum = PE016_power_digit[i];
}


void Determine_Length_of_String(string &PE016_power_digit, int &PE016_answer_length)
{
	/*PE016_answer_length is used as an upperbound when summing
	the digits of PE016_answer*/
	
	PE016_answer_length = PE016_power_digit.length();
}

void Reverse(string &PE016_power_digit, string &multiple_two)
{
	/*prep and present the number whose digits are to be summed*/
	
	//update to final value
	PE016_power_digit = multiple_two;
	//prep number
	reverse(PE016_power_digit.begin(), PE016_power_digit.end());
	//present number
	cout << PE016_power_digit;
}

void Carry(string &PE016_power_digit, int &carry)
{
	/*add the final hierarchical digit, if the digit exists*/

	if (carry == 1)
	{
		PE016_power_digit.push_back(carry + '0');
	}
}

void Reset_Variables(string &multiple_two, string &duplicate_multiple_two, string &PE016_power_digit,
	int &carry)
{
	/*reset variables at the start of a new cycle*/
	
	//hard-coded to 2, initially
	multiple_two = PE016_power_digit;

	/*these two numbers must be equal so that multplication can be simulate when 
	they're added together*/
	duplicate_multiple_two = multiple_two;

	//clean out final answer
	PE016_power_digit = "";

	//carry is reset
	carry = 0;
}

void Add_2_Duplicate_Strings(string &multiple_two, string &duplicate_multiple_two, 
	string &PE016_power_digit, int &carry)
{
	/*add the LSB of the two strings that are copies of each other*/

	//reset carry variable
	carry = 0;
	//establish upperbound for the loop
	int multiple_two_length = multiple_two.length();

	for (int i = 0; i < multiple_two_length; i++)
	{
		/*loop cycle through the full length of the smaller string*/

		//sum of the index i value of the 2 strings
		int sum = ((multiple_two[i] - '0') + (duplicate_multiple_two[i] - '0') + carry);
		//store the resulting sum in the variable PE013_answer
		PE016_power_digit.push_back((sum % 10) + '0');
		//if the sum exceeds 9, there's a carry
		carry = sum / 10;
	}
}