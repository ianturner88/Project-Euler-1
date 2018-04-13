#include<iostream>
#include<vector>
using namespace std;

int main ()
{
	//vector<DataType> NameOfVector
	vector<int> myVector;
	
	//adds an element to the end of the vector & resizes the vector
	//myVector.push_back()
	
	myVector.push_back(298);
	myVector.push_back(78);
	myVector.push_back(56);
	myVector.push_back(724);
	myVector.push_back(312);
	myVector.push_back(34);
	
	cout << "Vector: ";
	
	for (unsigned int i = 0; i < myVector.size(); i++)
	{
		cout << myVector[i] << " ";
	}
	cout << endl;
	
	//returns the vector's size
	//myVector.size()
	
	cout << "The vector's size is: " << myVector.size();
	cout << endl;
	
	//myVector.insert()
	
	
	return 0;
}
