#include<iostream>
using namespace std;

int twice(int n);

int main (void)
{
	int n = 5;
	
	cout << &n << endl; // prints the memory location of n
	cout << n << endl; // prints the value of n
	
	cout << "a" << endl; // prints a, as a marker to show the code's flow
	
	twice(n); // calls the function 'twice'
	
	cout << "c" << endl; // prints c, ditto
	
	cout << n << endl; // prints n as 5, unchanged by the function
}

twice(int number)
{
	cout << &number << endl; // prints the memory location of the variable number
	cout << number << endl; // prints the value of number
	
	cout << "b" << endl; // prints b, ditto
	
	number *= number; // sets number equal to the square of itself
	
	cout << number << endl; // prints the new value of number (25)
	
	return number;
}
