#include<string>
#include<iostream>
using namespace std;

void Length_Calculator(int &n1, int &n2, int &n3, int &length_difference, string &fibonacci1, string &fibonacci2, string &fibonacci_next);
void Fibonacci_Generator(string &fibonacci1, string &fibonacci2, string &fibonacci_next);
void Fibonacci_Next(string &fibonacci_next);
void Add_LSB(string &fibonacci1, string &fibonacci2, string &fibonacci_next, int &length_difference, int &carry, int &n1, int &n2, int &sum);
void Add_MSB(string &fibonacci2, string &fibonacci_next, int &length_difference, int &n1, int &n2, int &carry);
void Carry(string &fibonacci_next, int &carry);
void ReverseFNext(string &fibonacci_next);
void ReverseAllFibonacciNumbers(string &fibonacci1, string &fibonacci2, string &fibonacci_next);

int main()
{
	string fibonacci1 = "55", fibonacci2 = "89", fibonacci_next = "144";
	int length_difference, carry = 0, count = 12, n1, n2, n3 = 1, sum = 0;

	ReverseAllFibonacciNumbers(fibonacci1, fibonacci2, fibonacci_next);

	while (n3 != 1000)
	{
		Fibonacci_Generator(fibonacci1, fibonacci2, fibonacci_next);
		Fibonacci_Next(fibonacci_next);
		Length_Calculator(n1, n2, n3, length_difference, fibonacci1, fibonacci2, fibonacci_next);
		Add_LSB(fibonacci1, fibonacci2, fibonacci_next, length_difference, carry, n1, n2, sum);
		Add_MSB(fibonacci2, fibonacci_next, length_difference, n1, n2, carry);
		Carry(fibonacci_next, carry);
		Length_Calculator(n1, n2, n3, length_difference, fibonacci1, fibonacci2, fibonacci_next);

		count++;
	}

	ReverseFNext(fibonacci_next);

	cout << "The index number of the first fibonacci number with 1 000 digits is: " << count << endl << endl;

	cout << "The " << count << " fibonacci number is " << fibonacci_next << endl;

	system("pause");

	return 0;
}

void Length_Calculator(int &n1, int &n2, int &n3, int &length_difference, string &fibonacci1, string &fibonacci2, string &fibonacci_next)
{
	/*Calculate the length of all strings. Needed for various subsequent for loops &
	to determine if a Fibonacci number with 1000 digits has been found*/

	n1 = fibonacci1.length();
	n2 = fibonacci2.length();
	n3 = fibonacci_next.length();

	length_difference = n2 - n1;
}

void Fibonacci_Generator(string &fibonacci1, string &fibonacci2, string &fibonacci_next)
{
	/*Traditionally, Fnext = F1 + F2 is the first line*/

	fibonacci1 = fibonacci2;
	fibonacci2 = fibonacci_next;
}

void Fibonacci_Next(string &fibonacci_next)
{
	/*The ensuing functions calculate fibonacci_next.
	The zero will be deleted later.*/

	string replacement = "0";

	fibonacci_next = replacement;
}

void Add_LSB(string &fibonacci1, string &fibonacci2, string &fibonacci_next, int &length_difference, int &carry, int &n1, int &n2, int &sum)
{
	/*Add the least significant bits of both numbers*/

	{
		carry = 0;

		for (int i = 0; i < n1; i++)
		{
			int test1 = (fibonacci1[i] - '0');
			int test2 = (fibonacci2[i] - '0');

			sum = (fibonacci1[i] - '0') + (fibonacci2[i] - '0') + carry;

			fibonacci_next.push_back(sum % 10 + '0');

			carry = sum / 10;
		}
	}

	/*Delete the zero at the start of fibonacci_next*/
	fibonacci_next.erase(fibonacci_next.begin());
}

void Add_MSB(string &fibonacci2, string &fibonacci_next, int &length_difference, int &n1, int &n2, int &carry)
{
	/*Add the most sigificant digits of n2, the larger number*/

	int remainder;
	int increment = n1;

	for (int i = n2 - n1 - 1; i >= 0; i--)
	{
		int test = fibonacci2[increment];

		remainder = ((fibonacci2[increment] - '0') + carry);
		carry = remainder / 10;

		fibonacci_next.push_back(remainder + '0');

		increment++;
	}
}

void Carry(string &fibonacci_next, int &carry)
{
	/*For the most significant digit*/

	if (carry == 1)
	{
		fibonacci_next.push_back(carry + '0');
	}
}

void ReverseFNext(string &fibonacci_next)
{
	/*Reverse the digit to the 'normal' order once the
	algorithm has run.*/

	reverse(fibonacci_next.begin(), fibonacci_next.end());
}

void ReverseAllFibonacciNumbers(string &fibonacci1, string &fibonacci2, string &fibonacci_next)
{
	/*Reverses the digits of all numbers to all the algorithm to work*/

	reverse(fibonacci1.begin(), fibonacci1.end());
	reverse(fibonacci2.begin(), fibonacci2.end());
	reverse(fibonacci_next.begin(), fibonacci_next.end());
}