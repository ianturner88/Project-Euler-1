#include<iostream>
using namespace std;

int main (void)
{
	int number = 88; //an integer variable called number gets the value 88
	int &alias = number; // the integer variable alias is a duplicate of the integer variable number. Number & alias are linked; they will always have the same value
	
	cout << alias << endl; // prints 88
	cout << number; // prints 88
	
	cout << endl; // space
	
	alias = 77; // both alias & number are changed to 77
	
	cout << alias << endl; // 77 is printed
	cout << number; // 77 is printed
}
