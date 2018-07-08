#include<iostream>
#include<cmath>
using namespace std;

void Pythagorean_Triplet(int &a, int &b, int &c);
void Product(int &a, int &b, int &c);

int main()
{
	int a = 0, b = 5, c = 10;

	Pythagorean_Triplet(a, b, c);
}

void Pythagorean_Triplet(int &a, int &b, int &c)
{
	/*Find the values of a, b, c such that a < b < c and
	a^2 + b^2 = c^2 && a + b + c = 1000*/
	
	int test1, test2, test3;
	
	for (a = 0; a < 1000 && a < b; a++)
	{
		for (b = 1; b < 1000 && b < c; b++)
		{
			c = 1000 - a - b;
			
			test1 = a;
			test2 = b;
			test3 = c;
				
			if (pow(a, 2) + pow(b, 2) == pow(c, 2) && (a + b + c == 1000) && (a < b) && (b < c))
			{
				Product(a, b, c);
			}
			
		}
	}
}

void Product(int &a, int &b, int &c)
{
	/*Find the product of a, b, c*/
	
	int product;

	product = a * b * c;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;
}
