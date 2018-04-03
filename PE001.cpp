#include<iostream>
using namespace std;

void calcsum(int &x, int &u, int &h);
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
	
	int h = 3;
	calcsum(a, ul, h);
	
	h = 5;
	calcsum(b, ul, h);
	
	h = 15;
	calcsum(c, ul, h);
	
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

void calcsum(int &x, int &u, int &h)
{
	for (int m = 0; m < u; m += h)
	{
		x += m;
	}
}

void sumlimit(int &x, int &y, int &z, int &s)
{
	s = x + y - z;
}
