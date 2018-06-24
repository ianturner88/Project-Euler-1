#include<iostream>
#include<string>
using namespace std;

void Set_Str1_and_Str2(string &str1, string &str2, string &str3);
void Clear_Str3(string &str3);
void Length_Calculator(string &str1, int &string_length);
void Add_Digits(string &str1, string &str2, string &str3, int &string_length, int &carry);
void Carry(int &carry, string &str3);
void Reverse(string &str3);
void Digit_Return(string &str3, int &string_length, int &digit);
void Add_LSB(string &str3, string &str4, int &digit, int &sum, int &string_length, int &carry);

int main()
{
	int addition_limit = 2, exponent = 0, string_length, carry = 0, digit, sum;
	string str1 = "1", str2, str3 = "1", str4 = "0";

	while (exponent < 15)
	{
		Set_Str1_and_Str2(str1, str2, str3);
		Clear_Str3(str3);
		Length_Calculator(str1, string_length);
		Add_Digits(str1, str2, str3, string_length, carry);
		Carry(carry, str3);

		exponent++;
	}

	Reverse(str3);
	Length_Calculator(str3, string_length);

	string_length--;
	str4 = str3[string_length];
	carry = 0;

	while (string_length >= 0)
	{
		Digit_Return(str3, string_length, digit);
		Add_LSB(str3, str4, digit, sum, string_length, carry);
		string_length--;
	}

	Carry(carry, str4);
	
	str4.erase(str4.begin());

	Reverse(str4);

	system("pause");

	return 0;
}

void Set_Str1_and_Str2(string &str1, string &str2, string &str3)
{
	/*We set the second string equal to the first string*/

	str1 = str3;
	str2 = str3;
}

void Length_Calculator(string &str1, int &string_length)
{
	/*We calculate the length of str1. This is needed for a
	subsequent for loop.*/
	
	string_length = str1.length();
}

void Add_Digits(string &str1, string &str2, string &str3, int &string_length, int &carry)
{
	/*We add the str1 & str2 to 'simulate' multiplication*/
	
	int sum;

	for (int i = 0; i < string_length; i++)
	{
		sum = (str1[i] - '0') + (str2[i] - '0') + carry;

		str3.push_back(sum % 10 + '0');

		carry = sum / 10;
	}

	str3.erase(str3.begin());
}

void Clear_Str3(string &str3)
{
	/* Clear out str3 so that str1 & str2 can be added together and 
	placed into str3.*/
	
	str3 = "0";
}

void Carry(int &carry, string &str3)
{
	/* If there is a 'final' carry, add the carry*/
	
	if (carry == 1)
	{
		str3.push_back(carry + '0');
	}

	carry = 0;
}

void Reverse(string &str3)
{
	reverse(str3.begin(), str3.end());
}

void Digit_Return(string &str3, int &string_length, int &digit)
{
	digit = (str3[string_length] - '0');
}

void Add_LSB(string &str3, string &str4, int &digit, int &sum, int &string_length, int &carry)
{
	//int i = 0;
	sum = digit + carry + (str4[1] - '0');
	carry = sum / 10;

	str4.push_back(sum % 10 + '0');

	//i++;
}