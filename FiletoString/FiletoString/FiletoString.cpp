/*
#include <string>
#include <fstream>
#include <streambuf>

std::ifstream t("file.txt");
std::string str((std::istreambuf_iterator<char>(t)),
	std::istreambuf_iterator<char>());
*/

#include<string>
#include<fstream>
#include<streambuf>
#include<iostream>
using namespace std;

int main(void)
{
	ifstream fin("numbers.txt");
	int x, Ian;

	while (fin >> x)
	{
		cout << x << endl;
	}

	cin >> Ian;
}