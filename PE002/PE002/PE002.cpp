#include<iostream>
using namespace std;

void Fibonacci(long int &f1, long int &f2, long int &fnext);
bool Is_Even(long int fnext);

int main(void)
{
	long int upperlimit = 4000000;
	long int fibonacci = 0;
	long int f1 = 1, f2 = 2, fnext = 3;
	long int sum = 0;

	while (fibonacci < upperlimit)
	{
		/* fibonacci is increased until fibonacci
		equals the upperlimit.
		fibonacci is checked to see if it's even*/

		Fibonacci(f1, f2, fnext);
		fibonacci = fnext;
		if (Is_Even(fibonacci) == true)
		{
			sum += fibonacci;
		}
	}

	cout << sum + 2 << endl;

	system("pause");
}

void Fibonacci(long int &f1, long int &f2, long int &fnext)
{
	/*A fibonacci # generator*/
	f1 = f2;
	f2 = fnext;
	fnext = f1 + f2;
}

bool Is_Even(long int fnext)
{
	/*check the value of even*/

	int flag = 0;

	if (fnext % 2 == 0)
	{
		flag = 1;
	}

	return flag;
}