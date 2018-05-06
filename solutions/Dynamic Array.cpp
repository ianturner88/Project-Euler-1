#include<iostream>
using namespace std;

const int CAPACITY = 100000;

int main (void)
{
	// makes a pointer to the array & states the size of the array
	int *dArray;
	dArray = new int[CAPACITY];
	
	// states the elements of each slot
	dArray[0] = 1;
	dArray[1] = 3;
	dArray[2] = 5;
	dArray[3] = 7;
	
	cout << "Array: ";
	
	// prints the contents of the array
	for (int i = 0; i < 4; i++)
	{
		cout << dArray[i] << " ";
	}
	
	//deletes the array 
	delete [] dArray;
	
	cout << " The last call: " << dArray[0];
	
	dArray = NULL;
}
