#include<iostream>
using namespace std;

void Add(int &a, int b);

int main(void)
{
	int x = 5, y = 6;

	Add(x, y);

	cout << x << endl;
	cout << y << endl << endl;

	getchar();
}

void Add(int &a, int b)
{
	cout << a << endl;
	cout << b << endl << endl;

	a -= 2;
	b -= 2;

	cout << a << endl;
	cout << b << endl << endl;
}