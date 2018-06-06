/* Question: A palindromic number reads the same both ways. The largest 
palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99. 
Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include<iostream>
using namespace std;

int Palindrome(int answer);
void Divisor_First(int &answer, int &flag);
int Divisor_Second(int first_divisor);

int main(void)
{
	int flag = 0;
	int answer = 987;

	while (flag == 0)
	{
		Palindrome(answer);
		if (Divisor_First(flag) == 1)
		{
			Divisor_Second();
		}
	}
}

int Palindrome(int answer)
{
	int testcase;
	
	answer--;

	testcase = (answer / 100) * 1000 + ((answer / 10) % 10) * 10000 + ((answer % 10) * 100000) + answer;

	return testcase;
}

void Divisor_First(int &answer, int &flag)
{
	int divisor = 100;
	int testcase = answer;

	while (divisor < (testcase / 2) && flag == 0)
	{
		if (testcase % divisor == 0)
		{
			flag = 1;
		}

		else
		{
			divisor++;
		}
	}
}

int Divisor_Second(int first_divisor)
{
	int second_divisor = testcase / first_divisor;

	if (sizeof(second_divisor) == 3)
	{

	}
}