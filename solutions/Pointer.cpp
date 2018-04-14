#include<iostream>
using namespace std;

int main (void)
{
	int number = 88; // declares the integer variable to have a value of 88
	int *pNumber; // declares a pointer of type integer
	pNumber = &number; // assigns the address of the variable number to the pointer pNumber
	
	cout << number << endl; // returns the number 88
	cout << *pNumber << endl; //returns the value stored at the memory address of pNumber
	cout << pNumber << endl; // returns the memory location's address
	cout << &number << endl; // the '&' latched on to a variable returns the address of the variable
	
	cout << endl;
	
	*pNumber = 99; // this changes the value stored in number, since the memory location of number is now updated to store 99 - not 88
	
	cout << pNumber << endl; // the memory location of number
	cout << *pNumber << endl; // the 'new' value stored in number
}
