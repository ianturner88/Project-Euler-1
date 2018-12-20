#include<string>
#include<iostream>
using namespace std;

void Reset_Variables(string &multiple_two, string &duplicate_multiple_two, string &PE016_answer, 
	int &carry);
void Add_2_Duplicate_Strings(string &multiple_two, string &duplicate_multiple_two, 
	string &PE016_answer, int &carry);
void Carry(string &PE016_anwer, int &carry);
void Reverse(string &PE016_answer);

int main(void)
{
	string multiple_two = "", duplicate_multiple_two = "", PE016_answer = "2";
	int exponent = 2, carry = 0;

	//initialize the variables
	Reset_Variables(multiple_two, duplicate_multiple_two, PE016_answer, carry);

	while (exponent < 10001)
	{
		/*driving algorithm*/

		//add the two duplicate string together
		Add_2_Duplicate_Strings(multiple_two, duplicate_multiple_two, PE016_answer, carry);
		//add carry of previous function, if there's a carry
		Carry(PE016_answer, carry);
		//duplicate_multiple_two is set equal to multiple_two
		Reset_Variables(multiple_two, duplicate_multiple_two, PE016_answer, carry);

		//one step closer to the upperbound
		exponent++;
	}
	
	//test
	//output final answer
	Reverse(multiple_two);

	getchar();
}

void Reverse(string &PE016_answer)
{
	/*prep and present final answer*/
	
	//prep final answer
	reverse(PE016_answer.begin(), PE016_answer.end());
	//present final answer
	cout << PE016_answer;
}

void Carry(string &PE016_anwer, int &carry)
{
	/*add the final hierarchical digit, if the digit exists*/

	if (carry == 1)
	{
		PE016_anwer.push_back(carry + '0');
	}
}

void Reset_Variables(string &multiple_two, string &duplicate_multiple_two, string &PE016_answer,
	int &carry)
{
	/*reset variables at the start of a new cycle*/
	
	//hard-coded to 2, initially
	multiple_two = PE016_answer;

	/*these two numbers must be equal so that multplication can be simulate when 
	they're added together*/
	duplicate_multiple_two = multiple_two;

	//clean out final answer
	PE016_answer = "";

	//carry is reset
	carry = 0;
}

void Add_2_Duplicate_Strings(string &multiple_two, string &duplicate_multiple_two, string &PE016_answer, int &carry)
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
		PE016_answer.push_back((sum % 10) + '0');
		//if the sum exceeds 9, there's a carry
		carry = sum / 10;
	}
}