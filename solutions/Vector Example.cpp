#include<iostream>
#include<vector>
using namespace std;

int main ()
{
	//vector<DataType> NameOfVector
	
	vector<int> myVector;
	
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
	
	cout << "The vector's size is: "<< myVector.size();
	
	cout << endl;
	
	return 0;
}
