#include <iostream>
#include <cmath>
using namespace std;

int main (void)
{
	int n = 0;
	int count89 = 0;
	int count1 = 0;
	int r;
	int sum;
	int dummynumber;
	
	while (n < 10000000)
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
			sum = 0;
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
