#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	long long int F1 = 1, F2 = 1, Fnext;
	long int flag = 0;
	int a = 999;
	
	while (flag != 1)
	{
		Fnext = F1 + F2;
		F1 = F2 + Fnext;
		F2 = Fnext + F1;
		
		if (Fnext > pow(10,a))
		{
			flag = 1;
		}
		
		if (F1 > pow(10,a))
		{
			flag = 1;
		}
		
		if (F2 > pow(10,a))
		{
			flag = 1;
		}
	}
	
	cout << F1 << " " << F2 << " " << Fnext;
}
