#include<iostream>
using namespace std;

int main (void)
{
	int number = 88; //an integer variable called number gets the value 88
	int &alias = number; // the integer variable alias is a duplicate of the integer variable number. Number & alias are linked; they will always have the same value
	
	cout << alias; // prints 88
	
	cout << endl; // space
	
	alias = 77; // both alias 
	
	cout << alias << endl;
	cout << number;
}
