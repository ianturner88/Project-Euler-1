#include<iostream>
using namespace std;

void sum3(int &x, int &u);
void sum5(int &y, int &u);
void sum15(int &z, int &u);
void sumlimit(int &x, int &y, int &z, int &s);

int main ()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int upperlimit = 1000;
	int sum = 0;
	
	sum3(a, upperlimit);
	sum5(b, upperlimit);
	sum15(c, upperlimit);
	sumlimit(a, b, c, sum);
	
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << sum;
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
