#include<iostream>
#include<string>
using namespace std;

void Length_Check(string &project_euler, int &pe_length, int &pe_digit_counter, int &ds_length, string &digit_sum);
void Assign_Counter_Value(int &pe_digit_counter, int &pe_length);
void Assign_Case_N(string &project_euler, int &case_n, int pe_digit_counter);
void Add_LSB(string &digit_sum, string &project_euler, int &case_n, int &pe_length, int &ds_length, int &carry);
void Carry(int &carry, string &digit_sum);
void Reverse(string &digit_sum);

int main(void)
{
	string digit_sum = "0", project_euler = "3825";
	int case_n, pe_length = 0, pe_digit_counter = 1, ds_length, carry;

	Length_Check(project_euler, pe_length, pe_digit_counter, ds_length, digit_sum);
	Assign_Counter_Value(pe_digit_counter, pe_length);

	while (pe_digit_counter != 0)
	{
		Assign_Case_N(project_euler, case_n, pe_digit_counter);
		Add_LSB(digit_sum, project_euler, case_n, pe_length, ds_length, carry);
		Carry(carry, digit_sum);
	}
	
	Reverse(digit_sum);

	cout << digit_sum << endl;
}

void Length_Check(string &project_euler, int &pe_length, int &pe_digit_counter, int &ds_length, string &digit_sum)
{
	/*Calculate the length of the two strings*/

	pe_length = project_euler.length();
	ds_length = digit_sum.length();
}

void Assign_Counter_Value(int &pe_digit_counter, int &pe_length)
{
	/*Assign a counter the value of pe_length*/

	pe_digit_counter = pe_length;
}

void Assign_Case_N(string &project_euler, int &case_n, int pe_digit_counter)
{
	/*Assign the int case_n the value of the 'next' digit in
	the string project_euler.*/
	
	case_n = (project_euler[pe_digit_counter - 1] - '0');

	pe_digit_counter--;
}

void Add_LSB(string &digit_sum, string &project_euler, int &case_n, int &pe_length, int &ds_length, int &carry)
{
	/*Add the 'latest' int from the string project_euler
	to the solution, digit_sum.*/
	
	int sum = (digit_sum[ds_length - 1] - '0') + case_n;
	carry = sum / 10;

	digit_sum.push_back(sum % 10 + '0');
}

void Carry(int &carry, string &digit_sum)
{
	/*If there's a carry - for example, 9 + 4 = 13 -
	the carry is 1*/
	
	if (carry == 1)
	{
		digit_sum.push_back(carry + '0');
	}
}

void Reverse(string &digit_sum)
{
	/*Reverse the answer, digit_sum*/
	
	reverse(digit_sum.begin(), digit_sum.end());
}