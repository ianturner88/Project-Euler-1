#include<iostream>
using namespace std;

void sum3(int &x, int &u);
void sum5(int &y, int &u);
void sum15(int &z, int &u);
void sumlimit(int &x, int &y, int &z, int &s);
void answer(int &a, int &b, int &c, int &s);
void upperlimit(int &u);

int main ()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int ul = 0;
	int sum = 0;
	
	upperlimit(ul);
	sum3(a, ul);
	sum5(b, ul);
	sum15(c, ul);
	sumlimit(a, b, c, sum);
	answer(a, b, c, sum);
}

void upperlimit(int &u)
{
	cout << "Please enter the upperlimit" << endl;
	cin >> u;
}

void answer(int &a, int &b, int &c, int &s)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << s;
}

void sum3(int &x, int &u)
{
	for (int m = 0; m < u; m += 3)
	{
		x += m;
	}
}

void sum5(int &y, int &u)
{
	for (int m = 0; m < u; m += 5)
	{
		y += m;
	}
}

void sum15(int &z, int &u)
{
	for (int m = 0; m < u; m += 15)
	{
		z += m;
	}
}

void sumlimit(int &x, int &y, int &z, int &s)
{
	s = x + y - z;
}
