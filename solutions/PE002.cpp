#include<iostream>
using namespace std;

void Fibonacci(long int &f1, long int &f2, long int &fnext);
bool Is_Even(long int fnext);
void Sum(long int &sum, long int &fibonacci);

int main(void)
{
	long int upperlimit = 4000000;
	long int fibonacci = 0;
	long int f1 = 1, f2 = 2, fnext = 3;
	long int sum = 0;

	while (fibonacci < upperlimit)
	{
		Fibonacci(f1, f2, fnext);
		fibonacci = fnext;
		if (Is_Even(fibonacci) == true)
		{
			Sum(sum, fibonacci);
		}
	}

	cout << sum + 2 << endl;

	system("pause");
}

void Fibonacci(long int &f1, long int &f2, long int &fnext)
{
	f1 = f2;
	f2 = fnext;
	fnext = f1 + f2;
}

bool Is_Even(long int fnext)
{
	int flag = 0;

	if (fnext % 2 == 0)
	{
		flag = 1;
	}

	return flag;
}

void Sum(long int &sum, long int &fibonacci)
{
	sum += fibonacci;
}