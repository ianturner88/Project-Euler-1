#include<iostream>
using namespace std;

int main (void)
{
	int number = 88;
	int *pNumber;
	pNumber = &number;
	
	cout << number << endl;
	cout << *pNumber << endl;
	cout << &number << endl;
}
