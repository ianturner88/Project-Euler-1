#include<iostream>
#include<cmath>
using namespace std;

int main (void)
{
	int big = 4, little;
	int long long sum = 5;
	int upperlimit = 2000000;
	int sqrlimit;
	int flag;
	
	while (big < upperlimit)
	{
		little = 2;
		flag = 1;
		big++;
		sqrlimit = pow(big, .5);
	
		while (little < sqrlimit + 1)
		{
			if (big % little == 0)
			{
				flag = 0;
			}
		
			little++;
	}
	
		if (flag == 1)
		{
			sum += big;
		}
	}
	cout << sum;
}
