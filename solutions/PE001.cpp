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

	system("pause");
}


int upperlimit()
{
	/* The user enters the upperlimit.
	'void' when not returning something.
	Here, u is being returned, so we have 
	the return type 'int' */ 

	int u;

	cout << "Enter the upperlimit: " << endl;
	cin >> u;

	return u;
}

void answer(int a, int b, int c, int s)
{
	/* void because there's no return. 
	may pass by value in as much as we like. 
	don't use pass by reference because the values
	are constnat and being output */ 
	
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << s;
}

int calcsum(int u, int h)
{
	/* calculate the sum of the multiples 
	of 3, 5, & 15 that are less than the
	upperlimit
	*/
	
	int x = 0;

	for (int m = 0; m < u; m += h)
	{
		x += m;
	}

	return x;
}

int sumlimit(int x, int y, int z)
{
	// the function is given the value of the summation 

	return  x + y - z;
}