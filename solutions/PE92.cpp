#include <iostream>
#include <cmath>
using namespace std;

int main (void)
{
	long long int n = 0;
	long long int count89 = 0;
	long long int count1 = 0;
	long long int r;
	long long int sum;
	long long int dummynumber;
	
	while (n < pow(10,7))
	{
		n++;
		
		dummynumber = n;
		
		sum = 0;
		
		while (dummynumber != 89 && dummynumber != 1)
		{
			while (dummynumber > 0)
			{
				r = dummynumber % 10;
				dummynumber = dummynumber / 10;
				sum += pow(r, 2);	
			}
			
			dummynumber = sum;
			//sum = 0;
		}
		
		if (dummynumber == 89)
		{
			count89++;
		}
		
		else
		{
			count1++;	
		}
	}
	
	cout << count89 << endl;
	cout << count1;
}
