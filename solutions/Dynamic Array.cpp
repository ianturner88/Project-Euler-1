#include<iostream>
using namespace std;

const int CAPACITY = 100000;

int main (void)
{
	int *dArray;
	dArray = new int[CAPACITY];
	
	dArray[0] = 1;
	dArray[1] = 3;
	dArray[2] = 5;
	dArray[3] = 7;
	
	cout << "Array: ";
	
	for (int i = 0; i < 4; i++)
	{
		cout << dArray[i] << " ";
	}
}
