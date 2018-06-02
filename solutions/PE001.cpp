#include<iostream>
using namespace std;

int calcsum(int u, int h);
int sumlimit(int x, int y, int z);
void answer(int a, int b, int c, int s);
int upperlimit();

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int ul = 0;
	int sum = 0;

	ul = upperlimit();

	int h = 3;
	a = calcsum(ul, h);

	h = 5;
	b = calcsum(ul, h);

	h = 15;
	c = calcsum(ul, h);

	sumlimit(a, b, c);
	answer(a, b, c, sum);

	system ("pause");
}


int upperlimit()
{
	int u;

	cout << "Please enter the upperlimit" << endl;
	cin >> u;

	return u;

	// 'void' when not returning something - here, u is being returned, so we have the return type 'int' 
}

///////////


void answer(int a, int b, int c, int s)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << s;
}

// void because there's no return. may pass by value in as much as we like. don't use pass by reference because the values are
// are constnat and being output b

///////////////

int calcsum(int u, int h)
{
	int x = 0;
	
	for (int m = 0; m < u; m += h)
	{
		x += m;
	}

	return x;
}

/////////////////////

int sumlimit(int x, int y, int z)
{
	return  x + y - z;
}
// the function is given the value of the summation 
