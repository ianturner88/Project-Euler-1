#include<string>
#include<fstream>
#include<streambuf>
#include<iostream>
using namespace std;

int main(void)
{
	ifstream file("PE013.txt");
	string line_x;

	while (getline(file, line_x))
	{
		cout << line_x << endl;
	}

	//system pause
	getchar();
}