/*
Question: A palindromic number reads the same both ways. The largest
palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include<iostream>
using namespace std;

void Palindrome(int &answer, int &testcase);
void Divisor_First(int &testcase, int &flag, int &first_divisor, int &second_divisor);
void Condition_Check(int &testcase, int &flag, int &first_divisor, int &second_divisor);

int main(void)
{
	int flag = 0;
	int answer = 954;
	int first_divisor = 100;
	int second_divisor = 0;
	int testcase = 0;

	/*The flag will be 'put up & stay up' if a first & second divisor are found
	that are each three digits long*/

	while (flag == 0)
	{
		first_divisor = 100;
		second_divisor = 0;

		Palindrome(answer, testcase);
		Divisor_First(testcase, flag, first_divisor, second_divisor);
		if (flag == 1)
		{
			Condition_Check(testcase, flag, first_divisor, second_divisor);
		}
	}

	cout << answer << endl;
	cout << (answer / 100) * 1000 + ((answer / 10) % 10) * 10000 + ((answer % 10) * 100000) + answer << endl;

	system("pause");
}

void Palindrome(int &answer, int &testcase)
{
	/*Produce the palindromes*/

	answer--;

	testcase = (answer / 100) * 1000 + ((answer / 10) % 10) * 10000 + ((answer % 10) * 100000) + answer;
}

void Divisor_First(int &testcase, int &flag, int &first_divisor, int &second_divisor)
{
	//first_divisor = 100;

	while (first_divisor < (testcase / 2) && flag == 0)
	{
		/*If the first divisor of the palindrome is found, the second is
		also recored. Otherwise, increment the variable 'first_divisor' to
		see if the variable divides into the palindrome.*/

		if (testcase % first_divisor == 0)
		{
			flag = 1;
			second_divisor = testcase / first_divisor;
		}

		else
		{
			first_divisor++;
		}
	}
}

void Condition_Check(int &testcase, int &flag, int &first_divisor, int &second_divisor)
{
	/*Ensure that both divisors are 3 digits long.*/

	flag = 0;
	int count_first = 0;
	int count_second = 0;
	int count_testcase = 0;

	while (first_divisor > 0)
	{
		first_divisor = first_divisor / 10;
		count_first++;
	}

	while (second_divisor > 0)
	{
		second_divisor = second_divisor / 10;
		count_second++;
	}

	while (testcase > 0)
	{
		testcase = testcase / 10;
		count_testcase++;
	}

	if (count_first == 3 && count_second == 3 && count_testcase == 6)
	{
		flag = 1;
	}
	//test
	else
	{
		flag = 0;
	}
}