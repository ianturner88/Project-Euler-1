#include<string>
#include<fstream>
#include<streambuf>
#include<iostream>
using namespace std;

int main(void)
{
	ifstream PE013_Input_File("PE013.txt");
	string number_x;

	while (getline(PE013_Input_File, number_x))
	{
		/*programs driving algorithm...
		numbers are fed in one at a time*/
		
		//test
		cout << number_x << endl;
	}

	//system pause
	getchar();
}