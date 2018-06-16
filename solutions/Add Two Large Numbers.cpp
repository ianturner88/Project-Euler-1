#include<iostream>
#include<string>
using namespace std;

void Length_Check(string &str1, string &str2);
void Length_Calculate(string &answer, string &str1, string &str2, int &length_difference, int &n1, int &n2);
void Add_LSB(string &answer, string &str1, string &str2, int &carry, int &n1, int &n2, int &sum, int &length_difference);
void Add_MSB(string &answer, string &str1, string &str2, int &carry, int &n1, int &n2, int &sum);
void Carry(int &carry, string &answer);
void Reverse(string &answer);

int main()
{
	string str1 = "31675", str2 = "542357", answer;
	int length_difference = 0, carry = 0;
	int n1 = 0, n2 = 0, sum = 0;

	Length_Check(str1, str2);
	Length_Calculate(answer, str1, str2, length_difference, n1, n2);
	Add_LSB(answer, str1, str2, carry, n1, n2, sum, length_difference);
	Add_MSB(answer, str1, str2, carry, n1, n2, sum);
	Carry(carry, answer);
	Reverse(answer);

	cout << answer << endl;

	system("pause");
	return 0;
}

void Length_Check(string &str1, string &str2)
{
	/* Check which string is longer. Swap if #1 is longer
	than #2*/
	
	if (str1.length() > str2.length())
	{
		swap(str1, str2);
	}
}

void Length_Calculate(string &answer, string &str1, string &str2, int &length_difference, int &n1, int &n2)
{
	/*Calculate the length of each string*/

	n1 = str1.length();
	n2 = str2.length();

	length_difference = n2 - n1;
}

void Add_LSB(string &answer, string &str1, string &str2, int &carry, int &n1, int &n2, int &sum, int &length_difference)
{
	/* Add the least signifcant digits. Example: 5 from #1
	and 7 from #2*/

	for (int i = n1 - 1; i >= 0; i--)
	{
		sum = (str1[i] -'0') + (str2[i + length_difference] - '0') + carry;
		int test1 = (str1[i] - '0');
		int test2 = (str2[i + length_difference] - '0');
		carry = sum / 10;
		answer.push_back(sum % 10 + '0');
	}
}

void Add_MSB(string &answer, string &str1, string &str2, int &carry, int &n1, int &n2, int &sum)
{	
	/* Add the remaining digits of string #2*/
	
	for (int i = n2 - n1 - 1; i >= 0; i--)
	{
		sum = (str2[i] - '0');
		carry = sum / 10;
		answer.push_back(sum % 10 + '0');
	}
}

void Carry(int &carry, string &answer)
{
	/*Add the carry, if there is any*/
	
	if (carry == 1)
	{
		answer.push_back(carry + '0');
	}
}

void Reverse(string &answer)
{
	/*Reverse the digits*/
	
	reverse(answer.begin(), answer.end());
}
